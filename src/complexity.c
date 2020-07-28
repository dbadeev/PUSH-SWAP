/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:50:28 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 01:50:29 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			mini_sorting_complexity(t_mstack **s, t_meta *m, int level)
{
	if (s[0]->quantity == 1 && s[0]->pos == 10)
		m->complexity += 1.;
	else if (s[0]->quantity == 2 && s[0]->pos == 0)
		m->complexity += (level == 1) ? 1. : .5;
	else if (s[0]->quantity == 2 && s[0]->pos == 10)
		m->complexity += (level == 1) ? 3. : 2.5;
	else if (s[0]->quantity == 3 && s[0]->pos == 0)
		m->complexity += (level == 1) ? 5. : (17. / 6);
	else if (s[0]->quantity == 3 && s[0]->pos == 10)
		m->complexity += (level == 1) ? 6. : (27. / 6);
	else if (s[0]->quantity == 4 && s[0]->pos == 0)
		m->complexity += (level == 1) ? 9. : (144. / 24);
	else if (s[0]->quantity == 4 && s[0]->pos == 10)
		m->complexity += (level == 1) ? 8. : (154. / 24);
	if (s[0]->pos == 10)
	{
		m->a_nums += s[0]->quantity;
		m->b_nums -= s[0]->quantity;
	}
	ft_mstack_push(s);
}

static void		div_sort_parts_complexity(t_mstack **s, t_meta *m,
														unsigned first)
{
	first = s[0]->first;
	m->min = s[0]->first + s[0]->quantity / 3;
	m->mid = m->min + (s[0]->first + s[0]->quantity - m->min) / 2;
	m->max = s[0]->first + s[0]->quantity;
	if (s[0]->pos == 0)
	{
		m->a_nums -= s[0]->quantity - m->max + m->mid;
		m->b_nums += s[0]->quantity - m->max + m->mid;
		if (ft_mstack_pop(s, m->min, m->mid, 10) < 0)
			ft_exit(ERR_MEMALLOC, m);
		if (ft_mstack_pop(s, m->mid, m->max, 1) < 0)
			ft_exit(ERR_MEMALLOC, m);
	}
	else if (s[0]->pos == 10)
	{
		m->b_nums -= s[0]->quantity - m->min + first;
		m->a_nums += s[0]->quantity - m->min + first;
		if (ft_mstack_pop(s, m->min, m->mid, 1) < 0)
			ft_exit(ERR_MEMALLOC, m);
		if (ft_mstack_pop(s, m->mid, m->max, 0) < 0)
			ft_exit(ERR_MEMALLOC, m);
	}
	s[0]->next->next->quantity = m->min - first;
	s[0]->next->next->pos = 11;
	m->complexity += m->max - m->min + 2 * (m->min - first);
}

static void		move_up_part_complexity(t_mstack **s, t_meta *m)
{
	if (s[0]->pos == 1 && s[0]->next && s[0]->next->pos == 11
						&& s[0]->quantity >= s[0]->next->quantity)
	{
		s[0]->pos = 0;
		s[0]->next->pos = 10;
	}
	else if (s[0]->pos == 1)
		s[0]->pos = 0;
	else if (s[0]->pos == 11)
		s[0]->pos = 10;
	m->complexity += s[0]->quantity;
}

static int		complexity(t_meta *m, unsigned num, int level)
{
	t_mstack		*t;

	t = NULL;
	m->complexity = 0.;
	if (ft_mstack_pop(&t, 0, num, 0) < 0)
		ft_exit(ERR_MEMALLOC, m);
	m->a_nums = num;
	while (t)
	{
		if (t && (t->pos == 1 || t->pos == 11))
		{
			if ((t->pos == 1) && (t->quantity == m->a_nums))
				t->pos = 0;
			else if ((t->pos == 11) && (t->quantity == m->b_nums))
				t->pos = 10;
			else
				move_up_part_complexity(&t, m);
		}
		if (t->quantity > 4)
			div_sort_parts_complexity(&t, m, t->first);
		else
			mini_sorting_complexity(&t, m, level);
	}
	return ((int)m->complexity);
}

int				main2(int ac, char **av)
{
	t_meta			meta;
	int				nums;
	int				sup;

	sup = 0;
	if (ac != 2)
		ps_hint();
	else
	{
		init_ps(&meta);
		nums = ft_atoi_ps(av[1], &meta);
		if (nums >= 0)
		{
			sup = complexity(&meta, nums, 1);
			if (sup < 0 || complexity(&meta, nums, 0) < 0)
				ft_putstr("\033[31mError\033[0m\n");
			else
				ft_print_complexity(nums, sup, complexity(&meta, nums, 0));
		}
		else
			ft_exit(ERR_NAN, &meta);
	}
	return (0);
}
