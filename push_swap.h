/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:10:05 by meoneida          #+#    #+#             */
/*   Updated: 2021/09/23 01:52:32 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				flag;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_info
{
	int				no_a;
	int				no_b;
	int				max_pos;
	int				max_len;
	int				min_index;
	int				count;
	int				err;
}					t_info;

t_stack				*add_el(t_info **inf);
int					ft_split(t_stack **head_a, char *s, int *i, t_info **inf);
int					fill_a(t_stack **head_a, char *s, int *i, t_info **inf);
int					fill_number(char *s, t_stack *ps);
void				fill_index(t_stack *el, int curr_index, int curr_number);
int					longest_line(t_stack **el, t_info **inf, int *arr, int max);
int					best_index(t_stack *el, t_info *inf);
int					fill_b(t_stack **head_a, t_stack **head_b, t_info **inf);
int					get_best_index(t_stack *lst_a, t_stack *lst_b, t_info *inf);
int					find_hole(t_stack *lst, int index, t_info *inf);
int					back_home(t_stack **a, t_stack **b, t_info **inf);
int					get_up(t_stack **el, int index, t_info **inf, int a);
int					move_both(t_stack **a, t_stack **b, int a_up, int b_up);
int					s(t_stack **el, int a);
int					r(t_stack **el, int a);
int					rr(t_stack **el, int a);
int					p(t_stack **src, t_stack **dst, int a);
int					bigger(int a, int *b);
int					smaller(int a, int *b);
int					ft_mod(int a);
int					steps_up(t_stack *lst, int index);
int					min_move(int a, int b);
int					free_ft(t_stack **s, t_info **inf);

#endif
