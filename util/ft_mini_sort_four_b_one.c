/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort_four_b_one.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:36:18 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 01:36:19 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		mini_sorting_four_b_four(t_meta *m, unsigned comb)
{
	if (comb == 2413 || comb == 2431)
	{
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		if (comb == 2431)
			sa(&m->a, m);
		else
			ss(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		sa(&m->a, m);
		pa(&m->a, &m->b, m);
	}
	else if (comb == 3124)
	{
		pa(&m->a, &m->b, m);
		rb(&m->b, m);
		pa(&m->a, &m->b, m);
		ra(&m->a, m);
		pa(&m->a, &m->b, m);
		sa(&m->a, m);
		rrr(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
}

static void		mini_sorting_four_b_three(t_meta *m, unsigned comb)
{
	if (comb == 2134 || comb == 2143)
	{
		pa(&m->a, &m->b, m);
		rr(&m->a, &m->b, m);
		if (comb == 2134)
			sb(&m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		rrr(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
	else if (comb == 2314 || comb == 3214)
	{
		pa(&m->a, &m->b, m);
		if (comb == 2314)
			ra(&m->a, m);
		pa(&m->a, &m->b, m);
		(comb == 2314) ? rb(&m->b, m) : rr(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		sa(&m->a, m);
		rrr(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
}

static void		mini_sorting_four_b_two(t_meta *m, unsigned comb)
{
	if (comb == 1342 || comb == 2341)
	{
		sb(&m->b, m);
		pa(&m->a, &m->b, m);
		sb(&m->b, m);
		pa(&m->a, &m->b, m);
		(comb == 2341) ? sa(&m->a, m) : ss(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
	else if (comb == 1423 || comb == 1432)
	{
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		if (comb == 1423)
			ss(&m->a, &m->b, m);
		else
			sa(&m->a, m);
		pa(&m->a, &m->b, m);
		sa(&m->a, m);
		pa(&m->a, &m->b, m);
		sa(&m->a, m);
	}
}

static void		mini_sorting_four_b_one(t_meta *m, unsigned comb)
{
	if (comb == 1234 || comb == 1243)
	{
		sb(&m->b, m);
		pa(&m->a, &m->b, m);
		rr(&m->a, &m->b, m);
		if (comb == 1234)
			sb(&m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		rrr(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
	else if (comb == 1324)
	{
		pa(&m->a, &m->b, m);
		ra(&m->a, m);
		pa(&m->a, &m->b, m);
		sb(&m->b, m);
		pa(&m->a, &m->b, m);
		sa(&m->a, m);
		pa(&m->a, &m->b, m);
		rra(&m->a, m);
	}
}

void			ft_mini_sort_four_b_one(t_meta *m, unsigned comb)
{
	if (comb == 1234 || comb == 1243 || comb == 1324)
		mini_sorting_four_b_one(m, comb);
	else if (comb == 1342 || comb == 2341 || comb == 1423 || comb == 1432)
		mini_sorting_four_b_two(m, comb);
	else if (comb == 2134 || comb == 2143 || comb == 2314 || comb == 3214)
		mini_sorting_four_b_three(m, comb);
	else if (comb == 2413 || comb == 2431 || comb == 3124)
		mini_sorting_four_b_four(m, comb);
	else
		ft_mini_sort_four_b_two(m, comb);
}
