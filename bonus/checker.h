/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:24:09 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/06 13:55:20 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct s_chk
{
	char			*inst;
	struct s_chk	*next;
}	t_chk;

//chk_utils

t_chk	*ft_chknew(char *str);
t_chk	*ft_chklast(t_chk *check);
void	ft_chk_add_back(t_chk **check, t_chk *new);
void	ft_chkclear(t_chk **check);

//process_insts

t_chk	*ft_get_insts(void);
int		ft_convert_inst(char *inst, t_stack **stk_a, t_stack **stk_b, int sh);
int		ft_apply_insts(t_chk **check, t_stack **stk_a, t_stack **stk_b, int sh);

#endif
