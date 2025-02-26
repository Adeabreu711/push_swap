/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:46:08 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/26 21:21:36 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_get_max(t_stack *stk)
{
	t_stack	*temp;
	t_stack	*max;

	temp = stk;
	max = stk;
	while (temp)
	{
		if (temp->nb > max->nb)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

int	ft_check_sort(t_stack *stk)
{
	t_stack	*front;
	t_stack	*back;

	front = stk->next;
	back = stk;
	while (front)
	{
		if (front > back)
			return (0);
		front = front->next;
		back = back->next;
	}
	return (1);
}
