/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:40:37 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/03 22:20:24 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "checker.h"


//Create a new instruction node.
t_chk	*ft_chknew(char *str)
{
	t_chk	*check;

	check = ft_calloc(1, sizeof(t_chk));
	if (!check)
		return (NULL);
	check->inst = str;
	check->next = NULL;
	return (check);
}

//Return the last node in the given stack.
t_chk	*ft_chklast(t_chk *check)
{
	t_chk	*last;

	if (!check)
		return (NULL);
	last = check;
	while (last->next)
		last = last->next;
	return (last);
}

//Add a new node at the end of the given stack.
void	ft_chk_add_back(t_chk **check, t_chk *new)
{
	if (!check)
		return ;
	if (!*check)
		*check = new;
	else
		ft_chklast(*check)->next = new;
}

void	ft_convert_inst(char *inst, t_stack **stk_a, t_stack **stk_b)
{
	if (inst == "pa\n")
		ft_pa(stk_a, stk_b, 0);
	else if (inst == "pb\n")
		ft_pb(stk_a, stk_b, 0);
	else if (inst == "ra\n")
		ft_ra(stk_a, 0);
	else if (inst == "rb\n")
		ft_rb(stk_b, 0);
	else if (inst == "rr\n")
		ft_rr(stk_a ,stk_b, 0);
	else if (inst == "rra\n")
		ft_rra(stk_a, 0);
	else if (inst == "rrb\n")
		ft_rrb(stk_b, 0);
	else if (inst == "rrr\n")
		ft_rrr(stk_a, stk_b, 0);
	else if (inst == "sa\n")
		ft_sa(stk_a, 0);
	else if (inst == "sb\n")
		ft_sb(stk_b, 0);
}
int main(int argc, char *argv[])
{
	t_chk *check;
	t_chk *temp;

	check = ft_chknew(ft_get_next_line(0));
	temp = check;
	while(temp->inst)
	{
		ft_chk_add_back(&check, ft_chknew(ft_get_next_line(0)));
		temp = temp->next;
	}
	temp = check;
	while(temp->next)
	{

		printf("inst : %s", temp->inst);
		temp = temp->next;
	}
	// printf("%s", check->inst);
	printf("test OK");
	// insts = ft_get_next_line(1);
}
