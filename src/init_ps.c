/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:36:05 by loram             #+#    #+#             */
/*   Updated: 2020/07/22 16:36:07 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_meta *meta)
{
	meta->p = NULL;
	meta->a = NULL;
	meta->b = NULL;
	meta->program = '\0';
	meta->nums = 0;
	meta->a_nums = 0;
	meta->b_nums = 0;
	meta->sorted = 0;
	meta->min = 0;
	meta->mid = 0;
	meta->max = 0;
	meta->size = 0;
	meta->complexity = 0;
	meta->flags.t = 0;
	meta->flags.v = 0;
	meta->flags.s = 0;
	meta->flags.a = 0;
	meta->flags.c = 0;
}
