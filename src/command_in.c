/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 01:36:54 by loram             #+#    #+#             */
/*   Updated: 2020/07/19 01:37:03 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		command_in(char *cmd, t_stack **a, t_stack **b, t_meta *m)
{
	if (ft_strequ(cmd, "sa"))
		sa(a, m);
	else if (ft_strequ(cmd, "sb"))
		sb(b, m);
	else if (ft_strequ(cmd, "ss"))
		ss(a, b, m);
	else if (ft_strequ(cmd, "pa"))
		pa(a, b, m);
	else if (ft_strequ(cmd, "pb"))
		pb(a, b, m);
	else if (ft_strequ(cmd, "ra"))
		ra(a, m);
	else if (ft_strequ(cmd, "rb"))
		rb(b, m);
	else if (ft_strequ(cmd, "rr"))
		rr(a, b, m);
	else if (ft_strequ(cmd, "rra"))
		rra(a, m);
	else if (ft_strequ(cmd, "rrb"))
		rrb(b, m);
	else if (ft_strequ(cmd, "rrr"))
		rrr(a, b, m);
	else
		return (1);
	return (0);
}
