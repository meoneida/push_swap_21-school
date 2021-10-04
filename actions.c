/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:09:15 by meoneida          #+#    #+#             */
/*   Updated: 2021/09/29 02:58:24 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s(t_stack **el, int a)
{
	t_stack	*next_1;
	t_stack	*next_2;
	t_stack	*prev_1;

	if (*el == NULL || (*el)->next == *el)
		return (0);
	else if ((*el)->next->next == *el)
		*el = (*el)->next;
	else
	{
		next_1 = (*el)->next;
		prev_1 = (*el)->prev;
		next_2 = next_1->next;
		prev_1->next = next_1;
		next_1->prev = prev_1;
		next_1->next = *el;
		(*el)->prev = next_1;
		next_2->prev = *el;
		(*el)->next = next_2;
		*el = next_1;
		return (1);
	}
	return (0);
}

int	r(t_stack **el, int a)
{
	if (!(*el) || (*el)->number == (*el)->next->number)
		return (0);
	else
	{
		*el = (*el)->next;
		if (a == 1)
			write(1, "ra\n", 3);
		else if (a == 0)
			write(1, "rb\n", 3);
	}
	return (1);
}

int	rr(t_stack **el, int a)
{
	if (!(*el) || (*el)->number == (*el)->next->number)
		return (0);
	else
	{
		*el = (*el)->prev;
		if (a == 1)
			write(1, "rra\n", 4);
		else if (a == 0)
			write(1, "rrb\n", 4);
	}
	return (1);
}

static void	p_add(t_stack **src, t_stack **dst)
{
	t_stack	*dstprev;

	if (*dst)
	{
		dstprev = (*dst)->prev;
		dstprev->next = (*src);
		(*src)->prev = dstprev;
		(*dst)->prev = (*src);
		(*src)->next = *dst;
		*dst = *src;
	}	
	else
	{
		*dst = *src;
		(*dst)->next = *dst;
		(*dst)->prev = *dst;
	}
}

int	p(t_stack **src, t_stack **dst, int a)
{
	t_stack	*srcprev;
	t_stack	*srcnext;

	if (!(*src))
		return (0);
	srcprev = (*src)->prev;
	srcnext = (*src)->next;
	p_add(src, dst);
	if ((*src)->number == srcnext->number)
		*src = NULL;
	else
	{
		srcprev->next = srcnext;
		srcnext->prev = srcprev;
		*src = srcnext;
	}
	if (a)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return (1);
}
