/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:33:39 by lchety            #+#    #+#             */
/*   Updated: 2017/08/07 09:33:45 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	clean_null_path(t_dna *dna)
{
	int i;

	i = 0;
	while (i < dna->path->nb_lnk - 1)
	{
		if (!dna->path->lnk[i])
		{
			if (dna->path->lnk[i + 1])
			{
				dna->path->lnk[i] = dna->path->lnk[i + 1];
				dna->path->lnk[i + 1] = NULL;
				i--;
			}
		}
		i++;
	}
}

void	clean_path(t_dna *dna, t_node *node)
{
	t_node *tmp;

	while (!is_end(dna, node))
	{
		tmp = node;
		node = next_node_path(node);
		tmp->num_path = 0;
	}
	dna->nb_path--;
}

int		compare_room(t_dna *dna, t_node *node)
{
	t_node *tmp;

	tmp = dna->node_lst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, node->name) && tmp->active)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	activate_path(t_dna *dna, t_node *node)
{
	while (!is_end(dna, node))
	{
		node->active = 1;
		node = next_node_path(node);
	}
}

void	clean_useless_path(t_dna *dna)
{
	int i;
	int invalid;
	int nb_valid;

	i = 0;
	nb_valid = 1;
	invalid = 0;
	sort_node_by_score(dna);
	while (i < dna->path->nb_lnk)
	{
		if (dna->path->lnk[i])
		{
			if (check_path(dna, dna->path->lnk[i]))
				activate_path(dna, dna->path->lnk[i]);
			else
				clean_path(dna, dna->path->lnk[i]);
		}
		i++;
	}
}
