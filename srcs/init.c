/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:16:52 by lchety            #+#    #+#             */
/*   Updated: 2017/08/24 15:52:11 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	dna_init(t_dna *dna)
{
	dna->start = NULL;
	dna->end = NULL;
	dna->room_lst = NULL;
	dna->link_lst = NULL;
	dna->nb_ants = 0;
	dna->nb_path = 0;
	dna->path = NULL;
	dna->node_lst = NULL;
	dna->tmp_node_lst = NULL;
	dna->node_limits = 7;
	dna->start_node = NULL;
}

void	node_init(t_node *node, t_node *parent)
{
	node->next = NULL;
	node->score = 0;
	node->num_path = -1;
	node->active = 0;
}

void	init_lst_ants(t_dna *dna)
{
	int i;

	i = 0;
	while (i < dna->nb_ants)
	{
		dna->lst_ants[i].id = i;
		dna->lst_ants[i].pos = NULL;
		i++;
	}
}
