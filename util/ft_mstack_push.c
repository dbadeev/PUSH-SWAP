/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mstack_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:46:35 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 01:46:36 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mstack_push(t_mstack **s)
{
	t_mstack *tmp;

	if (s == NULL)
		ft_exit(ERR_OPERATION, 0);
	else
	{
		tmp = (*s);
		(*s) = (*s)->next;
		tmp->quantity = 0;
		tmp->first = 0;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
	}
}
