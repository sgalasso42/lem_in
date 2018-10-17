/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_next_out.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:55:50 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/12 17:21:33 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_stock_next_out(char *line, t_map *map, int *index_out)
{
	char	*out;
	int		i;

	*index_out = 0;
	i = 0;
	while (line[i] != '-')
		i++;
	out = ft_strsub(line, i + 1, ft_strlen(line));
	if (out == NULL)
		return (0);
	while (map->rooms[*index_out] &&
	!ft_strequ(map->rooms[*index_out]->name, out))
		(*index_out) += 1;
	free(out);
	if (map->rooms[*index_out] == 0)
		return (0);
	if (!(map->rooms[*index_out]->next_rooms =
	ft_tab_add(map->rooms[*index_out]->next_rooms)))
		return (0);
	return (1);
}
