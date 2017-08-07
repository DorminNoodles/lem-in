/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:20:10 by lchety            #+#    #+#             */
/*   Updated: 2017/08/07 09:32:41 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char		**get_chlds_name(t_dna *dna, const t_node *p)
{
	int		i;
	char	**tab;
	t_link	*tmp;

	tab = NULL;
	tmp = dna->link_lst;
	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (p->nb_lnk + 1))))
		error("error : malloc\n");
	while (tmp)
	{
		if (!ft_strcmp(tmp->from, p->name))
		{
			tab[i] = tmp->to;
			i++;
		}
		if (!ft_strcmp(tmp->to, p->name))
		{
			tab[i] = tmp->from;
			i++;
		}
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}

int			chld_exist(t_dna *dna, t_node *path)
{
	int i;
	int length;

	i = 0;
	length = cnt_lnk(dna, path->name);
	while (i < length)
	{
		if (path->lnk[i])
			return (1);
		i++;
	}
	return (0);
}

t_node		**set_child(t_node *cp)
{
	int		size;
	t_node	**next;

	size = cp->nb_lnk;
	if (!(next = (t_node**)malloc(sizeof(t_node*) * size)))
		error("error : malloc\n");
	return (next);
}

int			already_use(t_dna *dna)
{
	int i;

	i = 0;
	while (i < dna->nb_path)
		i++;
	return (0);
}

t_node		*best_chld(t_dna *dna, t_node *node)
{
	int		i;
	t_node	*best;

	i = 0;
	best = NULL;
	while (i < node->nb_lnk)
	{
		if (!best && node->lnk[i] && !already_use(dna))
			best = node->lnk[i];
		else if (best && node->lnk[i] && best->score > node->lnk[i]->score)
		{
			if (!already_use(dna))
				best = node->lnk[i];
		}
		i++;
	}
	return (best);
}
