/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:54:45 by loram             #+#    #+#             */
/*   Updated: 2020/07/15 01:54:46 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			print_total(int ap)
{
	ft_putstr("Total actions: ");
	ft_putnbr(ap);
	ft_putchar('\n');
}

static void			sorting(t_mstack **s, t_meta *m)
{
	while (s[0])
	{
		if (s[0] && (s[0]->pos == 1 || s[0]->pos == 11))
			move_up_part(s, m);
		if (s[0]->quantity > 4)
			div_sort_parts(s, m);
		else
			mini_sorting(s, m);
	}
}

int					main(int ac, char **av)
{
	t_meta		meta;
	t_mstack	*t;

	t = NULL;
	if (ac < 2)
		ps_hint();
	else
	{
		init_ps(&meta);
		meta.program = 'p';
		parse_in(ac, av, &meta);
		if (ft_lstsorted(*meta.p) == 0)
		{
			meta.a = meta.p[0];
			if (ft_mstack_pop(&t, 0, meta.nums, 0) < 0)
				ft_exit(&meta);
			sorting(&t, &meta);
		}
		if (meta.flags.t)
			print_total(meta.size);
		ft_lstfree(meta.p);
	}
	return (0);
}
