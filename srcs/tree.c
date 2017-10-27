/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 12:04:38 by lchety            #+#    #+#             */
/*   Updated: 2017/10/27 10:58:56 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	create_tree(t_dna *dna)
{
	t_node	*tmp;
	int		i;

	tmp = dna->node_lst;
	while (tmp)
	{
		i = 0;
		if (!(tmp->lnk = (t_node**)ft_memalloc(sizeof(t_node*) * tmp->nb_lnk)))
			error(dna, "error : malloc\n");
		while (i < tmp->nb_lnk)
		{
			tmp->lnk[i] = get_next_node(dna, tmp, i);
			i++;
		}
		tmp = tmp->next;
	}
}
