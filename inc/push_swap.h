/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loram <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:08:44 by loram             #+#    #+#             */
/*   Updated: 2020/07/14 21:08:47 by loram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "util.h"
# include "messages.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct		s_ps
{
	int								cur_ac;
	char							*cur_av;
	char							flag[6];
	char							length[3];
	char							spec;
	long int						width;
	long int						pr;
	char							*flag_mask;
	char							*length_mask;
	char							*spec_mask;
	int								i;
	int								len;
	int								da_len;
	int								da_exp;
}					t_ps;

void				ps_hint(void);
void				init_ps(t_meta *meta);
int					parse_in(int ac, char **av, t_meta *meta, int j);
int					command_in(char *cmd, t_stack **a, t_stack **b, t_meta *m);
void				div_sort_parts(t_mstack **s, t_meta *m);
void				move_up_part(t_mstack **s, t_meta *m);
void				print_status(char *cmd, t_stack **a, t_stack **b,
															t_flags flags);
void				print_total(int ap);
void				div_parts_a(t_mstack **s, t_meta *m, int first);
void				div_parts_b(t_mstack **s, t_meta *m, int first);
void				mini_sorting(t_mstack **s, t_meta *m);

#endif
