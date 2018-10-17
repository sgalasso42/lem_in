/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 20:14:17 by tfernand          #+#    #+#             */
/*   Updated: 2018/07/12 13:42:20 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_parse_ants(char **line, char **map_text, t_map *map)
{
	while (get_next_line(0, line) > 0)
	{
		if (!(ft_stradd(map_text, line)))
			return (0);
		if ((*line)[0] == '#')
		{
			if (ft_strequ(*line, "##start") || ft_strequ(*line, "##end"))
			{
				return (0);
			}
		}
		else if (ft_atoi(*line) > 0 && ft_isnumber(*line)
				&& (map->ants = ft_atoi(*line)))
			break ;
		else
			return (0);
		free(*line);
		*line = NULL;
	}
	free(*line);
	*line = NULL;
	return (1);
}

static int		ft_parse_tunnels(char **line, char **map_text, t_map *map)
{
	int		ret;

	ret = 1;
	if (*line == NULL)
		ret = get_next_line(0, line);
	while (ret > 0)
	{
		if (!(ft_stradd(map_text, line)))
			return (0);
		if (*line[0] == '#')
		{
			if (ft_strequ(*line, "##start") && ft_strequ(*line, "##end"))
				return (0);
		}
		else if (ft_is_tunnel(*line))
		{
			if (!(ft_stock_next_rooms(*line, map)))
				return (0);
		}
		else
			return (0);
		free(*line);
		ret = get_next_line(0, line);
	}
	return (1);
}

int				ft_parse_input(t_map *map)
{
	char	*line;
	char	*map_text;

	line = NULL;
	map_text = ft_strdup("");
	if (!(map->rooms = (t_room **)(malloc(sizeof(t_room *)))))
		return (0);
	map->rooms[0] = NULL;
	if (ft_parse_ants(&line, &map_text, map))
	{
		if (ft_parse_rooms(&line, &map_text, map))
		{
			if (ft_parse_tunnels(&line, &map_text, map))
			{
				ft_putstr(map_text);
				free(map_text);
				free(line);
				return (1);
			}
		}
	}
	free(line);
	free(map_text);
	return (0);
}
