/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:10:42 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 19:11:26 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rra(t_stack **a, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("rra");
	ft_lst_rrr(a);
	m->size++;
	if (m->flags.v != 0)
		print_status("rra", &m->a, &m->b, m->flags);
	return (1);
}

int		rrb(t_stack **b, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("rrb");
	ft_lst_rrr(b);
	m->size++;
	if (m->flags.v != 0)
		print_status("rrb", &m->a, &m->b, m->flags);
	return (1);
}

int		rrr(t_stack **a, t_stack **b, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("rrr");
	ft_lst_rrr(a);
	ft_lst_rrr(b);
	m->size++;
	if (m->flags.v != 0)
		print_status("rrr", &m->a, &m->b, m->flags);
	return (1);
}
