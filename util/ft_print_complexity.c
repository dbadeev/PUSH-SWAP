/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_complexity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 19:54:38 by loram             #+#    #+#             */
/*   Updated: 2020/07/24 19:54:47 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_complexity(int nums, int sup, int complexity)
{
	ft_putstr("\033[0mUpper_bound of\tcomplexity for \033[33m");
	ft_putnbr(nums);
	ft_putstr("\033[0m element(s): \033[33m");
	ft_putnbr(sup);
	ft_putstr("\033[0m operations\033[0m\n");
	ft_putstr("\033[0mA_v_e_r_a_g_e\tcomplexity for \033[33m");
	ft_putnbr(nums);
	ft_putstr("\033[0m element(s): \033[33m");
	ft_putnbr(complexity);
	ft_putstr("\033[0m operations\033[0m\n");
}
