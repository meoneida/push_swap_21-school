/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:09:22 by meoneida          #+#    #+#             */
/*   Updated: 2021/09/23 01:09:34 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_best_index(t_stack *lst_a, t_stack *lst_b, t_info *inf)
{
	int		i;
	t_stack	*tmp_b;
	int		up_a;
	int		up_b;
	int		min;

	i = 0;
	min = 2147483647;
	tmp_b = lst_b;
	while (i < (inf)->no_b)
	{
		up_b = steps_up(lst_b, tmp_b->index);
		up_a = steps_up(lst_a, find_hole(lst_a, tmp_b->index, inf));
		if (smaller(min_move(up_a, up_b), &min))
			inf->min_index = tmp_b->index;
		tmp_b = tmp_b->next;
		i++;
	}
	return (inf->min_index);
}

int	find_hole(t_stack *lst, int index, t_info *inf)
{
	int		i;
	t_stack	*prev;

	i = 0;
	while (i < inf->no_a)
	{
		prev = lst->prev;
		if (prev->index < index
			&& (lst->index < prev->index || index < lst->index))
			return (lst->index);
		if (lst->index > index
			&& (lst->index < prev->index || index > prev->index))
			return (lst->index);
		lst = lst->next;
	}
	return (0);
}

int	back_home(t_stack **a, t_stack **b, t_info **inf)
{
	int	a_index;
	int	b_index;
	int	up_a;
	int	up_b;

	b_index = get_best_index(*a, *b, *inf);
	a_index = find_hole(*a, b_index, *inf);
	up_b = steps_up(*b, b_index);
	up_a = steps_up(*a, a_index);
	if ((up_a >= 0 && up_b >= 0) || (up_a <= 0 && up_b <= 0))
		(*inf)-> count += move_both(a, b, up_a, up_b);
	else
	{
		get_up(b, b_index, inf, 0);
		get_up(a, a_index, inf, 1);
	}
	(*inf)-> count += p(b, a, 1);
	return (1);
}

int	get_up(t_stack **el, int index, t_info **inf, int a)
{	
	int	up_el;
	int	i;

	up_el = steps_up(*el, index);
	i = 0;
	if (up_el < 0)
		while (i++ < ft_mod(up_el))
			(*inf)-> count += rr(el, a);
	else
		while (i++ < ft_mod(up_el))
			(*inf)-> count += r(el, a);
	return (1);
}

int	move_both(t_stack **a, t_stack **b, int up_a, int up_b)
{
	int	(*f)(t_stack **arg, int a);
	int	i;

	i = 0;
	if (up_a >= 0 && up_b >= 0)
		f = r;
	else
		f = rr;
	while (i < ft_mod(up_a) && i < ft_mod(up_b))
	{
		f(a, -1);
		f(b, -1);
		if (up_a > 0)
			write(1, "rr\n", 3);
		else
			write(1, "rrr\n", 4);
		i++;
	}
	while (i < ft_mod(up_a) && i++ >= 0)
		f(a, 1);
	while (i < ft_mod(up_b) && i++ >= 0)
		f(b, 0);
	return (i);
}
