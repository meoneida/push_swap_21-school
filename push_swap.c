/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:10:01 by meoneida          #+#    #+#             */
/*   Updated: 2021/09/23 02:09:06 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_info	*fill_info(void)
{
	t_info	*lst;

	lst = NULL;
	lst = (t_info *)malloc(sizeof(t_info));
	if (!lst)
		return (NULL);
	lst->no_a = 0;
	lst->no_a = 0;
	lst->max_pos = 0;
	lst->max_len = 0;
	lst->min_index = 0;
	lst->count = 0;
	lst->err = 1;
	return (lst);
}

static int	check_dup(t_stack *head_a, t_info *inf)
{
	t_stack	*tmpi;
	t_stack	*tmpj;
	t_stack	*last;

	if (!head_a)
		return (0);
	tmpi = head_a;
	last = head_a->prev;
	while (tmpi != last)
	{
		tmpj = tmpi->next;
		while (tmpj != head_a)
		{
			if (tmpi->number == tmpj->number)
			{
				inf->err = 0;
				return (0);
			}
			tmpj = tmpj->next;
		}
		tmpi = tmpi->next;
	}
	return (1);
}

static void	make_three(t_stack **head_a, t_info **inf)
{
	t_stack	*tmp;

	tmp = *head_a;
	if (tmp->number > tmp->next->number)
		tmp = tmp->next;
	else if (tmp->next->number > tmp->prev->number)
		tmp = tmp->prev;
	if (tmp->number > tmp->next->number
		|| tmp->next->number > tmp->prev->number)
	{
		s(head_a, 1);
		write (1, "sa\n", 3);
		(*inf)->count += 1;
	}
}

static void	part_2(t_stack *head_a, t_stack *head_b, t_info *inf)
{
	int	i;
	int	j;

	if (inf->no_a == 3)
		make_three(&head_a, &inf);
	best_index(head_a, inf);
	fill_b(&head_a, &head_b, &inf);
	i = 0;
	j = inf->no_b;
	while (i++ < j)
	{
		back_home(&head_a, &head_b, &inf);
		inf->no_b -= 1;
		inf->no_a += 1;
	}
	get_up(&head_a, 0, &inf, 1);
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_info	*inf;
	int		i;

	inf = fill_info();
	if (!inf)
		return (0);
	head_a = NULL;
	head_b = NULL;
	i = 0;
	while (*(++argv))
		ft_split(&head_a, *argv, &i, &inf);
	check_dup(head_a, inf);
	if (!inf->err)
	{
		write(1, "Error\n", 6);
		return (free_ft(&head_a, &inf));
	}
	if (argc < 2 || i < 1)
		return (free_ft(&head_a, &inf));
	inf->no_a = i + 1;
	part_2(head_a, head_b, inf);
	free_ft(&head_a, &inf);
	return (0);
}
