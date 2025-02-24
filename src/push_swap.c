/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:56:44 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/24 21:04:48 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (!ft_ps_parsing(&stk_a, argc, argv))
		return(write(2, "Error\n", 6));
	ft_print_stack(stk_a, stk_b);
	ft_init_stack_b(&stk_a, &stk_b);
	ft_print_stack(stk_a, stk_b);
	printf("%i \n", ft_get_cheaper(&stk_a, &stk_b)->nb);
	printf("done\n");
	return (0);
}
