/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:04:00 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/12 17:38:02 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_is_room_doublon(t_map *map, char *name)
{
	int		i;

	i = 0;
	while (map->rooms[i])
	{
		if (ft_strequ(map->rooms[i]->name, name))
		{
			free(name);
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_stock_room(char *line, int index, t_map *map, int flag)
{
	char	*name;
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	if (!(name = ft_strsub(line, 0, i)) || (ft_is_room_doublon(map, name)))
		return (0);
	if (!(map->rooms = ft_tab_add(map->rooms)))
		return (0);
	if (!(map->rooms[index] = (t_room *)(malloc(sizeof(t_room)))))
		return (0);
	if (!(map->rooms[index]->next_rooms = (struct s_room **)
	(malloc(sizeof(struct s_room *)))))
		return (0);
	map->rooms[index]->next_rooms[0] = 0;
	if ((map->rooms[index]->name = ft_strdup(name)) == NULL)
		return (0);
	free(name);
	map->rooms[index]->flag = flag;
	map->rooms[index]->power = -1;
	map->rooms[index]->ant = 0;
	map->rooms[index]->moved = 0;
	return (1);
}
