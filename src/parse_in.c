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

	if (((av[0] == '-' || av[0] == '+') && ft_isdigit(av[1]))
		|| ft_isdigit(av[0]))
		return (0);
	else if ((av[0] != '-') || ((av[0] == '-') && (av[1] == '\0')))
		ft_exit(0);
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
			ft_exit(0);
	}
	return (1);
}

static t_stack		*ft_lstget(t_stack *a, int num, t_meta *meta)
{
	t_stack	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_stack))))
		ft_exit(meta);
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

static void			parse_data(int ac, int temp_ac, char **av, t_meta *meta)
{
	unsigned	j;
	int			num;

	j = 0;
	if (!(meta->p = ft_memalloc(sizeof(t_stack*) * (ac - temp_ac + 1))))
		ft_exit(meta);
	meta->nums = ac - temp_ac;
	while (j < meta->nums)
	{
		num = ft_atoi_ps(av[temp_ac + j], meta);
		meta->p[j] = (j > 0) ? ft_lstget(meta->p[j - 1], num, meta)
							: ft_lstget(NULL, num, meta);
		j++;
	}
}

int					parse_in(int ac, char **av, t_meta *meta, unsigned j)
{
	unsigned	i;

	i = 1;
	j = 0;
	while ((i < (unsigned)ac) && (check_param(av[i], meta) > 0))
		i++;
	if (i < (unsigned)ac)
		parse_data(ac, (int)i, av, meta);
	else
		return (1);
	i = 0;
	while (i < meta->nums)
	{
		j = 0;
		while (j < meta->nums)
		{
			if ((i != j) && (meta->p[i]->num == meta->p[j]->num))
				ft_exit(meta);
			else if ((i != j) && (meta->p[i]->num > meta->p[j]->num))
				meta->p[i]->label++;
			j++;
		}
		i++;
	}
	return (0);
}
