/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:56:44 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/18 14:34:17 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Free all allocated structs, return 0.
int	ft_clear_all(t_stack **stk_a, t_stack **stk_b)
{
	if (*stk_a)
		ft_stkclear(stk_a);
	if (*stk_b)
		ft_stkclear(stk_b);
	return (0);
}

//Optimize sorting if number of elements match.
int	ft_short_sort(t_stack **stk_a, int len)
{
	if (ft_check_sort(*stk_a))
		return (1);
	if (len > 3)
		return (0);
	else if (len == 2)
		ft_sort_two(stk_a);
	else if (len == 3)
		ft_sort_three(stk_a);
	return (1);
}

//Program : push_swap.
int	main(int argc, char *argv[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	(void)argc;
	stk_a = NULL;
	stk_b = NULL;
	if (!ft_ps_parsing(&stk_a, argv))
	{
		write(2, "Error\n", 6);
		return (ft_clear_all(&stk_a, &stk_b));
	}
	if (!ft_short_sort(&stk_a, ft_stklen(stk_a)))
	{
		ft_init_stack_b(&stk_a, &stk_b);
		ft_sort(&stk_a, &stk_b);
	}
	return (ft_clear_all(&stk_a, &stk_b));
}
