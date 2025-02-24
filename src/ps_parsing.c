/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:44:26 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/24 13:52:32 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Return a long corresponding to the given int in the given string nptr,
//return INT_MIN - 1 if nptr isn't a strict int.
static long	ft_atoi_strict(const char *nptr)
{
	int		i;
	long	temp;
	int		sign;

	i = 0;
	temp = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -sign;
	while (nptr[i] >= '0' && nptr[i] <= '9' && (temp > INT_MIN && temp < INT_MAX))
		temp = (temp * 10) + (nptr[i++] - '0');
	if ((i < 2 && !ft_isdigit(nptr[0])) || nptr[i])
		return ((long)INT_MIN - 1);
	return (temp * sign);
}

//Check if the stack a doesn't contain two equal value.
int	ft_check_duplicate(t_stack *stk_a)
{
	t_stack	*value;
	t_stack	*temp;

	value = stk_a;
	while (value)
	{
		temp = value->next;
		while (temp)
		{
			if (temp->nb == value->nb)
				return (0);
			temp = temp->next;
		}
		value = value->next;
	}
	return (1);
}

//Set the index of the elements of the given stack in order.
void	ft_set_index(t_stack *stk)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = stk;
	while (temp)
	{
		temp->id = i;
		temp = temp->next;
		i++;
	}
}

// Read the given arguments and assign them to stack A.
// [Return: 0] if an argument is not an integer or if its identical to another.
int	ft_ps_parsing(t_stack **stk_a, int argc, char **argv)
{
	int		i;
	long	nb;

	if (argc < 3)
		return (0);
	i = 0;
	while (++i < argc)
	{
		nb = ft_atoi_strict(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		if (i == 1)
			*stk_a = ft_stknew(nb);
		else
			ft_stk_add_back(stk_a, ft_stknew(nb));
	}
	if (!ft_check_duplicate(*stk_a))
		return (0);
	ft_set_index(*stk_a);
	return (1);
}

