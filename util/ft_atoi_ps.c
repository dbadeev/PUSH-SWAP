/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:41:29 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 22:41:31 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi_ps(const char *str, t_meta *meta)
{
	int					sign;
	int					result;
	int					prev;
	int					i;

	result = 0;
	prev = 0;
	sign = (str[0] == '-') ? -1 : 1;
	i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
	if ((str[i] == '\0') || !((str[i] >= '0' && str[i] <= '9') ||
										str[0] == '-' || str[0] == '+'))
		(meta->p) ? ft_exit(ERR_NAN, meta) : ft_exit(ERR_NAN, 0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((prev != result / 10) && (sign == 1 ||
				((sign == -1) && (prev == result / -10) && (str[i] != '8'))))
			ft_exit(ERR_NAN, meta);
		prev = result;
		i++;
	}
	if (str[i] != '\0')
		ft_exit(ERR_NAN, meta);
	return (result * sign);
}
