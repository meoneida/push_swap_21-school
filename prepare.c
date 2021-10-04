/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:09:52 by meoneida          #+#    #+#             */
/*   Updated: 2021/09/23 01:09:56 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	longest_line_add(int max, int j, int *arr)
{
	int	i;

	i = max;
	while (j >= 0)
	{
		if (arr[j] == i)
			i--;
		else
			arr[j] = -1;
		j--;
	}
}

int	longest_line(t_stack **el, t_info **inf, int *arr, int max)
{
	t_stack	*tmpi;
	t_stack	*tmpj;
	int		i;
	int		j;

	tmpj = (*el)->next;
	j = 1;
	while (j < (*inf)->no_a)
	{
		arr[j] = 1;
		i = 0;
		tmpi = *el;
		while (tmpi->index != tmpj->index)
		{
			if (tmpi->index < tmpj->index && arr[j] <= arr[i])
				arr[j] = arr[i] + 1;
			bigger(arr[j], &max);
			i++;
			tmpi = tmpi->next;
		}
		tmpj = tmpj->next;
		j++;
	}
	longest_line_add(max, j - 1, arr);
	return (max);
}

static void	best_index_add(t_stack **tmp, t_info **inf, int *arr, int k)
{
	while (++k < (*inf)->no_a)
	{
		if (arr[k] == -1)
			(*tmp)->flag = 0;
		*tmp = (*tmp)->next;
	}
}

int	best_index(t_stack *el, t_info *inf)
{
	t_stack	*tmp;
	int		k;
	int		max;
	int		*arr;

	arr = (int *)malloc(sizeof(int) * (inf->no_a));
	k = 0;
	tmp = el;
	while (k++ < inf->no_a)
	{
		arr[0] = 1;
		max = longest_line(&tmp, &inf, arr, 0);
		if (bigger(max, &inf->max_len))
			inf->max_pos = tmp->index;
		tmp = tmp->next;
	}
	while (tmp->index != inf->max_pos)
		tmp = tmp->next;
	arr[0] = 1;
	longest_line(&tmp, &inf, arr, 0);
	best_index_add(&tmp, &inf, arr, -1);
	free(arr);
	return (inf->max_len);
}

int	fill_b(t_stack **head_a, t_stack **head_b, t_info **inf)
{
	int		i;
	t_stack	*tmp;

	(*inf)->no_b = (*inf)->no_a - (*inf)->max_len;
	(*inf)->no_a = (*inf)->max_len;
	*head_b = NULL;
	i = 0;
	while (i < (*inf)->no_b)
	{
		tmp = *head_a;
		while (tmp->flag == 1)
			tmp = tmp->next;
		get_up(head_a, tmp->index, inf, 1);
		(*inf)->count += p(head_a, head_b, 0);
		i++;
	}
	return (0);
}
