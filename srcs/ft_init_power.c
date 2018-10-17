/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:33:57 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/07 19:35:42 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_power_display(t_room *room, t_room *last, int power, int i)
{
	if (room->power < power)
		room->power = power;
	while (room->next_rooms[i])
	{
		if (last == 0 || !ft_strequ(room->next_rooms[i]->name, last->name))
		{
			if (room->next_rooms[i]->flag & STRT)
			{
				room->next_rooms[i]->power = 0;
				power = 0;
			}
			if (power <= 0)
				return (0);
			ft_power_display(room->next_rooms[i], room, power - 1, 0);
		}
		i++;
	}
	return (0);
}

int		ft_init_power(t_map *map)
{
	int		power;
	int		end;
	int		start;

	start = 0;
	power = 0;
	end = 0;
	while (map->rooms[power])
		power++;
	while ((map->rooms[end]->flag & END) == 0)
		end++;
	ft_power_display(map->rooms[end], 0, power, 0);
	while ((map->rooms[start]->flag & STRT) == 0)
		start++;
	if (map->rooms[start]->power == -1)
		return (0);
	return (1);
}
