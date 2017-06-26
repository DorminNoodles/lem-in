/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:51:10 by lchety            #+#    #+#             */
/*   Updated: 2017/06/26 18:37:31 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		sort_node_by_score(t_dna *dna)
{
	t_node	*tmp;
	int		i;

	i = 0;
	clean_null_path(dna);
	while (i < dna->path->nb_chld - 1)
	{
		if (dna->path->next[i])
		{
			if (dna->path->next[i + 1])
			{
				if (dna->path->next[i + 1]->score < dna->path->next[i]->score)
				{
					tmp = dna->path->next[i];
					dna->path->next[i] = dna->path->next[i + 1];
					dna->path->next[i + 1] = tmp;
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
	while (i < node->nb_chld)
	{
		if (node->next[i])
		{
			if (node->next[i]->num_path == node->num_path)
				return (node->next[i]);
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
