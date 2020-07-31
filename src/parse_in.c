/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:02:15 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 22:02:15 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			flag_activate(char av, t_meta *meta)
{
	if (av == 'v')
		meta->flags.v = 1;
	else if (av == 't')
		meta->flags.t = 1;
	else if (av == 's')
		meta->flags.s = 1;
	else if (av == 'a')
		meta->flags.a = 1;
	else if (av == 'c')
		meta->flags.c = 1;
}

static int			check_param(char *av, t_meta *meta)
{
	int		i;

	if (av[0] == '\0')
		return (1);
	if (((av[0] == '-' || av[0] == '+') && ft_isdigit(av[1]))
		|| ft_isdigit(av[0]) || av[0] == ' ' || av[0] == '\t' || av[0] == '\v')
		return (0);
	else if ((av[0] != '-') || ((av[0] == '-') && (av[1] == '\0')))
		ft_exit(ERR_INVALID_SYM, 0);
	i = 1;
	while (av[i] != '\0')
	{
		if (av[i] == 'v' || av[i] == 't' || av[i] == 's'
			|| av[i] == 'a' || av[i] == 'c')
		{
			flag_activate(av[i], meta);
			i++;
		}
		else
			ft_exit(ERR_INVALID_SYM, 0);
	}
	return (1);
}

static void			parse_data(int ac, int temp_ac, char **av, t_meta *meta)
{
	int		j;
	int		num;

	j = 0;
	if (!(meta->p = ft_memalloc(sizeof(t_stack*) * (ac - temp_ac + 1))))
		ft_exit(ERR_MEMALLOC, meta);
	meta->nums = ac - temp_ac;
	while (j < meta->nums)
	{
		num = ft_atoi_ps(av[temp_ac + j], meta);
		meta->p[j] = (j > 0) ? ft_lstget(meta->p[j - 1], num, meta)
							: ft_lstget(NULL, num, meta);
		j++;
	}
}

static int			parse_str(char *str, t_meta *meta, int j)
{
	char	**numbers;
	int		num;

	if (!(numbers = ft_strsplit(str, ' ')))
		ft_exit(ERR_MEMALLOC, 0);
	meta->nums = ft_strsplit_len(numbers);
	if (numbers[0] == '\0')
	{
		ft_strsplit_free(numbers);
		return (1);
	}
	if (!(meta->p = ft_memalloc(sizeof(t_stack*) * (meta->nums + 1))))
	{
		ft_strsplit_free(numbers);
		ft_exit(ERR_MEMALLOC, meta);
	}
	while (j < meta->nums)
	{
		num = ft_atoi_ps(numbers[j], meta);
		meta->p[j] = (j > 0) ? ft_lstget(meta->p[j - 1], num, meta)
							: ft_lstget(NULL, num, meta);
		j++;
	}
	ft_strsplit_free(numbers);
	return (0);
}

int					parse_in(int ac, char **av, t_meta *meta, int j)
{
	int		i;

	i = ((1 < ac) && (check_param(av[1], meta) > 0)) ? 2 : 1;
	if ((ac == i) || ((ac == i + 1) && (parse_str(av[i], meta, 0) == 1)))
		return (1);
	else if ((i < ac) && (ac != i + 1))
		parse_data(ac, i, av, meta);
	i = 0;
	while (i < meta->nums)
	{
		j = 0;
		while (j < meta->nums)
		{
			if ((i != j) && (meta->p[i]->num == meta->p[j]->num))
				ft_exit(ERR_DUPLICATE, meta);
			else if ((i != j) && (meta->p[i]->num > meta->p[j]->num))
				meta->p[i]->label++;
			j++;
		}
		i++;
	}
	return (0);
}
