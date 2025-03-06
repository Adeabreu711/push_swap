/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_find_cheap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:56:34 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 14:00:43 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Return the given number target in the stack "nm".
int	ft_get_target_id(int nb, t_stack **stk_a, t_stack **stk_b, int to_b)
{
	if (to_b)
		return (ft_get_btrg_id(nb, *stk_b));
	return (ft_get_atrg_id(nb, *stk_a));
}

//Count the number of rotations to pass a number on top of the stack.
int	ft_count_rotates(int id, int len)
{
	int	count;
	int	dir;

	count = 0;
	dir = 1;
	if (id <= (len + 1) / 2)
		dir *= -1;
	while (id > 1 && id < (len + 1))
	{
		count += dir;
		id += dir;
	}
	return (count);
}

//Get the total amount of moves necessary to push a
//number on the top of the his target.
int	ft_mvcount(int id, int trg_id, int len, int trg_len)
{
	int	count;
	int	trg_count;
	int	mix_count;

	count = ft_count_rotates(id, len);
	trg_count = ft_count_rotates(trg_id, trg_len);
	mix_count = ft_merge_instructions(&count, &trg_count);
	return (ft_abs(count) + ft_abs(trg_count) + ft_abs(mix_count) + 1);
}

//Get the node of the value that cost less moves
//than the others to get push on top of his target.
//to_b : stack a target, else stack b target.
//to b || !to_b
t_stack	*ft_get_cheap(t_stack **stk_a, t_stack **stk_b, int *trg_id, int to_b)
{
	t_stack	*cheaper;
	int		mv_best;
	t_stack	*temp;
	int		mv_count;
	int		len[2];

	len[0] = ft_stklen(*stk_a);
	len[1] = ft_stklen(*stk_b);
	temp = *stk_a;
	if (!to_b)
		temp = *stk_b;
	mv_best = INT_MAX;
	while (temp)
	{
		*trg_id = ft_get_target_id(temp->nb, stk_a, stk_b, to_b);
		mv_count = ft_mvcount(temp->id, *trg_id, len[!to_b], len[to_b]);
		if (mv_count < mv_best)
		{
			mv_best = mv_count;
			cheaper = temp;
		}
		temp = temp->next;
	}
	*trg_id = ft_get_target_id(cheaper->nb, stk_a, stk_b, to_b);
	return (cheaper);
}
