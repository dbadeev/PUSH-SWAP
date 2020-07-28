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

static int			read_action(t_stack **a, t_stack **b, t_meta *m)
{
	int		i;
	int		ret;
	char	c;
	char	cmd[4];

	ft_bzero(cmd, sizeof(char) * 4);
	i = 0;
	while ((ret = read(0, &c, 1)) > 0)
	{
		if (c == '\n')
			return (command_in(cmd, a, b, m));
		if (i >= 3)
		{
			while (c != '\n')
				read(0, &c, 1);
			return (1);
		}
		cmd[i] = c;
		i++;
		cmd[i] = '\0';
	}
	return (ret == 0 ? 10 : -1);
}

static void			commands(t_stack **a, t_stack **b, t_meta *m)
{
	int		res;

	res = -1;
	while ((res = read_action(a, b, m)) != 10)
	{
		if (res == 1)
			ft_exit(ERR_NOT_COMMAND, m);
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
	if (parse_in(ac, av, &meta, 0) == 1)
		return (0);
	meta.a = meta.p[0];
	commands(&meta.a, &meta.b, &meta);
	ft_putendl(check(meta.a, meta.b) ? "\033[32mOK\033[0m" :
	"\033[31mKO\033[0m");
	if (meta.flags.t)
		print_total((int)meta.size);
	ft_lstfree(meta.p);
	return (0);
}
