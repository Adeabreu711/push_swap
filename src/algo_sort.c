/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:19:37 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/26 21:21:48 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_stack_b(t_stack **stk_a, t_stack **stk_b)
{
	ft_pb(stk_a, stk_b);
	ft_pb(stk_a, stk_b);
}
void	ft_sort_three(t_stack **stk)
{
	t_stack	*temp;
	t_stack *max;

	temp = *stk;
	max = ft_get_max(*stk);
	if (max->id == 1)
		ft_ra(stk);
	else if (max->id == 2)
		ft_rra(stk);
	if (!ft_check_sort(*stk))
		ft_sa(stk);
}

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
		cheaper = ft_get_cheaper(stk_a, stk_b, &trg_id);
		printf("cheaper : id[%i] %i\n triger id[%i]\n", cheaper->id, cheaper->nb, trg_id);
		ft_move_to_target(cheaper->id, trg_id, stk_a, stk_b);
		len[0]--;
		len[1]++;
	}
	ft_sort_three(stk_a);
	ft_print_stack(*stk_a, *stk_b);
}
