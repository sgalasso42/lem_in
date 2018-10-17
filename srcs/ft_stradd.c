/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfernand <tfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 11:05:20 by tfernand          #+#    #+#             */
/*   Updated: 2018/07/07 18:29:24 by tfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_stradd(char **dst, char **src)
{
	char	*tmp;

	if (*dst == NULL)
		*dst = ft_strdup("");
	tmp = ft_strjoin(*dst, *src);
	free(*dst);
	*dst = NULL;
	if (tmp == NULL)
		return (0);
	*dst = tmp;
	tmp = ft_strjoin(*dst, "\n");
	free(*dst);
	*dst = NULL;
	if (tmp == NULL)
		return (0);
	*dst = tmp;
	return (1);
}
