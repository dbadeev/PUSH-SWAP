/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 00:40:24 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 00:40:25 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_lst_rrr(t_stack **stack)
{
	t_stack		*temp;
	t_stack		*first;

	if (*stack && (*stack)->next)
	{
		temp = (*stack);
		while (*stack && (*stack)->next && (*stack)->next->next)
			(*stack) = (*stack)->next;
		first = (*stack)->next;
		(*stack)->next = NULL;
		first->next = temp;
		(*stack) = first;
	}
}
