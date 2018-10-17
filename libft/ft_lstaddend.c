/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:18:51 by sgalasso          #+#    #+#             */
/*   Updated: 2018/05/25 18:28:21 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *first;

	if (alst && new)
	{
		first = *alst;
		while ((*alst)->next != 0)
			*alst = (*alst)->next;
		(*alst)->next = new;
		*alst = first;
	}
}
