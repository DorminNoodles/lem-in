/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:36:04 by lchety            #+#    #+#             */
/*   Updated: 2017/06/06 16:36:04 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		is_end(t_dna *dna, t_node *cp)
{
	if (!ft_strcmp(cp->room_name, dna->end->name))
		return (1);
	return (0);
}

int		is_start(t_dna *dna, t_node *cp)
{
	if (!ft_strcmp(cp->room_name, dna->start->name))
		return (1);
	return (0);
}

int		repeat_room(t_node *cp)
{
	t_node *tmp;

	tmp = cp->parent;
	while (tmp)
	{
		if (!ft_strcmp(tmp->room_name, cp->room_name))
			return (1);
		tmp = tmp->parent;
	}
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
		return (dna->path->next[nb]->score);
	else
		return (dna->path->next[nb]->score + stk[nb]);
	return (1);
}
