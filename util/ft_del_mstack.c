/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_mstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:43:15 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 22:43:16 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_del_mstack(t_mstack **s)
{
	t_mstack	*prev;

	while ((*s)->next)
	{
		prev = (*s);
		(*s) = (*s)->next;
		prev->next = NULL;
		prev->pos = 0;
		prev->first = 0;
		prev->quantity = 0;
		free(prev);
		prev = NULL;
	}
	(*s)->first = 0;
	(*s)->quantity = 0;
	(*s)->pos = 0;
	free(*s);
	*s = NULL;
}
