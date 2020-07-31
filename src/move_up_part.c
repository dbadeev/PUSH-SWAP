/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:56:25 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 21:56:27 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			move_up_parts_ab(t_mstack **s, t_meta *m)
{
	int i;

	i = 0;
	while (i < s[0]->next->quantity)
	{
		rrr(&m->a, &m->b, m);
		i++;
	}
	if (s[0]->quantity > s[0]->next->quantity)
	{
		rra(&m->a, m);
	}
	s[0]->pos = 0;
	s[0]->next->pos = 10;
}

void				move_up_part(t_mstack **s, t_meta *m)
{
	int	i;

	if (s[0]->pos == 1 && s[0]->next && s[0]->next->pos == 11
									&& s[0]->quantity >= s[0]->next->quantity)
		move_up_parts_ab(s, m);
	else if (s[0]->pos == 1)
	{
		i = 0;
		while (i++ < s[0]->quantity)
			rra(&m->a, m);
		s[0]->pos = 0;
	}
	else if (s[0]->pos == 11)
	{
		if (!((s[0]->first <= m->b[0].label) &&
							(m->b[0].label < s[0]->first + s[0]->quantity)))
		{
			i = 0;
			while (i++ < s[0]->quantity)
				rrb(&m->b, m);
		}
		s[0]->pos = 10;
	}
}
