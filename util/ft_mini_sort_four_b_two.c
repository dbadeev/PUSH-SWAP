/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort_four_b_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:37:24 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 01:37:26 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		mini_sorting_four_b_seven(t_meta *m, int comb)
{
	if (comb == 4231 || comb == 4312 || comb == 4321)
	{
		pa(&m->a, &m->b, m);
		if (comb == 4231)
			sb(&m->b, m);
		pa(&m->a, &m->b, m);
		if (comb == 4312)
			sb(&m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
}

static void		mini_sorting_four_b_six(t_meta *m, int comb)
{
	if (comb == 4123 || comb == 4213)
	{
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		sb(&m->b, m);
		pa(&m->a, &m->b, m);
		sa(&m->a, m);
		pa(&m->a, &m->b, m);
		if (comb == 4123)
			sa(&m->a, m);
	}
	else if (comb == 4132)
	{
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		sa(&m->a, m);
		pa(&m->a, &m->b, m);
		sa(&m->a, m);
	}
}

static void		mini_sorting_four_b_five(t_meta *m, int comb)
{
	if (comb == 3142 || comb == 3241)
	{
		pa(&m->a, &m->b, m);
		sb(&m->b, m);
		pa(&m->a, &m->b, m);
		if (comb == 3241)
			sa(&m->a, m);
		else
			ss(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
	else if (comb == 3412 || comb == 3421)
	{
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		if (comb == 3421)
			sa(&m->a, m);
		else
			ss(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
}

void			ft_mini_sort_four_b_two(t_meta *m, int comb)
{
	if (comb == 3142 || comb == 3241 || comb == 3412 || comb == 3421)
		mini_sorting_four_b_five(m, comb);
	else if (comb == 4123 || comb == 4213 || comb == 4132)
		mini_sorting_four_b_six(m, comb);
	else if (comb == 4231 || comb == 4312 || comb == 4321)
		mini_sorting_four_b_seven(m, comb);
}
