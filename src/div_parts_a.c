/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_parts_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:24:28 by loram             #+#    #+#             */
/*   Updated: 2020/07/25 23:24:30 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		div_parts_a(t_mstack **s, t_meta *m, unsigned first)
{
	s[0]->first = first;
	s[0]->quantity = m->min - first;
	s[0]->pos = 11;
	if (s[0]->quantity == ft_lstsize(m->b))
		s[0]->pos = 10;
	if (ft_mstack_pop(s, m->min, m->mid, 10) < 0)
		ft_exit(ERR_MEMALLOC, m);
	if (ft_mstack_pop(s, m->mid, m->max, 1) < 0)
		ft_exit(ERR_MEMALLOC, m);
	if (s[0]->quantity == ft_lstsize(m->a))
		s[0]->pos = 0;
}
