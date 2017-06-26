/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:16:52 by lchety            #+#    #+#             */
/*   Updated: 2017/06/26 17:21:29 by lchety           ###   ########.fr       */
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
}

void	cp_init(t_node *cp, t_node *parent)
{
	cp->parent = parent;
	cp->score = -1;
	cp->nb_chld = 0;
	cp->next = NULL;
	cp->room_name = NULL;
	cp->num_path = 0;
	cp->active = 0;
	cp->joint = NULL;
}
