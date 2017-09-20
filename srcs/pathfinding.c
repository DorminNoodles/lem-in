/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 23:03:45 by lchety            #+#    #+#             */
/*   Updated: 2017/09/20 11:26:25 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_node	*first_unused_node(t_dna *dna)
{
	int		i;
	t_node	*best;

	best = NULL;
	i = 0;
	while (i < dna->start_node->nb_lnk)
	{
		if (dna->start_node->lnk[i]->num_path == -1)
		{
			if (!best)
				best = dna->start_node->lnk[i];
			if (best && best->score > dna->start_node->lnk[i]->score)
				best = dna->start_node->lnk[i];
		}
		i++;
	}
	if (best)
		return (best);
	return (NULL);
}

int		pathfinding(t_dna *dna, int num, t_node *node)
{
	int		length;

	length = 0;
	if (!node->score)
		return (0);
	node->num_path = num;
	while (!is_end(dna, node))
	{
		node = next_shortest_node(node);
		if (!node)
			return (0);
		is_end(dna, node) ? 0 : (node->num_path = num);
		is_end(dna, node) ? 0 : (node->active = 0);
	}
	return (1);
}
