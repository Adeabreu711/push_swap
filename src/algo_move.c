/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:18:35 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 14:00:23 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Merge the ra/rb and rra/rrb instructions
//into rr/rrr (optimization).
int	ft_merge_instructions(int *rotation_a, int *rotation_b)
{
	int	rotation_mix;

	if ((*rotation_a >= 0 && *rotation_b <= 0)
		|| (*rotation_a <= 0 && *rotation_b >= 0))
		return (0);
	if (ft_abs(*rotation_b) < ft_abs(*rotation_a))
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
	return (rotation_mix);
}

//Apply the desired rotation depending on the
//given function tab and the rota sign and value.
void	ft_apply_rota(t_stack **stk, int rota, void (*f[2])(t_stack**, int))
{
	if (rota < 0)
		while (rota++ < 0)
			f[0](stk, 1);
	else
		while (rota-- > 0)
			f[1](stk, 1);
}

//Apply the desired rotation depending on the
//given function tab and the rota sign and value.
void	ft_apply_mixrota(t_stack **stk_a, t_stack **stk_b, int rota_mix)
{
	if (rota_mix < 0)
		while (rota_mix++ < 0)
			ft_rr(stk_a, stk_b, 1);
	else
		while (rota_mix-- > 0)
			ft_rrr(stk_a, stk_b, 1);
}

//Move the stack a value to the stack b on the top of the target.
void	ft_move_to_btrg(int id, int trg_id, t_stack **stk_a, t_stack **stk_b)
{
	int		rotation_a;
	int		rotation_b;
	int		rotation_mix;
	void	(*f[2])(t_stack**, int);

	rotation_a = ft_count_rotates(id, ft_stklen(*stk_a));
	rotation_b = ft_count_rotates(trg_id, ft_stklen(*stk_b));
	rotation_mix = ft_merge_instructions(&rotation_a, &rotation_b);
	ft_apply_mixrota(stk_a, stk_b, rotation_mix);
	f[0] = ft_ra;
	f[1] = ft_rra;
	ft_apply_rota(stk_a, rotation_a, f);
	f[0] = ft_rb;
	f[1] = ft_rrb;
	ft_apply_rota(stk_b, rotation_b, f);
	ft_pb(stk_a, stk_b, 1);
}

//Move the stack b value to the stack a on the top of the target.
void	ft_move_to_atrg(int id, int trg_id, t_stack **stk_a, t_stack **stk_b)
{
	int		rotation_a;
	int		rotation_b;
	int		rotation_mix;
	void	(*f[2])(t_stack**, int);

	rotation_b = ft_count_rotates(id, ft_stklen(*stk_b));
	rotation_a = ft_count_rotates(trg_id, ft_stklen(*stk_a));
	rotation_mix = ft_merge_instructions(&rotation_a, &rotation_b);
	ft_apply_mixrota(stk_a, stk_b, rotation_mix);
	f[0] = ft_rb;
	f[1] = ft_rrb;
	ft_apply_rota(stk_b, rotation_b, f);
	f[0] = ft_ra;
	f[1] = ft_rra;
	ft_apply_rota(stk_a, rotation_a, f);
	ft_pa(stk_a, stk_b, 1);
}
