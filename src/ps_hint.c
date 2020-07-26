/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:39:28 by loram             #+#    #+#             */
/*   Updated: 2020/07/22 16:39:30 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_hint(void)
{
	ft_putstr("\n\t\033[31mUsage:\t\033[32m./push_swap [-vtsac] [numbers ...]"
																"\033[0m\n");
	ft_putstr("\t\t\033[32m./checker [-vtsac] [numbers ...]"
																"\033[0m\n");
	ft_putstr("\t\t\033[33m-v :\033[34m enable visualizing\033[0m\n");
	ft_putstr("\t\t\033[33m-t :\033[34m show total number of actions\n");
	ft_putstr("\t\t\033[33m-s :\033[34m enable delay while vizualizing\n");
	ft_putstr("\t\t\033[33m-a :\033[34m enable stack's elements count\n");
	ft_putstr("\t\t\033[33m-c :\033[34m enable color for stacks\033[0m\n");
	ft_putstr("\t\033[31mOR:\033[0m\t");
	ft_putstr("\033[32m./complexity [number_of_elements] \033[0m\n\n");
	exit(1);
}
