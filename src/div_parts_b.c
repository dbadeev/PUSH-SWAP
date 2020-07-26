/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_parts_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:24:43 by loram             #+#    #+#             */
/*   Updated: 2020/07/25 23:24:45 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		div_parts_b(t_mstack **s, t_meta *m, unsigned first)
{
	s[0]->first = first;
	s[0]->quantity = m->min - first;
	s[0]->pos = 11;
	if (ft_mstack_pop(s, m->min, m->mid, 1) < 0)
		ft_exit(m);
	if (ft_mstack_pop(s, m->mid, m->max, 0) < 0)
		ft_exit(m);
}
