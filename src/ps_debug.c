/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:11:32 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/11 02:41:51 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include"../libft/includes/ft_printf.h"

void	ft_print_stack(t_stack *stk_a, t_stack *stk_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = stk_a;
	temp_b = stk_b;
	ft_printf("STACK A %10s STACK B\n\n", "");
	while (temp_a || temp_b)
	{
		if (temp_a)
		{
			ft_printf("id[%i]: %-12i", temp_a->id, temp_a->nb);
			temp_a = temp_a->next;
		}
		else
			ft_printf("%-19s","");
		if (temp_b)
		{
			ft_printf("id[%i]: %-12i", temp_b->id, temp_b->nb);
			temp_b = temp_b->next;
		}
		write(1,"\n",1);
	}
}
