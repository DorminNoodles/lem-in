/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 12:04:38 by lchety            #+#    #+#             */
/*   Updated: 2017/09/15 15:13:38 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	create_tree(t_dna *dna)
{
	t_node	*lst;
	int		i;

	lst = dna->node_lst;
	while (lst)
	{
		printf("Master : %s\n", lst->name);
		i = 0;
		if (!(lst->lnk = (t_node**)ft_memalloc(sizeof(t_node*) * lst->nb_lnk)))
			error(dna, "error : malloc\n");
		while (i < lst->nb_lnk)
		{
			printf("__> %s\n", get_next_node(dna, lst, i)->name);
			lst->lnk[i] = get_next_node(dna, lst, i);
			i++;
		}
		printf("\n\n");
		lst = lst->next;
	}
}
