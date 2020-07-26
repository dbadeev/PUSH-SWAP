/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 01:29:55 by loram             #+#    #+#             */
/*   Updated: 2020/07/19 01:29:56 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			print_total(int ap)
{
	ft_putstr("Total actions: ");
	ft_putnbr(ap);
	ft_putchar('\n');
}

static void			commands(t_stack **a, t_stack **b, t_meta *m)
{
	char	*cmd;

	while (get_next_line(0, &cmd) > 0)
	{
		command_in(cmd, a, b, m);
		free(cmd);
	}
	if (cmd && *cmd)
	{
		free(cmd);
		cmd = NULL;
	}
}

static int			check(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while (a && a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int					main(int ac, char **av)
{
	t_meta	meta;

	if (ac == 1)
		return (0);
	init_ps(&meta);
	meta.program = 'c';
	parse_in(ac, av, &meta);
	meta.a = meta.p[0];
	commands(&meta.a, &meta.b, &meta);
	ft_putendl(check(meta.a, meta.b) ? "\033[32mOK\033[0m" :
	"\033[31mKO\033[0m");
	if (meta.flags.t)
		print_total((int)meta.size);
	ft_lstfree(meta.p);
	return (0);
}
