/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:53:01 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 21:53:03 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			mini_sorting_four(t_mstack **s, t_meta *m)
{
	unsigned	comb;

	if (s[0]->pos == 10)
	{
		comb = 1000 * (m->b->label - s[0]->first + 1) +
				100 * (m->b->next->label - s[0]->first + 1) +
				10 * (m->b->next->next->label - s[0]->first + 1) +
				(m->b->next->next->next->label - s[0]->first + 1);
		ft_mini_sort_four_b_one(m, comb);
	}
	else if (s[0]->pos == 0)
	{
		comb = 1000 * (m->a->label - s[0]->first + 1) +
				100 * (m->a->next->label - s[0]->first + 1) +
				10 * (m->a->next->next->label - s[0]->first + 1) +
				(m->a->next->next->next->label - s[0]->first + 1);
		ft_mini_sort_four_a_one(m, comb);
	}
	else if (s[0]->pos == 1 || s[0]->pos == 11)
		ft_putendl("1 OR 11 ON TOP mini_sorting_two!!!!!!!!!!!!!!!!!!!!!");
	ft_mstack_push(s);
	m->sorted += 4;
}

static void			mini_sorting_two(t_mstack **s, t_meta *m)
{
	t_mstack	*temp;

	temp = s[0];
	if ((s[0]->pos == 0) && (m->a->label > m->a->next->label))
	{
		while (temp->next && temp->pos != 10)
			temp = temp->next;
		if ((temp->pos == 10) && (temp->quantity > 1)
			&& (m->b->label < m->b->next->label))
			ss(&m->a, &m->b, m);
		else
			sa(&m->a, m);
	}
	else if (s[0]->pos == 10)
	{
		if (m->b->label < m->b->next->label)
			sb(&m->b, m);
		pa(&m->a, &m->b, m);
		pa(&m->a, &m->b, m);
	}
	ft_mstack_push(s);
	m->sorted += 2;
}

static void			mini_sorted_plus_one(t_mstack **s, t_meta *m)
{
	if (s[0]->pos == 10)
		pa(&m->a, &m->b, m);
	else if (s[0]->pos == 1 || s[0]->pos == 11)
		ft_putendl("1 OR 11 ON TOP in mini_sorted_plus_one!!!!!!!!!!!!!!!");
	ft_mstack_push(s);
	m->sorted += 1;
}

static void			mini_sorting_three(t_mstack **s, t_meta *m)
{
	unsigned	comb;

	comb = 0;
	if (s[0]->pos == 10)
	{
		comb = 100 * (m->b->label - s[0]->first + 1) +
				10 * (m->b->next->label - s[0]->first + 1) +
				(m->b->next->next->label - s[0]->first + 1);
	}
	else if (s[0]->pos == 0)
	{
		comb = 100 * (m->a->label - s[0]->first + 1) +
				10 * (m->a->next->label - s[0]->first + 1) +
				(m->a->next->next->label - s[0]->first + 1);
	}
	else if (s[0]->pos == 1 || s[0]->pos == 11)
		ft_putendl("1 OR 11 ON TOP mini_sorting_two!!!!!!!!!!!!!!!!!!!!!");
	ft_mini_sort_three_ab(s, m, comb);
	ft_mstack_push(s);
	m->sorted += 3;
}

void				mini_sorting(t_mstack **s, t_meta *m)
{
	if (s[0]->quantity == 1)
		mini_sorted_plus_one(s, m);
	else if (s[0]->quantity == 2)
		mini_sorting_two(s, m);
	else if (s[0]->quantity == 3)
		mini_sorting_three(s, m);
	else if (s[0]->quantity == 4)
		mini_sorting_four(s, m);
}
