/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_tunnel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:47:01 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/12 16:17:22 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_is_tunnel(char *line)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (ft_nbwords(line, '-') != 2)
		return (0);
	if (line[i] == 'L')
		return (0);
	while (line[i])
	{
		if (line[i] == ' ')
			return (0);
		if (line[i] == '-')
		{
			if (line[i + 1] == 'L')
				return (0);
			c++;
		}
		i++;
	}
	return ((c != 1) ? 0 : 1);
}
