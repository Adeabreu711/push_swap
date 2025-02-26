/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:18:35 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/26 21:20:26 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_merge_instructions(int *rotation_a, int *rotation_b)
{
	int rotation_mix;
	int	sign;

	//printf("before : rotation_a : %i, rotation_b : %i\n", *rotation_a, *rotation_b);
	if ((*rotation_a >= 0 && *rotation_b <= 0)
		|| (*rotation_a <= 0 && *rotation_b >= 0))
		return (0);
	sign = (*rotation_a > 0 * 2) - 1;
	if((*rotation_b * sign) < (*rotation_a * sign))
	{
		rotation_mix = *rotation_b;
		*rotation_b = 0;
		*rotation_a -= rotation_mix;
	}
	else
	{
		rotation_mix = *rotation_a;
		*rotation_a = 0;
		*rotation_b -= rotation_mix;
	}
	//printf("rotation_two : %i, rotation_a : %i, rotation_b : %i\n", rotation_mix, *rotation_a, *rotation_b);
	return (rotation_mix);
}

void	ft_apply_rota(t_stack **stk, int rota, void(*f[2])(t_stack**))
{
	if (rota < 0)
		while (rota++ < 0)
			f[0](stk);
	else
		while (rota-- > 0)
			f[1](stk);
}

void	ft_move_to_target(int id, int trg_id, t_stack **stk_a, t_stack **stk_b)
{
	int	rotation_a;
	int rotation_b;
	int	rotation_mix;
	void(*f[2])(t_stack**);

	rotation_a = ft_count_rotates(id, ft_stklen(*stk_a));
	rotation_b = ft_count_rotates(trg_id, ft_stklen(*stk_b));
	rotation_mix = ft_merge_instructions(&rotation_a, &rotation_b);
	printf("id[%i], trg_id[%i]\n", id, trg_id);
	if (rotation_mix < 0)
		while (rotation_mix++ < 0)
			ft_rr(stk_a, stk_b);
	else
		while (rotation_mix-- > 0)
			ft_rrr(stk_a, stk_b);
	f[0] = ft_ra;
	f[1] = ft_rra;
	ft_apply_rota(stk_a, rotation_a, f);
	f[0] = ft_rb;
	f[1] = ft_rrb;
	ft_apply_rota(stk_b, rotation_b, f);
	ft_pb(stk_a, stk_b);
	ft_print_stack(*stk_a, *stk_b);
}
