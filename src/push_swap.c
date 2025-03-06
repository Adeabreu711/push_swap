/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:56:44 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 18:34:51 by alde-abr         ###   ########.fr       */
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

int	ft_short_sort(t_stack **stk_a, int argc)
{
	if (argc > 4)
		return (0);
	else if (argc == 3)
		ft_sort_two(stk_a);
	else if (argc == 4)
		ft_sort_three(stk_a);
	return (1);
}

//Program : push_swap
int	main(int argc, char *argv[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (!ft_ps_parsing(&stk_a, argc, argv))
	{
		write(2, "Error\n", 6);
		return (ft_clear_all(&stk_a, &stk_b));
	}
	if (argc != ft_stklen(stk_a) + 1)
		return (ft_clear_all(&stk_a, &stk_b));
	if (!ft_short_sort(&stk_a, argc))
	{
		ft_init_stack_b(&stk_a, &stk_b);
		ft_sort(&stk_a, &stk_b);
	}
	return (ft_clear_all(&stk_a, &stk_b));
}
