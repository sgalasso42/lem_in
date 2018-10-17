/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_next_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:54:45 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/12 17:21:21 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_stock_next_in(char *line, t_map *map, int *index_in)
{
	char	*in;
	int		i;

	*index_in = 0;
	i = 0;
	while (line[i] != '-')
		i++;
	in = ft_strsub(line, 0, i);
	if (in == NULL)
		return (0);
	while (map->rooms[*index_in] &&
	!ft_strequ(map->rooms[*index_in]->name, in))
		(*index_in) += 1;
	free(in);
	if (map->rooms[*index_in] == 0)
		return (0);
	if (!(map->rooms[*index_in]->next_rooms =
	ft_tab_add(map->rooms[*index_in]->next_rooms)))
		return (0);
	return (1);
}
