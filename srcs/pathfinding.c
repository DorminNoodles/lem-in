/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 23:03:45 by lchety            #+#    #+#             */
/*   Updated: 2017/09/20 01:03:49 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_node	*first_unused_node(t_dna *dna)
{
	int i;
	t_node *best;

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
	{
		return (best);
	}
	return (NULL);
}

int			pathfinding(t_dna *dna, int num, t_node *node)
{
	int		length;

	length = 0;

//-------------------debug
	// printf("*******-> %s\n", next_shortest_node(dna->start_node)->name);

	// node = next_shortest_node(dna->start_node);

	// printf("%p\n", node);
	// printf("ta mere\n");

	// t_node *fck = NULL;

	// fck = first_unused_node(dna);
	// node = first_unused_node(dna);

	// printf("name first node => %s\n", fck->name);


//-------------------debug




	// node = dna->start_node->lnk[num]; // ici il faut commencer avec le plus faible score et pas juste le premier
	if (!node->score)
		return (0);
	node->num_path = num;
	// printf("*node -> %s\n", node->name);
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
