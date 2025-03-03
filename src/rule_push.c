/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:50:29 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/03 22:02:16 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Push the top element of stack src to the top of stack dest.
static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
	ft_set_index(*src);
	ft_set_index(*dest);
}

//Push the top element of stack b to the top of stack a.
void	ft_pa(t_stack **stk_a, t_stack **stk_b, int show)
{
	ft_push(stk_b, stk_a);
	if (show)
		write(1, "pa\n", 3);
}

//Push the top element of stack a to the top of stack b.
void	ft_pb(t_stack **stk_a, t_stack **stk_b, int show)
{
	ft_push(stk_a, stk_b);
	if (show)
		write(1, "pb\n", 3);
}
