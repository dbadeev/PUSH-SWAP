/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:18:49 by loram             #+#    #+#             */
/*   Updated: 2020/07/30 01:18:53 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_lstget(t_stack *a, int num, t_meta *meta)
{
	t_stack	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_stack))))
		ft_exit(ERR_MEMALLOC, meta);
	if (tmp)
	{
		tmp->num = num;
		tmp->label = 0;
		tmp->next = NULL;
	}
	if (a)
		a->next = tmp;
	return (tmp);
}
