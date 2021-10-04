/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 01:14:31 by meoneida          #+#    #+#             */
/*   Updated: 2021/09/23 04:51:46 by meoneida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_ft(t_stack **s, t_info **inf)
{
	t_stack	*tmp;

	if (*s)
		(*s)->prev->next = NULL;
	while (*s)
	{
		tmp = *s;
		*s = (*s)->next;
		free(tmp);
		tmp = NULL;
	}
	free(*inf);
	*inf = NULL;
	return (0);
}
