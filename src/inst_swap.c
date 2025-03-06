/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:16:40 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 20:06:36 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Swap the 2 first elements of the given stack.
static int	ft_swap(t_stack *stk)
{
	int	temp_nb;

	if (!stk || !stk->next)
		return (0);
	temp_nb = stk->nb;
	stk->nb = stk->next->nb;
	stk->next->nb = temp_nb;
	ft_set_index(stk);
	return (1);
}

//Swap the 2 first elements of the given stack a.
void	ft_sa(t_stack **stk_a, int show)
{
	if (!ft_swap(*stk_a))
		return ;
	if (show)
		write(1, "sa\n", 3);
}

//Swap the 2 first elements of the given stack b.
void	ft_sb(t_stack **stk_b, int show)
{
	if (!ft_swap(*stk_b))
		return ;
	if (show)
		write(1, "sb\n", 3);
}

//Swap the 2 first elements of the stack a and stack b.
void	ft_ss(t_stack **stk_a, t_stack **stk_b, int show)
{
	if (!ft_swap(*stk_a) && !ft_swap(*stk_b))
		return ;
	if (show)
		write(1, "ss\n", 3);
}
