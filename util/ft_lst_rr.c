/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 00:40:08 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 00:40:12 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_lst_rr(t_stack **stack)
{
	t_stack		*temp;
	t_stack		*last;

	if (*stack && (*stack)->next)
	{
		last = (*stack);
		temp = (*stack)->next;
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = last;
		last->next = NULL;
		(*stack) = temp;
	}
}
