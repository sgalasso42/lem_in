/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:47:04 by tfernand          #+#    #+#             */
/*   Updated: 2018/07/07 21:37:45 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_parse_start_end(char *line, int *flag, int *edge_found)
{
	int		tmp;

	tmp = 0;
	if (ft_strequ(line, "##start"))
	{
		tmp |= 1;
	}
	else if (ft_strequ(line, "##end"))
	{
		tmp |= 2;
	}
	else
		return (1);
	if ((*edge_found & tmp) > 0)
		return (0);
	*flag |= tmp;
	*edge_found |= *flag;
	return (1);
}

static int	ft_handle_line(char **line, int *flag, int *edge_found, t_map *map)
{
	static int	index = 0;

	if (*line[0] == '#')
	{
		if (!(ft_parse_start_end(*line, flag, edge_found)))
		{
			free(*line);
			return (0);
		}
	}
	else if (ft_is_room(*line))
	{
		if (!(ft_stock_room(*line, index++, map, *flag)))
			return (0);
		*flag = 0;
	}
	else
		return (2);
	return (1);
}

int			ft_parse_rooms(char **line, char **map_text, t_map *map)
{
	int		flag;
	int		edge_found;
	int		ret;

	edge_found = 0;
	flag = 0;
	ret = 1;
	if (*line == NULL)
		ret = get_next_line(0, line);
	while (ret > 0)
	{
		if (!(ft_stradd(map_text, line)))
			return (0);
		ret = ft_handle_line(line, &flag, &edge_found, map);
		if (ret == 0)
			return (0);
		if (ret == 2)
			break ;
		free(*line);
		*line = NULL;
		ret = get_next_line(0, line);
	}
	if (edge_found != 3)
		return (0);
	return (1);
}
