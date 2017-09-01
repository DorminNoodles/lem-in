/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 12:04:38 by lchety            #+#    #+#             */
/*   Updated: 2017/09/01 11:34:46 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	create_tree(t_dna *dna)
{
	t_node	*lst;
	int		i;

	lst = dna->node_lst;
	while (lst)
	{
		i = 0;
		if (!(lst->lnk = (t_node**)ft_memalloc(sizeof(t_node*) * lst->nb_lnk)))
			error("error : malloc\n");
		while (i < lst->nb_lnk)
		{
			lst->lnk[i] = get_next_node(dna, lst, i);
			i++;
		}
		lst = lst->next;
	}
}
