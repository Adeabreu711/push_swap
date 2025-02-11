/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:56:34 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/11 00:08:22 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_init_stack_b(t_stack *stk_a)
{
	t_stack	*stk_b;
	t_stack *temp;

	temp = stk_a;
	stk_b = ft_stknew(temp->nb);
	temp = temp->next;
	ft_stk_add_back(&stk_b, ft_stknew(temp->nb));
	ft_set_index(stk_b);
	return (stk_b);
}
