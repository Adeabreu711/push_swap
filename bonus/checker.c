/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:40:37 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/17 16:40:37 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "checker.h"

//Free all allocated structs, return 0.
int	ft_clear_all(t_chk **check, t_stack **stk_a, t_stack **stk_b)
{
	if (*check)
		ft_chkclear(check);
	if (*stk_a)
		ft_stkclear(stk_a);
	if (*stk_b)
		ft_stkclear(stk_b);
	return (0);
}

//Program : checker
int	main(int argc, char *argv[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_chk	*check;

	stk_a = NULL;
	stk_b = NULL;
	check = NULL;
	if (argc == 1)
		return (0);
	if (!ft_ps_parsing(&stk_a, argv))
	{
		write(2, "Error\n", 6);
		return (ft_clear_all(&check, &stk_a, &stk_b));
	}
	check = ft_get_insts();
	if (!check)
		return (ft_clear_all(&check, &stk_a, &stk_b));
	if (!ft_apply_insts(&check, &stk_a, &stk_b, 0))
		return (ft_clear_all(&check, &stk_a, &stk_b));
	if ((ft_check_sort(stk_a) && !stk_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_clear_all(&check, &stk_a, &stk_b);
	return (0);
}
