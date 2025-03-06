/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:50:29 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 20:06:42 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Push the top element of stack src to the top of stack dest.
static int	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!*src)
		return (0);
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
	ft_set_index(*src);
	ft_set_index(*dest);
	return (1);
}

//Push the top element of stack b to the top of stack a.
void	ft_pa(t_stack **stk_a, t_stack **stk_b, int show)
{
	if (!ft_push(stk_b, stk_a))
		return ;
	if (show)
		write(1, "pa\n", 3);
}

//Push the top element of stack a to the top of stack b.
void	ft_pb(t_stack **stk_a, t_stack **stk_b, int show)
{
	if (!ft_push(stk_a, stk_b))
		return ;
	if (show)
		write(1, "pb\n", 3);
}
