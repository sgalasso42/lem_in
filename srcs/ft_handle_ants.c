/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:05:23 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/07 19:36:22 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_find_best_way(t_room *room)
{
	int		i;
	int		temp;

	i = 0;
	temp = -1;
	while (room->next_rooms[i])
	{
		if (room->next_rooms[i]->ant == 0)
		{
			if (temp == -1 || room->next_rooms[i]->power >
			room->next_rooms[temp]->power)
				temp = i;
		}
		i++;
	}
	if (temp == -1)
		return (0);
	return (room->next_rooms[temp]);
}

void	ft_new_turn(t_map *map)
{
	int i;

	i = 0;
	while (map->rooms[i])
	{
		map->rooms[i]->moved = 0;
		i++;
	}
}

void	ft_move_ant(t_map *map, t_room *current, t_room *next, int num_ant)
{
	if ((next->flag & END) == END)
	{
		current->moved = 0;
		current->ant = 0;
		map->ants_on_end++;
	}
	else
	{
		next->ant = num_ant;
		next->moved = 1;
		current->ant = 0;
		current->moved = 0;
	}
	ft_putchar('L');
	ft_putnbr(num_ant);
	ft_putchar('-');
	ft_putstr(next->name);
	ft_putchar(' ');
}

int		ft_ants_choices(t_map *map, t_room *next_way, int num_ant, int i)
{
	int		j;

	if ((map->rooms[i]->flag & STRT) == STRT && map->rooms[i]->ant == 0)
	{
		j = 0;
		while (map->ants_on_start > 0 && map->rooms[i]->next_rooms[j])
		{
			if (map->rooms[i]->next_rooms[j]->ant == 0)
			{
				ft_move_ant(map, map->rooms[i],
				map->rooms[i]->next_rooms[j], ++num_ant);
				map->ants_on_start--;
			}
			j++;
		}
	}
	else if (map->rooms[i]->moved == 0 && map->rooms[i]->ant != 0)
	{
		if ((next_way = ft_find_best_way(map->rooms[i])))
			ft_move_ant(map, map->rooms[i], next_way, map->rooms[i]->ant);
	}
	return (num_ant);
}

void	ft_handle_ants(t_map *map)
{
	t_room	*next_way;
	int		num_ant;
	int		i;

	next_way = 0;
	map->ants_on_start = map->ants;
	map->ants_on_end = 0;
	num_ant = 0;
	while (map->ants_on_end < map->ants)
	{
		i = 0;
		while (map->rooms[i])
		{
			num_ant = ft_ants_choices(map, next_way, num_ant, i);
			i++;
		}
		ft_putchar('\n');
		ft_new_turn(map);
	}
}
