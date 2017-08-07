/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:36:04 by lchety            #+#    #+#             */
/*   Updated: 2017/08/07 09:33:07 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		is_end(t_dna *dna, t_node *cp)
{
	if (!ft_strcmp(cp->name, dna->end->name))
		return (1);
	return (0);
}

int		is_start(t_dna *dna, t_node *cp)
{
	// printf("Node -> %p\n", cp);
	if (!ft_strcmp(cp->name, dna->start->name))
		return (1);
	return (0);
}

int		repeat_room(t_node *cp)
{
	t_node *tmp;

	// printf("SEGFAULT1\n");
	tmp = cp->parent;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, cp->name))
			return (1);
		tmp = tmp->parent;
	}
	// printf("SEGFAULT2\n");
	return (0);
}

int		check_path(t_dna *dna, t_node *node)
{
	while (!is_end(dna, node))
	{
		if (compare_room(dna, node))
			return (0);
		node = next_node_path(node);
	}
	return (1);
}

int		cost_of_path(t_dna *dna, int *stk, int nb)
{
	int cost;

	cost = 0;
	if (!stk[nb])
		return (dna->path->lnk[nb]->score);
	else
		return (dna->path->lnk[nb]->score + stk[nb]);
	return (1);
}
