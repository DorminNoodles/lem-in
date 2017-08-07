/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:51:10 by lchety            #+#    #+#             */
/*   Updated: 2017/08/07 09:37:31 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		sort_node_by_score(t_dna *dna)
{
	t_node	*tmp;
	int		i;

	i = 0;
	clean_null_path(dna);
	while (i < dna->path->nb_lnk - 1)
	{
		if (dna->path->lnk[i])
		{
			if (dna->path->lnk[i + 1])
			{
				if (dna->path->lnk[i + 1]->score < dna->path->lnk[i]->score)
				{
					tmp = dna->path->lnk[i];
					dna->path->lnk[i] = dna->path->lnk[i + 1];
					dna->path->lnk[i + 1] = tmp;
					i -= 2;
				}
			}
		}
		i++;
		if (i < 0)
			i = 0;
	}
}

t_node		*next_node_path(t_node *node)
{
	int i;

	i = 0;
	while (i < node->nb_lnk)
	{
		if (node->lnk[i])
		{
			if (node->lnk[i]->num_path == node->num_path)
				return (node->lnk[i]);
		}
		i++;
	}
	return (NULL);
}

int			cnt_node_length(t_node *cp)
{
	int i;

	i = 0;
	while (cp)
	{
		i++;
		cp = cp->parent;
	}
	return (i);
}

void		add_node_lst(t_dna *dna, t_node *node)
{
	if (!dna->node_lst)
	{
		dna->node_lst = node;
		dna->tmp_node_lst = node;
	}
	else
	{
		while (dna->tmp_node_lst->next)
			dna->tmp_node_lst = dna->tmp_node_lst->next;
		dna->tmp_node_lst->next = node;
	}
}
