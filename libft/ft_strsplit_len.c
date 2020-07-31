/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:33:02 by loram             #+#    #+#             */
/*   Updated: 2020/07/30 17:33:04 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strsplit_len(char **strsplit)
{
	size_t	size;

	size = 0;
	if (strsplit)
		while (*strsplit)
		{
			size++;
			strsplit++;
		}
	return (size);
}
