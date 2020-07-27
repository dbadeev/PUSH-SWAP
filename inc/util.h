/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:09:42 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 21:09:47 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stack
{
	int				num;
	unsigned		label;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_mstack
{
	unsigned		first;
	unsigned		quantity;
	int				pos;
	struct s_mstack	*next;
}					t_mstack;

typedef struct		s_flags
{
	int			t;
	int			v;
	int			s;
	int			a;
	int			c;
	int			h;
}					t_flags;

typedef struct		s_meta
{
	char			program;
	unsigned		nums;
	unsigned		a_nums;
	unsigned		b_nums;
	unsigned		min;
	unsigned		mid;
	unsigned		max;
	t_stack			**p;
	t_stack			*a;
	t_stack			*b;
	t_flags			flags;
	unsigned		size;
	unsigned		sorted;
	double			complexity;
}					t_meta;

/*
** cmd
*/
void				sa(t_stack **a, t_meta *m);
void				sb(t_stack **b, t_meta *m);
void				ss(t_stack **a, t_stack **b, t_meta *m);
void				pa(t_stack **a, t_stack **b, t_meta *m);
void				pb(t_stack **a, t_stack **b, t_meta *m);
void				ra(t_stack **a, t_meta *m);
void				rb(t_stack **b, t_meta *m);
void				rr(t_stack **a, t_stack **b, t_meta *m);
void				rra(t_stack **a, t_meta *m);
void				rrb(t_stack **b, t_meta *m);
void				rrr(t_stack **a, t_stack **b, t_meta *m);
/*
** util
*/
int					ft_atoi_ps(const char *str, t_meta *meta);
void				ft_lstpush(t_stack **a, t_stack **b);
void				ft_lst_rrr(t_stack **s);
void				ft_lst_rr(t_stack **s);
void				ft_lstswp(t_stack **s);
void				ft_lstfree(t_stack **s);
unsigned			ft_lstsize(t_stack *a);
int					ft_lstsorted(t_stack *s);
void				ft_exit(t_meta *meta);
void				ft_lstprint(t_stack *a);
int					ft_mstack_pop(t_mstack **s, unsigned first, unsigned last,
																	int pos);
void				ft_mstack_push(t_mstack **s);
void				ft_del_mstack(t_mstack **s);
void				ft_mini_sort_three_ab(t_mstack **s, t_meta *m,
															unsigned comb);
void				ft_mini_sort_four_a_two(t_meta *m, unsigned comb);
void				ft_mini_sort_four_a_one(t_meta *m, unsigned comb);
void				ft_mini_sort_four_b_one(t_meta *m, unsigned comb);
void				ft_mini_sort_four_b_two(t_meta *m, unsigned comb);
void				ft_print_complexity(int nums, int sup, int complexity);
#endif
