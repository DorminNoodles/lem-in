/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:30:14 by lchety            #+#    #+#             */
/*   Updated: 2017/06/26 18:35:29 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	free_lst_ants(t_ants *lst_ants)
{
	if (lst_ants->next)
		free_lst_ants(lst_ants->next);
	free(lst_ants);
}

void	free_one_node(t_node **n)
{
	ft_memdel((void**)&(*n)->room_name);
	ft_memdel((void**)n);
}

void	free_node(t_node *node)
{
	if (node->joint)
		free_node(node->joint);
	free(node->room_name);
	free(node->next);
	free(node);
}

void	dna_free(t_dna *dna)
{
	free_node(dna->node_lst);
	if (dna->end)
	{
		ft_memdel((void**)&dna->end->name);
		ft_memdel((void**)&dna->end);
	}
	if (dna->start)
	{
		ft_memdel((void**)&dna->start->name);
		ft_memdel((void**)&dna->start);
	}
	if (dna->room_lst)
		free_room_lst(&dna->room_lst);
	if (dna->link_lst)
	{
		free_link_lst(dna->link_lst);
		dna->link_lst = NULL;
	}
}
