/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort_four_a_one.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:32:51 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 01:32:52 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		mini_sorting_four_a_one(t_meta *m, int comb)
{
	if (comb == 1243 || comb == 1342)
	{
		ra(&m->a, m);
		ra(&m->a, m);
		sa(&m->a, m);
		rra(&m->a, m);
		if (comb == 1342)
			sa(&m->a, m);
		rra(&m->a, m);
	}
	else if (comb == 1423 || comb == 1432)
	{
		ra(&m->a, m);
		sa(&m->a, m);
		ra(&m->a, m);
		sa(&m->a, m);
		rra(&m->a, m);
		if (comb == 1432)
			sa(&m->a, m);
		rra(&m->a, m);
	}
}

static void		mini_sorting_four_a_two(t_meta *m, int comb)
{
	if (comb == 1324 || comb == 2314)
	{
		ra(&m->a, m);
		sa(&m->a, m);
		rra(&m->a, m);
		if (comb == 2314)
			sa(&m->a, m);
	}
	else if (comb == 2134 || comb == 3124 || comb == 3214)
	{
		sa(&m->a, m);
		if (comb == 3124 || comb == 3214)
		{
			ra(&m->a, m);
			sa(&m->a, m);
			rra(&m->a, m);
			if (comb == 3214)
				sa(&m->a, m);
		}
	}
}

static void		mini_sorting_four_a_three(t_meta *m, int comb)
{
	if (comb == 2143 || comb == 3142 || comb == 3241)
	{
		pb(&m->a, &m->b, m);
		pb(&m->a, &m->b, m);
		ss(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		if (comb == 3142 || comb == 3241)
			sa(&m->a, m);
		pa(&m->a, &m->b, m);
		if (comb == 3241)
			sa(&m->a, m);
	}
	else if (comb == 2341 || comb == 2431)
	{
		ra(&m->a, m);
		if (comb == 2431)
			sa(&m->a, m);
		ra(&m->a, m);
		sa(&m->a, m);
		pb(&m->a, &m->b, m);
		rra(&m->a, m);
		rra(&m->a, m);
		pa(&m->a, &m->b, m);
	}
}

void			ft_mini_sort_four_a_one(t_meta *m, int comb)
{
	if (comb == 1243 || comb == 1342 || comb == 1423 || comb == 1432)
		mini_sorting_four_a_one(m, comb);
	else if (comb == 1324 || comb == 2314 || comb == 2134 || comb == 3124
						|| comb == 3214)
		mini_sorting_four_a_two(m, comb);
	else if (comb == 2143 || comb == 3142 || comb == 3241 || comb == 2341
						|| comb == 2431)
		mini_sorting_four_a_three(m, comb);
	else
		ft_mini_sort_four_a_two(m, comb);
}
