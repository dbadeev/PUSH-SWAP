/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 19:19:57 by loram             #+#    #+#             */
/*   Updated: 2020/07/30 19:19:59 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_strsplit_free(char **parts)
{
	ssize_t		i;

	i = -1;
	while (parts[++i] != NULL)
	{
		free(parts[i]);
		parts[i] = NULL;
	}
	free(parts);
	parts = NULL;
}
