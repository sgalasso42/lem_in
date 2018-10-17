/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:55:43 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/12 17:16:12 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_all(t_map *map)
{
	int i;

	i = 0;
	if (map == NULL || map->rooms == NULL)
		return ;
	while (map->rooms[i])
	{
		if (map->rooms[i]->next_rooms != NULL)
			free(map->rooms[i]->next_rooms);
		if (map->rooms[i]->name != NULL)
			free(map->rooms[i]->name);
		free(map->rooms[i]);
		i++;
	}
	free(map->rooms);
}
