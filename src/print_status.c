/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:04:38 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 22:04:40 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_size(t_stack *s)
{
	ft_putchar('(');
	ft_putnbr((int)ft_lstsize(s));
	ft_putchar(')');
}

void			print_status(char *cmd, t_stack **a, t_stack **b, t_flags flags)
{
	system("clear");
	ft_putstr("Command: ");
	ft_putendl(cmd);
	if (flags.c)
		ft_putstr("\033[32m");
	ft_putstr("Stack A ");
	if (flags.a)
		print_size(*a);
	ft_putstr(": \033[0m");
	ft_lstprint(*a);
	ft_putchar('\n');
	if (flags.c)
		ft_putstr("\033[33m");
	ft_putstr("Stack B ");
	if (flags.a)
		print_size(*b);
	ft_putstr(": \033[0m");
	ft_lstprint(*b);
	ft_putstr("\n");
	sleep(flags.s ? 1 : 0);
}
