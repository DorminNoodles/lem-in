/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:20:49 by lchety            #+#    #+#             */
/*   Updated: 2017/08/27 23:26:17 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_node		*get_next_node(t_dna *dna, t_node *node, int nb)
{
	int		i;
	char	*name;
	t_node	*lst;

	i = 0;
	name = get_next_lnk(dna, node->name, nb);
	if (!name)
		return (NULL);
	lst = dna->node_lst;
	while (lst)
	{
		if (!ft_strcmp(name, lst->name))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

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
	int i;
	t_node *tmp;

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

int			get_all_lnk_2(t_dna *dna, t_node **next_lnk)
{
	int i;
	int j;
	int cnt_tab;
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

void		create_node_score_2(t_dna *dna)
{
	t_node	*next_lnk[32000];
	int i;
	int j;
	int ret;

	ret = 1;
	i = 2;
	ft_bzero(next_lnk, 32000);
	next_lnk[0] = dna->end_node;
	next_lnk[0]->score = 1;

	while (ret)
	{
		ret = get_all_lnk_2(dna, next_lnk);
		j = 0;
		while (j < ret)
		{
			if (next_lnk[j])
				next_lnk[j]->score = i;
			j++;
		}
		i++;
	}
	dna->start_node->score = 0;
}

t_node		*next_node_path_new(t_node *node, int num_path)
{
	int i;

	i = 0;
	while (i < node->nb_lnk)
	{
		if (node->lnk[i]->num_path == num_path && node->lnk[i]->score < node->score)
		{
			return (node->lnk[i]);
		}
		i++;
	}
	return (NULL);
}

t_node		*next_shortest_node(t_node *node)
{
	int i;
	t_node	*tmp;

	i = 0;
	tmp = NULL;
	while (i < node->nb_lnk)
	{
		if (node->lnk[i]->num_path == -1 &&
			node->lnk[i]->score == node->score - 1)
		{
			return (node->lnk[i]);
		}
		i++;
	}
	return (tmp);
}

int			start_with_end(t_dna *dna)
{
	int i;

	i = 0;
	while (i < dna->start_node->nb_lnk)
	{
		if (is_end(dna, dna->start_node->lnk[i]))
			return (1);
		i++;
	}
	return (0);
}
