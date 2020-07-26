/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort_three_ab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:38:47 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 01:38:49 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		mini_sorting_three_b_two(t_meta *m, unsigned comb)
{
	if (comb == 231 || comb == 321)
	{
		if (comb == 231)
			sb(&m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
}

static void		mini_sorting_three_b_one(t_meta *m, unsigned comb)
{
	if (comb == 123 || comb == 213)
	{
		pa(&m->a, &m->b, m);
		sb(&m->b, m);
		pa(&m->a, &m->b, m);
		sa(&m->a, m);
		pa(&m->a, &m->b, m);
		if (comb == 123)
			sa(&m->a, m);
	}
	else if (comb == 132 || comb == 312)
	{
		if (comb == 132)
			sb(&m->b, m);
		pa(&m->a, &m->b, m);
		sb(&m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
	else if (comb == 231 || comb == 321)
		mini_sorting_three_b_two(m, comb);
}

static void		mini_sorting_three_a(t_meta *m, unsigned comb)
{
	if (comb == 132 || comb == 312)
	{
		if (comb == 312)
			sa(&m->a, m);
		ra(&m->a, m);
		sa(&m->a, m);
		rra(&m->a, m);
	}
	else if (comb == 231 || comb == 321)
	{
		if (comb == 321)
			sa(&m->a, m);
		ra(&m->a, m);
		sa(&m->a, m);
		rra(&m->a, m);
		sa(&m->a, m);
	}
	else if (comb == 213)
		sa(&m->a, m);
}

static void		mini_sorting_three_only_a(t_meta *m, unsigned comb)
{
	if (comb == 132 || comb == 231)
	{
		rra(&m->a, m);
		if (comb == 132)
			sa(&m->a, m);
	}
	else if (comb == 213 || comb == 321)
	{
		sa(&m->a, m);
		if (comb == 321)
			rra(&m->a, m);
	}
	else if (comb == 312)
		ra(&m->a, m);
}

void			ft_mini_sort_three_ab(t_mstack **s, t_meta *m, unsigned comb)
{
	if (s[0]->pos == 10)
		mini_sorting_three_b_one(m, comb);
	else if ((s[0]->pos == 0) && (m->nums == 3))
		mini_sorting_three_only_a(m, comb);
	else if (s[0]->pos == 0)
		mini_sorting_three_a(m, comb);
	else if (s[0]->pos == 1 || s[0]->pos == 11)
		ft_putendl("1 OR 11 ON TOP mini_sorting_two!!!!!!!!!!!!!!!!!!!!!");
}
