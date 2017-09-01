/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:30:14 by lchety            #+#    #+#             */
/*   Updated: 2017/09/01 14:45:29 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	free_lst_ants(t_ants **lst)
{
	if ((*lst)->next)
		free_lst_ants(&(*lst)->next);
	ft_memdel((void**)lst);
}

void	free_one_node(t_node **n)
{
	ft_memdel((void**)&(*n)->next);
	ft_memdel((void**)&(*n)->name);
	ft_memdel((void**)n);
}

void	free_node(t_node *node)
{
	if (node->next)
		free_node(node->next);
	node->name = NULL;
	ft_memdel((void**)&node->lnk);
	free(node);
}

void	free_split(char **tab, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_memdel((void**)&tab[i]);
		i++;
	}
	ft_memdel((void**)&tab);
}

void	main_free(t_dna *dna)
{
	if (dna->room_lst)
		free_room_lst(&dna->room_lst);
	if (dna->link_lst)
		free_link_lst(&dna->link_lst);
	if (dna->lst_ants)
		free_lst_ants(&dna->lst_ants);
	if (dna->node_lst)
		free_node(dna->node_lst);
	if (dna->start)
	{
		ft_memdel((void**)&dna->start->name);
		ft_memdel((void**)&dna->start);
	}
	if (dna->end)
	{
		ft_memdel((void**)&dna->end->name);
		ft_memdel((void**)&dna->end);
	}
}
