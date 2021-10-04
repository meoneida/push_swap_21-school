/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:10:12 by meoneida          #+#    #+#             */
/*   Updated: 2021/09/23 01:43:41 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger(int a, int *b)
{
	if (a > *b)
	{
		*b = a;
		return (1);
	}
	return (0);
}

int	smaller(int a, int *b)
{
	if (a < *b)
	{
		*b = a;
		return (1);
	}
	return (0);
}

int	ft_mod(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int	steps_up(t_stack *lst, int index)
{
	int			i;
	int			j;
	t_stack		*tmp;

	tmp = lst;
	i = 0;
	while (tmp->index != index)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = lst;
	j = 0;
	while (tmp->index != index)
	{
		tmp = tmp->prev;
		j++;
	}
	if (j < i)
		return (j * -1);
	else
		return (i);
}

int	min_move(int a, int b)
{
	unsigned int	c;

	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
	{
		if (ft_mod(a) >= ft_mod(b))
			return (ft_mod(a));
		else
			return (ft_mod(b));
	}
	else
		c = ft_mod(a) + ft_mod(b);
	return (c);
}
