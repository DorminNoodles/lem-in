/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:30:14 by lchety            #+#    #+#             */
/*   Updated: 2017/08/27 17:01:57 by lchety           ###   ########.fr       */
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
	free(node->name);
	free(node);
}

// void	dna_free(t_dna *dna)
// {
// 	free_node(dna->node_lst);
// 	if (dna->end)
// 	{
// 		ft_memdel((void**)&dna->end->name);
// 		ft_memdel((void**)&dna->end);
// 	}
// 	if (dna->start)
// 	{
// 		ft_memdel((void**)&dna->start->name);
// 		ft_memdel((void**)&dna->start);
// 	}
// 	if (dna->room_lst)
// 		free_room_lst(&dna->room_lst);
// 	if (dna->link_lst)
// 	{
// 		free_link_lst(dna->link_lst);
// 		dna->link_lst = NULL;
// 	}
// }

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
	free_room_lst(&dna->room_lst);
	free_link_lst(&dna->link_lst);
	free_lst_ants(&dna->lst_ants);
	// printf("%p\n",dna->room_lst);

}
