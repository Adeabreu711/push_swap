/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:33:47 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 17:33:22 by alde-abr         ###   ########.fr       */
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

//Free all the nodes of the given check.
void	ft_chkclear(t_chk **check)
{
	t_chk	*temp;

	while (*check)
	{
		temp = (*check)->next;
		if ((*check)->inst)
			free((*check)->inst);
		free(*check);
		*check = temp;
	}
	*check = NULL;
}
