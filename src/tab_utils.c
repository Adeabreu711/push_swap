/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:27:42 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/17 16:58:00 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_merge_tab(char **dest, char **src)
{
	char	**new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new = ft_calloc(ft_tablen(dest) + ft_tablen(src) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (dest[++i])
		new[i] = dest[i];
	while (src[j])
		new[i++] = src[j++];
	new[i] = NULL;
	free(dest);
	return (new);
}

char	**ft_split_args(char **argv)
{
	char	**s_args;
	char	**split;
	int		i;

	i = 0;
	s_args = ft_calloc(1, sizeof(char *));
	if (!s_args)
		return (NULL);
	while (argv[++i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (NULL);
		s_args = ft_merge_tab(s_args, split);
		if (!s_args)
			return (NULL);
		free(split);
	}
	return (s_args);
}

char	**free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return (NULL);
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}
