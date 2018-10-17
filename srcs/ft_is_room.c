/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:45:27 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/07 18:20:48 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_is_room(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	if (line[i] == 'L' || line[i] == ' ')
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	if (line[i++] == '\0')
		return (0);
	if (!ft_isdigit(line[i]))
		return (0);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i++] != ' ')
		return (0);
	if (!ft_isdigit(line[i]))
		return (0);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	return ((line[i] != '\0') ? 0 : 1);
}
