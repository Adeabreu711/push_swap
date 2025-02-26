/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:58:29 by alde-abr          #+#    #+#             */
/*   Updated: 2025/02/26 21:22:00 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include"../libft/includes/libft.h"

typedef struct s_stack
{
	int				nb;
	int				id;
	struct s_stack	*next;
}	t_stack;

int		ft_ps_parsing(t_stack **stk_a, int argc, char **argv);
void	ft_print_stack(t_stack *stk_a, t_stack *stk_b);
void	ft_set_index(t_stack *stk);
void	ft_init_stack_b(t_stack **stk_a, t_stack **stk_b);

t_stack	*ft_get_cheaper(t_stack **stk_a, t_stack **stk_b, int *out_trg_id);
int		ft_count_rotates(int id, int len);
void	ft_sort(t_stack **stk_a, t_stack **stk_b);
int		ft_merge_instructions(int *rotation_a, int *rotation_b);
void	ft_sort_three(t_stack **stk);
int		ft_check_sort(t_stack *stk);
t_stack	*ft_get_max(t_stack *stk);
void	ft_move_to_target(int id, int trg_id, t_stack **stk_a, t_stack **stk_b);

//Rules

void	ft_sa(t_stack **stk_a);
void	ft_sb(t_stack **stk_b);
void	ft_ss(t_stack **stk_a, t_stack **stk_b);
void	ft_pa(t_stack **stk_a, t_stack **stk_b);
void	ft_pb(t_stack **stk_a, t_stack **stk_b);
void	ft_ra(t_stack **stk_a);
void	ft_rb(t_stack **stk_a);
void	ft_rr(t_stack **stk_a, t_stack **stk_b);
void	ft_rra(t_stack **stk_a);
void	ft_rrb(t_stack **stk_b);
void	ft_rrr(t_stack **stk_a, t_stack **stk_b);

//Stack utils

t_stack	*ft_stknew(int nbr);
int		ft_stklen(t_stack *stk);
t_stack	*ft_stklast(t_stack *stk);
void	ft_stk_add_back(t_stack **stk, t_stack *new);
void	ft_stkclear(t_stack **stk);

#endif
