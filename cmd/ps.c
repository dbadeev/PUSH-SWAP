/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:14:38 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 19:14:41 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_stack **a, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("sa");
	ft_lstswp(a);
	m->size++;
	if (m->flags.v != 0)
		print_status("sa", &m->a, &m->b, m->flags);
	return (1);
}

int		sb(t_stack **b, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("sb");
	ft_lstswp(b);
	m->size++;
	if (m->flags.v != 0)
		print_status("sb", &m->a, &m->b, m->flags);
	return (1);
}

int		ss(t_stack **a, t_stack **b, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("ss");
	ft_lstswp(a);
	ft_lstswp(b);
	m->size++;
	if (m->flags.v != 0)
		print_status("ss", &m->a, &m->b, m->flags);
	return (1);
}

int		pa(t_stack **a, t_stack **b, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("pa");
	ft_lstpush(a, b);
	m->size++;
	if (m->flags.v != 0)
		print_status("pa", &m->a, &m->b, m->flags);
	return (1);
}

int		pb(t_stack **a, t_stack **b, t_meta *m)
{
	if ((m->flags.v == 0) && (m->program == 'p'))
		ft_putendl("pb");
	ft_lstpush(b, a);
	m->size++;
	if (m->flags.v != 0)
		print_status("pb", &m->a, &m->b, m->flags);
	return (1);
}
