/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:51:20 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 22:51:22 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_lstfree(t_stack **s)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	while (s[i] != NULL)
	{
		tmp = s[i];
		tmp->num = 0;
		tmp->label = 0;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
		i++;
	}
	free(s);
	s = NULL;
}
