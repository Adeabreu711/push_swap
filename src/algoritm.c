/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:56:34 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/24 21:25:14 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_stack_b(t_stack **stk_a, t_stack **stk_b)
{
	ft_pb(stk_a, stk_b);
	ft_pb(stk_a, stk_b);
}

int	ft_get_target_id(int nb, t_stack *stk)
{
	t_stack	*temp;
	t_stack	*best;

	temp = stk;
	best = temp;
	while (temp)
	{
		if (temp->nb < nb && temp->nb < best->nb)
			best = temp;
		else if (temp->nb > best->nb && best->nb > nb)
			best = temp;
		temp = temp->next;
	}
	return (best->id);
}
int	ft_count_rotates(int id, int len)
{
	int count;
	int dir;

	count = 0;
	dir = 1;
	if (id <= (len + 1)/ 2) // 3 <= 3
		dir *= -1;
	while (id > 1 && id < (len + 1))
	{
		printf("len : %d, median : %d\n", len, len / 2);
		printf ("id %d : r[ab], dir %d:\n", id, dir);
		count++;
		id += dir;
	}
	return (count);
}

int	ft_get_move_count(int id, int trg_id, int len, int trg_len)
{
	int	count;
	int	trg_count;

	count = ft_count_rotates(id, len);
	trg_count = ft_count_rotates(trg_id, trg_len);
	printf ("id[%d] : ra x%d, rb x%d\n", id, count, trg_count);
	if ((id < (len / 2) && trg_id < (trg_len / 2))
		|| ((id > len / 2) && trg_id > (trg_len / 2)))
	{
		if (trg_count > count)
			return (trg_count + 1);
		return (count + 1);
	}
	return (count + trg_count + 1);
}

t_stack	*ft_get_cheaper(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*cheaper;
	t_stack	*temp;
	int		trg_id;
	int		mv_count;
	int		len[2];

	len[0] = ft_stklen(*stk_a);
	len[1] = ft_stklen(*stk_b);
	temp = *stk_a;
	while (temp)
	{
		trg_id = ft_get_target_id(temp->nb, *stk_b);
		mv_count = ft_get_move_count(temp->id, trg_id, len[0], len[1]);

		printf("id[%d] : %d -> %d, moves : %d\n\n",temp->id, temp->nb, trg_id, mv_count);
		temp = temp->next;
	}
	return (cheaper);
}
