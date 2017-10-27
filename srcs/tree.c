/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 12:04:38 by lchety            #+#    #+#             */
/*   Updated: 2017/10/27 16:47:26 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	create_tree(t_dna *dna)
{
	t_node	*tmp;
	int		i;
	unsigned long nb_lnk;

	nb_lnk = 0;
	tmp = dna->node_lst;
	while (tmp)
	{
		i = 0;
		nb_lnk = (unsigned long)tmp->nb_lnk;
		if (!(tmp->lnk = (t_node**)ft_memalloc(sizeof(t_node*) * nb_lnk)))
			error(dna, "error : malloc\n");
		while (i < tmp->nb_lnk)
		{
			tmp->lnk[i] = get_next_node(dna, tmp, i);
			i++;
		}
		tmp = tmp->next;
	}
}
