/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:00:49 by sgalasso          #+#    #+#             */
/*   Updated: 2018/07/07 18:48:11 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_map		map;

	if (ft_parse_input(&map))
	{
		if (ft_init_power(&map))
		{
			ft_putchar('\n');
			ft_handle_ants(&map);
			ft_free_all(&map);
			return (0);
		}
	}
	ft_free_all(&map);
	ft_putendl("ERROR");
	return (EXIT_FAILURE);
}
