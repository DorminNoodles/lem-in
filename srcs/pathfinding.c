/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 23:03:45 by lchety            #+#    #+#             */
/*   Updated: 2017/09/15 15:38:35 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			pathfinding(t_dna *dna, int num)
{
	t_node	*node;
	int		length;

	printf("num %d\n", num);
	length = 0;
	node = dna->start_node->lnk[num];
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
