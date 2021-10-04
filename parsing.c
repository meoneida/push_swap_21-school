/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:09:47 by meoneida          #+#    #+#             */
/*   Updated: 2021/09/23 01:40:01 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_el(t_info **inf)
{
	t_stack	*lst;

	lst = NULL;
	lst = (t_stack *)malloc(sizeof(t_stack));
	if (lst == NULL)
	{
		(*inf)->err = 0;
		return (NULL);
	}
	lst->number = 0;
	lst->index = 0;
	lst->flag = 1;
	lst->prev = lst;
	lst->next = lst;
	return (lst);
}

int	fill_a(t_stack **head_a, char *s, int *i, t_info **inf)
{
	t_stack	*new;

	new = NULL;
	if (!(*head_a))
	{
		*head_a = add_el(inf);
		smaller(fill_number(s, *head_a), &((*inf)->err));
		(*head_a)->index = 0;
	}
	else
	{
		new = add_el(inf);
		(*head_a)->prev->next = new;
		new->prev = (*head_a)->prev;
		new->next = (*head_a);
		(*head_a)->prev = new;
		smaller(fill_number(s, new), &((*inf)->err));
		(*i)++;
		new->index = *i;
		fill_index(*head_a, *i, new->number);
	}
	return ((*inf)->err);
}

int	ft_split(t_stack **head_a, char *s, int *i, t_info **inf)
{
	char	*start;

	while (*s)
	{
		if (*s != ' ')
		{
			start = s;
			while ((*s != ' ') && *s)
				s++;
			if (*s)
			{
				*s = '\0';
				s++;
			}
			if (!fill_a(head_a, start, i, inf))
				return (0);
		}
		else
			s++;
	}
	return (1);
}

int	fill_number(char *s, t_stack *el)
{
	long int	number;
	int			minus;

	number = 0;
	minus = 1;
	if (*s == '+')
		s++;
	else if (*s == '-')
		s++, minus = -1;
	while (*s == '0')
		s++;
	if (*s > '0' && *s <= '9')
		number = *(s++) - 48;
	while (*s >= '0' && *s <= '9')
		number = number * 10 + (*s++ - 48);
	if (*s || !el || (number * minus) < -2147483648
		|| (number * minus) > 2147483647)
		return (0);
	el->number = (int)(number * minus);
	return (1);
}

void	fill_index(t_stack *el, int curr_index, int curr_number)
{
	t_stack	*tmp;
	int		pos;
	int		i;

	tmp = el;
	i = -1;
	while (++i < curr_index)
	{
		while (tmp->index != i)
			tmp = tmp->next;
		if (curr_number < tmp->number)
		{
			pos = tmp->index;
			el->prev->index = pos;
			tmp = el;
			while (tmp->next->number != el->number)
			{
				if (tmp->index >= pos && tmp->index < curr_index)
					(tmp->index)++;
				tmp = tmp->next;
			}
			return ;
		}
	}
}
