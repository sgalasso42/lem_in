/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_next_rooms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:05:12 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/07 20:08:50 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_stock_next_rooms(char *line, t_map *map)
{
	int		i;
	int		index_in;
	int		index_out;

	i = 0;
	if (!(ft_stock_next_in(line, map, &index_in))
		|| !(ft_stock_next_out(line, map, &index_out)))
		return (0);
	if (ft_strequ(map->rooms[index_in]->name, map->rooms[index_out]->name))
		return (0);
	if (map->rooms[index_in] == 0 || map->rooms[index_out] == 0)
		return (0);
	i = 0;
	while (map->rooms[index_in]->next_rooms[i])
		i++;
	map->rooms[index_in]->next_rooms[i] = map->rooms[index_out];
	i = 0;
	while (map->rooms[index_out]->next_rooms[i])
		i++;
	map->rooms[index_out]->next_rooms[i] = map->rooms[index_in];
	return (1);
}
