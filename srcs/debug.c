/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:32:28 by lchety            #+#    #+#             */
/*   Updated: 2017/08/14 17:26:53 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	debug_display_path(t_dna *dna, int num)
{
	t_node *fichtre;

	fichtre = dna->start_node;
	printf("       show path>> %s\n", fichtre->name);
	while (fichtre)
	{
		fichtre = next_node_path_new(fichtre, num);
		if (fichtre)
			printf(">> %s\n", fichtre->name);
	}
}

t_node	*next_node_path_by_num(t_node *node, int num)
{
	int i;

	i = 0;

	while (i < node->nb_lnk)
	{
		if (node->lnk[i]->num_path == num)
			return (node->lnk[i]);
		i++;
	}
	return (NULL);
}

void	display_all_child(t_node *node)
{
	int i;

	i = 0;
	while (i < node->nb_lnk)
	{
		printf("     child %d -> %s\n", i, node->lnk[i]->name);
		i++;
	}
}

void	debug_display_path_2(t_dna *dna, int num)
{
	t_node *fichtre;

	fichtre = dna->start_node;
	printf(">> %s\n", fichtre->name);
	while (fichtre)
	{
		printf("Pute\n");
		display_all_child(fichtre);
		fichtre = next_node_path_by_num(fichtre, num);
		if (fichtre)
			printf(">> %s\n", fichtre->name);
	}
}

void	debug_display_all(t_dna *dna)
{
	t_node *salade = dna->node_lst;
	//
	while (salade)
	{
		printf("name %s      score : %d    num_path : %d      active : %d\n\n", salade->name, salade->score, salade->num_path, salade->active);
		salade = salade->next;
	}
}
