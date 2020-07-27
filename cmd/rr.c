/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:09:38 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 19:09:48 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("ra");
	ft_lst_rr(a);
	m->size++;
	if (m->flags.v != 0)
		print_status("ra", &m->a, &m->b, m->flags);
}

void	rb(t_stack **b, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("rb");
	ft_lst_rr(b);
	m->size++;
	if (m->flags.v != 0)
		print_status("rb", &m->a, &m->b, m->flags);
}

void	rr(t_stack **a, t_stack **b, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("rr");
	ft_lst_rr(a);
	ft_lst_rr(b);
	m->size++;
	if (m->flags.v != 0)
		print_status("rr", &m->a, &m->b, m->flags);
}
