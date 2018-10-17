/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:53:18 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/12 17:43:48 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

/*
** Flag
** 1 -> start room
** 2 -> end room
*/
# define STRT 1
# define END 2

typedef struct		s_room
{
	char			*name;
	char			flag;
	int				power;
	int				ant;
	int				moved;
	struct s_room	**next_rooms;
}					t_room;

typedef struct		s_map
{
	int				ants_on_start;
	int				ants_on_end;
	int				ants;
	t_room			**rooms;
}					t_map;

void				ft_init_parse_struct(t_map *map);
int					ft_is_room(char *line);
int					ft_is_tunnel(char *line);
t_room				**ft_tab_add(t_room **rooms);
int					ft_stock_next_in(char *line, t_map *map, int *index_in);
int					ft_stock_next_out(char *line, t_map *map, int *index_out);
int					ft_stock_room(char *line, int index, t_map *map, int flag);
int					ft_stock_next_rooms(char *line, t_map *map);

int					ft_isnumber(char *str);
int					ft_stradd(char **dst, char **src);
int					ft_parse_rooms(char **line, char **map_text, t_map *map);
int					ft_parse_input(t_map *map);
int					ft_init_power(t_map *map);
void				ft_handle_ants(t_map *map);
void				ft_free_all(t_map *map);

#endif
