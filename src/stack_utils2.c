/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:04:06 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/03 23:04:24 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Set the index of the elements of the given stack in order.
void	ft_set_index(t_stack *stk)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = stk;
	while (temp)
	{
		temp->id = i;
		temp = temp->next;
		i++;
	}
}
