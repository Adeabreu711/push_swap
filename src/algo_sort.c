/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:19:37 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 19:00:43 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Push to value from the stack a to the top of the stack a.
void	ft_init_stack_b(t_stack **stk_a, t_stack **stk_b)
{
	ft_pb(stk_a, stk_b, 1);
	ft_pb(stk_a, stk_b, 1);
}

//Sort three values in two moves or less.
void	ft_sort_three(t_stack **stk_a)
{
	t_stack	*temp;
	t_stack	*max;

	if (!*stk_a || ft_stklen(*stk_a) != 3)
		return ;
	temp = *stk_a;
	max = ft_get_max(*stk_a);
	if (max->id == 1)
		ft_ra(stk_a, 1);
	else if (max->id == 2)
		ft_rra(stk_a, 1);
	if (!ft_check_sort(*stk_a))
		ft_sa(stk_a, 1);
}

//Sort two values in one move or less.
void	ft_sort_two(t_stack **stk_a)
{
	if (!*stk_a || !(*stk_a)->next)
		return ;
	if ((*stk_a)->nb > (*stk_a)->next->nb)
		ft_sa(stk_a, 1);
}

//Rotate until max value of the list is on top.
void	ft_rotate_max_to_top(t_stack **stk_a)
{
	t_stack	*max;
	int		len_a;
	void	(*f)(t_stack**, int);

	len_a = ft_stklen(*stk_a);
	max = ft_get_max(*stk_a);
	f = ft_ra;
	if (max->id > len_a / 2)
		f = ft_rra;
	while (max->id != len_a)
		f(stk_a, 1);
}

//Sort the stack a in ascending order.
void	ft_sort(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*cheaper;
	int		trg_id;
	int		len[2];

	len[0] = ft_stklen(*stk_a);
	len[1] = ft_stklen(*stk_b);
	trg_id = 0;
	while (len[0] > 3)
	{
		cheaper = ft_get_cheap(stk_a, stk_b, &trg_id, 1);
		ft_move_to_btrg(cheaper->id, trg_id, stk_a, stk_b);
		len[0]--;
		len[1]++;
	}
	ft_sort_three(stk_a);
	while (len[1] > 0)
	{
		cheaper = ft_get_cheap(stk_a, stk_b, &trg_id, 0);
		ft_move_to_atrg(cheaper->id, trg_id, stk_a, stk_b);
		len[1]--;
		len[0]++;
	}
	ft_rotate_max_to_top(stk_a);
}
