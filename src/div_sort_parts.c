/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_sort_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:35:19 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 21:35:22 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			ft_check_alien(t_stack **s, int min, int max)
{
	int			i;
	int			j;
	t_stack		*tmp;

	i = 0;
	tmp = s[0];
	j = ft_lstsize(tmp);
	while ((i < j) && (tmp->label >= min) && (tmp->label < max))
	{
		tmp = tmp->next;
		i++;
	}
	if (i == j)
		return (0);
	else
		return (1);
}

static void			div_sort_b(t_stack **a, t_stack **b, t_meta *m, int nums)
{
	int			i;

	i = 0;
	while (i < nums)
	{
		if (b[0]->label >= m->min)
		{
			pa(a, b, m);
			if (a[0]->label < m->mid)
				ra(a, m);
		}
		else if ((b[0]->label < m->min)
							&& ft_check_alien(b, m->max - nums, m->min))
			rb(b, m);
		i++;
	}
}

static void			div_sort_a(t_stack **a, t_stack **b, t_meta *m, int nums)
{
	int			i;

	i = 0;
	while (i < nums)
	{
		if ((a[0]->label >= m->mid) && ft_check_alien(a, m->mid, m->max))
			ra(a, m);
		else if (a[0]->label < m->mid)
		{
			pb(a, b, m);
			if ((b[0]->label < m->min)
				&& ft_check_alien(b, m->max - nums, m->min))
				rb(b, m);
		}
		i++;
	}
}

static void			div_sort_ab(t_mstack *s, t_meta *m)
{
	if (s->pos == 0)
		div_sort_a(&m->a, &m->b, m, s->quantity);
	else if (s->pos == 10)
		div_sort_b(&m->a, &m->b, m, s->quantity);
	else
		ft_putendl("WRNING!!!!!!!!!!!!!!!!!!!!!");
}

void				div_sort_parts(t_mstack **s, t_meta *m)
{
	int			first;

	first = s[0]->first;
	m->min = s[0]->first + s[0]->quantity / 3;
	m->mid = m->min + (s[0]->first + s[0]->quantity - m->min) / 2;
	m->max = s[0]->first + s[0]->quantity;
	div_sort_ab(s[0], m);
	if (s[0]->pos == 0)
		div_parts_a(s, m, first);
	else if (s[0]->pos == 10)
		div_parts_b(s, m, first);
}
