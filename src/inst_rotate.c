/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:33:06 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 16:31:01 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//The top element of the given stack became the last.
static void	ft_rotate(t_stack **stk)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stk;
	*stk = (*stk)->next;
	last = ft_checklast(*stk);
	last->next = temp;
	temp->next = NULL;
	ft_set_index(*stk);
}

//The top element of the stack a became the last.
void	ft_ra(t_stack **stk_a, int show)
{
	ft_rotate(stk_a);
	if (show)
		write(1, "ra\n", 3);
}

//The top element of the stack b became the last.
void	ft_rb(t_stack **stk_b, int show)
{
	ft_rotate(stk_b);
	if (show)
		write(1, "rb\n", 3);
}

//The top element of the stack a and b became the last.
void	ft_rr(t_stack **stk_a, t_stack **stk_b, int show)
{
	ft_rotate(stk_a);
	ft_rotate(stk_b);
	if (show)
		write(1, "rr\n", 3);
}
