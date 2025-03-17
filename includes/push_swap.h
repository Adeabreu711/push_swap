/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:58:29 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/17 16:35:13 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"../libft/includes/libft.h"

typedef struct s_stack
{
	int				nb;
	int				id;
	struct s_stack	*next;
}	t_stack;

int		ft_ps_parsing(t_stack **stk_a, char **argv);
void	ft_set_index(t_stack *stk);
void	ft_init_stack_b(t_stack **stk_a, t_stack **stk_b);

t_stack	*ft_get_cheap(t_stack **stk_a, t_stack **stk_b, int *trg_id, int to_b);
int		ft_count_rotates(int id, int len);
void	ft_sort(t_stack **stk_a, t_stack **stk_b);
int		ft_merge_instructions(int *rotation_a, int *rotation_b);
void	ft_sort_three(t_stack **stk);
void	ft_sort_two(t_stack **stk_a);
int		ft_check_sort(t_stack *stk);
t_stack	*ft_get_max(t_stack *stk);
void	ft_move_to_btrg(int id, int trg_id, t_stack **stk_a, t_stack **stk_b);
void	ft_move_to_atrg(int id, int trg_id, t_stack **stk_a, t_stack **stk_b);

int		ft_get_atrg_id(int nb, t_stack *stk_a);
int		ft_get_btrg_id(int nb, t_stack *stk_b);

//Instructions

void	ft_sa(t_stack **stk_a, int show);
void	ft_sb(t_stack **stk_b, int show);
void	ft_ss(t_stack **stk_a, t_stack **stk_b, int show);
void	ft_pa(t_stack **stk_a, t_stack **stk_b, int show);
void	ft_pb(t_stack **stk_a, t_stack **stk_b, int show);
void	ft_ra(t_stack **stk_a, int show);
void	ft_rb(t_stack **stk_b, int show);
void	ft_rr(t_stack **stk_a, t_stack **stk_b, int show);
void	ft_rra(t_stack **stk_a, int show);
void	ft_rrb(t_stack **stk_b, int show);
void	ft_rrr(t_stack **stk_a, t_stack **stk_b, int show);

//Stack utils

t_stack	*ft_stknew(int nbr);
int		ft_stklen(t_stack *stk);
t_stack	*ft_checklast(t_stack *stk);
void	ft_check_add_back(t_stack **stk, t_stack *new);
void	ft_stkclear(t_stack **stk);

//Tab utils

int		ft_tablen(char **tab);
char	**ft_merge_tab(char **dest, char **src);
char	**ft_split_args(char **argv);
char	**free_tab(char **tab);

#endif
