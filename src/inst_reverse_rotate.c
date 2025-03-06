/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 02:02:03 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 16:30:57 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//The last element of the given stack became the first.
static void	ft_reverse_rotate(t_stack **stk)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*second_last;

	second_last = *stk;
	while (second_last->next->next)
		second_last = second_last->next;
	temp = *stk;
	last = ft_checklast(*stk);
	*stk = last;
	(*stk)->next = temp;
	second_last->next = NULL;
	ft_set_index(*stk);
}

//The last element of the stack a became the first.
void	ft_rra(t_stack **stk_a, int show)
{
	ft_reverse_rotate(stk_a);
	if (show)
		write(1, "rra\n", 4);
}

//The last element of the stack b became the first.
void	ft_rrb(t_stack **stk_b, int show)
{
	ft_reverse_rotate(stk_b);
	if (show)
		write(1, "rrb\n", 4);
}

//The last element of the stack a and b became the first.
void	ft_rrr(t_stack **stk_a, t_stack **stk_b, int show)
{
	ft_reverse_rotate(stk_a);
	ft_reverse_rotate(stk_b);
	if (show)
		write(1, "rrr\n", 4);
}
