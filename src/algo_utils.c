/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:46:08 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/27 13:08:10 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Get the max value of the given stack.
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

//Rheck if the the given stack is sorted
//in ascending order, return 0 if not.
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

/**
 * @brief Compare a number to all the values of the given stack b.
 *
 * The target is the most close inferior value to the given number
 * or the max value if not found.
 * @return Return the id of the best target found.
 */
int	ft_get_btrg_id(int nb, t_stack *stk_b)
{
	t_stack	*temp;
	t_stack	*best;

	temp = stk_b;
	best = temp;
	while (temp)
	{
		if (temp->nb < nb && temp->nb < best->nb && best->nb > nb)
			best = temp;
		else if (temp->nb < nb && temp->nb > best->nb)
			best = temp;
		else if (temp->nb > best->nb && best->nb > nb)
			best = temp;
		temp = temp->next;
	}
	return (best->id);
}

/**
 * @brief Compare a number to all the values of the given stack a.
 *
 * The target is the most close superior value to the given number
 * or the min value if not found.
 * @return Return the id of the best target found.
 */
int	ft_get_atrg_id(int nb, t_stack *stk_a)
{
	t_stack	*temp;
	t_stack	*best;

	temp = stk_a;
	best = temp;
	while (temp)
	{
		if (temp->nb > nb && temp->nb > best->nb && best->nb < nb)
			best = temp;
		else if (temp->nb > nb && temp->nb < best->nb)
			best = temp;
		else if (temp->nb < best->nb && best->nb < nb)
			best = temp;
		temp = temp->next;
	}
	return (best->id);
}
