/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_insts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:24:18 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 17:31:50 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "checker.h"

//Read all the instructions in the input entry and store
//them in a check struct.
t_chk	*ft_get_insts(void)
{
	t_chk	*check;
	t_chk	*temp;
	t_chk	*new;

	check = ft_chknew(ft_get_next_line(0));
	if (!check)
		return (NULL);
	temp = check;
	while (temp->inst)
	{
		new = ft_chknew(ft_get_next_line(0));
		if (!new)
			return (NULL);
		ft_chk_add_back(&check, new);
		temp = temp->next;
	}
	temp = check;
	while (temp->next)
		temp = temp->next;
	ft_get_next_line(-1);
	return (check);
}

//Apply the fonction equivalent to the given string *inst.
int	ft_convert_inst(char *inst, t_stack **stk_a, t_stack **stk_b, int sh)
{
	if (!ft_strncmp(inst, "pa\n", 3))
		ft_pa(stk_a, stk_b, sh);
	else if (!ft_strncmp(inst, "pb\n", 3))
		ft_pb(stk_a, stk_b, sh);
	else if (!ft_strncmp(inst, "ra\n", 3))
		ft_ra(stk_a, sh);
	else if (!ft_strncmp(inst, "rb\n", 3))
		ft_rb(stk_b, sh);
	else if (!ft_strncmp(inst, "rr\n", 3))
		ft_rr(stk_a, stk_b, sh);
	else if (!ft_strncmp(inst, "rra\n", 4))
		ft_rra(stk_a, sh);
	else if (!ft_strncmp(inst, "rrb\n", 4))
		ft_rrb(stk_b, sh);
	else if (!ft_strncmp(inst, "rrr\n", 4))
		ft_rrr(stk_a, stk_b, sh);
	else if (!ft_strncmp(inst, "sa\n", 3))
		ft_sa(stk_a, sh);
	else if (!ft_strncmp(inst, "sb\n", 3))
		ft_sb(stk_b, sh);
	else
		return (write(2, "Error\n", 6) * 0);
	return (1);
}

//Apply all instructions readed in chk.
int	ft_apply_insts(t_chk **check, t_stack **stk_a, t_stack **stk_b, int sh)
{
	t_chk	*temp;

	if (!*stk_a || !*check)
		return (1);
	temp = *check;
	while (temp->next)
	{
		if (!ft_convert_inst(temp->inst, stk_a, stk_b, sh))
			return (0);
		temp = temp->next;
	}
	return (1);
}
