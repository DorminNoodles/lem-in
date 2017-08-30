/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:20:49 by lchety            #+#    #+#             */
/*   Updated: 2017/08/30 11:51:07 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char		*get_next_lnk(t_dna *dna, char *name, int nb)
{
	t_link	*lst;
	int		i;

	i = 0;
	lst = dna->link_lst;
	while (lst)
	{
		if (!ft_strcmp(lst->to, name))
		{
			i++;
			if (i == nb + 1)
				return (lst->from);
		}
		if (!ft_strcmp(lst->from, name))
		{
			i++;
			if (i == nb + 1)
				return (lst->to);
		}
		lst = lst->next;
	}
	return (NULL);
}

void		get_lnk_in_lnk(t_dna *dna, t_node *node, t_node **tab, int *cnt_tab)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = NULL;
	while ((tmp = get_next_node(dna, node, i)))
	{
		if (tmp->score == 0)
		{
			tab[*cnt_tab] = tmp;
			(*cnt_tab)++;
		}
		i++;
	}
}

int			get_all_lnk(t_dna *dna, t_node **next_lnk)
{
	int		i;
	int		j;
	int		cnt_tab;
	t_node	*tmp;
	t_node	*tab[32000];

	i = 0;
	cnt_tab = 0;
	tmp = NULL;
	ft_bzero(tab, 32000);
	while (next_lnk[i])
	{
		get_lnk_in_lnk(dna, next_lnk[i], tab, &cnt_tab);
		i++;
	}
	ft_bzero(next_lnk, 32000);
	i = 0;
	while (tab[i])
	{
		next_lnk[i] = tab[i];
		i++;
	}
	return (cnt_tab);
}

int			start_with_end(t_dna *dna)
{
	int i;

	i = 0;
	while (i < dna->start_node->nb_lnk)
	{
		if (is_end(dna, dna->start_node->lnk[i]))
		{
			start_to_end(dna);
			return (1);
		}
		i++;
	}
	return (0);
}

int			create_path(t_dna *dna)
{
	int i;

	i = 0;
	if (!(dna->node_lst = create_node_lst(dna)))
		error("error : create tree failed\n");
	create_tree(dna);
	create_node_score(dna);
	while (i < dna->start_node->nb_lnk)
	{
		if (pathfinding(dna, i))
		{
			dna->nb_path++;
			dna->start_node->lnk[i]->active = 1;
		}
		i++;
	}
	return (1);
}
