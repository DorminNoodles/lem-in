/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:51:10 by lchety            #+#    #+#             */
/*   Updated: 2017/08/30 11:50:25 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_node		*create_node_lst(t_dna *dna)
{
	t_room	*lst;
	t_node	*node_lst;
	t_node	*tmp;

	lst = dna->room_lst;
	node_lst = NULL;
	while (lst)
	{
		if (node_lst)
		{
			if (!(tmp->next = (t_node*)ft_memalloc(sizeof(t_node))))
				error("error : malloc\n");
			tmp = tmp->next;
		}
		else
		{
			if (!(node_lst = (t_node*)ft_memalloc(sizeof(t_node))))
				error("error : malloc\n");
			tmp = node_lst;
		}
		node_init(dna, tmp, NULL, lst->name);
		lst = lst->next;
	}
	return (node_lst);
}

t_node		*next_shortest_node(t_node *node)
{
	int		i;
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

t_node		*next_node_path(t_node *node, int num_path)
{
	int i;

	i = 0;
	while (i < node->nb_lnk)
	{
		if (node->lnk[i]->num_path == num_path &&
			node->lnk[i]->score < node->score)
		{
			return (node->lnk[i]);
		}
		i++;
	}
	return (NULL);
}

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

void		create_node_score(t_dna *dna)
{
	t_node	*next_lnk[32000];
	int		i;
	int		j;
	int		ret;

	ret = 1;
	i = 2;
	ft_bzero(next_lnk, 32000);
	next_lnk[0] = dna->end_node;
	next_lnk[0]->score = 1;
	while (ret)
	{
		ret = get_all_lnk(dna, next_lnk);
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
