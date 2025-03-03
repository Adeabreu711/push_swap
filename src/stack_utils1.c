/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:11:32 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/03 23:04:31 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Create a new stack node.
t_stack	*ft_stknew(int nbr)
{
	t_stack	*stk;

	stk = ft_calloc(1, sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->nb = nbr;
	stk->id = -1;
	stk->next = NULL;
	return (stk);
}

//Return the total amount of nodes contained in the given stack.
int	ft_stklen(t_stack *stk)
{
	t_stack	*temp;
	int		len;

	if (!stk)
		return (0);
	len = 1;
	temp = stk;
	while (temp->next)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

//Return the last node in the given stack.
t_stack	*ft_checklast(t_stack *stk)
{
	t_stack	*last;

	if (!stk)
		return (NULL);
	last = stk;
	while (last->next)
		last = last->next;
	return (last);
}

//Add a new node at the end of the given stack.
void	ft_check_add_back(t_stack **stk, t_stack *new)
{
	if (!stk)
		return ;
	if (!*stk)
		*stk = new;
	else
		ft_checklast(*stk)->next = new;
}

//Free all the nodes of the given stack.
void	ft_stkclear(t_stack **stk)
{
	t_stack	*temp;

	while (*stk)
	{
		temp = (*stk)->next;
		free(*stk);
		*stk = temp;
	}
	*stk = NULL;
}
