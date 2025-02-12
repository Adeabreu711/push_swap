/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:16:40 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/11 15:27:30 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Swap the 2 first elements of the given stack.
static void	ft_swap(t_stack *stk)
{
	int	temp_nb;
	int	temp_id;

	if (!stk || !stk->next)
		return ;
	temp_nb = stk->nb;
	temp_id = stk->id;
	stk->nb = stk->next->nb;
	stk->id = stk->next->id;
	stk->next->nb = temp_nb;
	stk->next->id = temp_id;
}
//Swap the 2 first elements of the given stack a.
void	ft_sa(t_stack **stk_a)
{
	ft_swap(*stk_a);
	write(1, "sa\n", 3);
}
//Swap the 2 first elements of the given stack b.
void	ft_sb(t_stack **stk_b)
{
	ft_swap(*stk_b);
	write(1, "sb\n", 3);
}

//Swap the 2 first elements of the stack a and stack b.
void	ft_ss(t_stack **stk_a, t_stack **stk_b)
{
	ft_swap(*stk_a);
	ft_swap(*stk_b);
	write(1, "ss\n", 3);
}
