/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstack_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:40:07 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 01:40:08 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pos
** 0 (00) - top A
** 1 (01) - ground A
** 10 - top B
** 11 - ground B
*/

#include "push_swap.h"

int		ft_mstack_pop(t_mstack **s, int first, int last, int pos)
{
	t_mstack	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_mstack))))
	{
		ft_del_mstack(s);
		return (-1);
	}
	else
	{
		tmp->quantity = last - first;
		tmp->first = first;
		tmp->pos = pos;
		tmp->next = NULL;
	}
	if (*s)
	{
		tmp->next = (*s);
		(*s) = tmp;
	}
	else
		(*s) = tmp;
	return (0);
}
