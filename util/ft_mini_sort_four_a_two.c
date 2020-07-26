/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort_four_a_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:34:42 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 01:34:43 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		mini_sorting_four_a_four(t_meta *m, unsigned comb)
{
	if (comb == 3412 || comb == 3421)
	{
		ra(&m->a, m);
		sa(&m->a, m);
		pb(&m->a, &m->b, m);
		sa(&m->a, m);
		rra(&m->a, m);
		sa(&m->a, m);
		pa(&m->a, &m->b, m);
		if (comb == 3421)
			sa(&m->a, m);
	}
	else if (comb == 4123 || comb == 4132)
	{
		sa(&m->a, m);
		ra(&m->a, m);
		sa(&m->a, m);
		ra(&m->a, m);
		sa(&m->a, m);
		rra(&m->a, m);
		if (comb == 4132)
			sa(&m->a, m);
		rra(&m->a, m);
	}
}

static void		mini_sorting_four_a_five(t_meta *m, unsigned comb)
{
	if (comb == 4231 || comb == 4312 || comb == 4321)
	{
		ra(&m->a, m);
		if ((comb == 4231) && pb(&m->a, &m->b, m))
			ra(&m->a, m);
		else
		{
			ra(&m->a, m);
			pb(&m->a, &m->b, m);
		}
		pb(&m->a, &m->b, m);
		rra(&m->a, m);
		rra(&m->a, m);
		if (comb == 4312)
			sa(&m->a, m);
		else
			ss(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
}

static void		mini_sorting_four_a_six(t_meta *m, unsigned comb)
{
	if (comb == 2413)
	{
		ra(&m->a, m);
		sa(&m->a, m);
		pb(&m->a, &m->b, m);
		sa(&m->a, m);
		rra(&m->a, m);
		pa(&m->a, &m->b, m);
	}
	else if (comb == 4213)
	{
		ra(&m->a, m);
		pb(&m->a, &m->b, m);
		pb(&m->a, &m->b, m);
		rra(&m->a, m);
		ss(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
}

void			ft_mini_sort_four_a_two(t_meta *m, unsigned comb)
{
	if (comb == 3412 || comb == 3421 || comb == 4123 || comb == 4132)
		mini_sorting_four_a_four(m, comb);
	else if (comb == 4231 || comb == 4312 || comb == 4321)
		mini_sorting_four_a_five(m, comb);
	else if (comb == 2413 || comb == 4213)
		mini_sorting_four_a_six(m, comb);
}
