/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:50:27 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/10 15:51:24 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	**ft_tab_add(t_room **rooms)
{
	t_room	**new;
	int		i;

	i = 0;
	while (rooms[i])
		i++;
	if (!(new = (t_room **)(malloc(sizeof(t_room *) * (i + 1 + 1)))))
		return (0);
	i = 0;
	while (rooms[i])
	{
		new[i] = rooms[i];
		i++;
	}
	new[i] = 0;
	new[i + 1] = 0;
	i = 0;
	free(rooms);
	return (new);
}
