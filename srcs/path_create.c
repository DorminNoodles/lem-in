/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:20:49 by lchety            #+#    #+#             */
/*   Updated: 2017/08/24 16:16:03 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		set_score(t_dna *dna, t_node *cp)
{
	int score;

	score = 0;
	while (cp)
	{
		if (cp->score > score || cp->score < 0)
		{
			cp->num_path = dna->nb_path;
			cp->active = 0;
			cp->score = score;
		}
		cp = cp->parent;
		score++;
	}
}

int			path_length(t_dna *dna, t_node *cp)
{
	int i;

	i = 0;
	while (cp->name && ft_strcmp(cp->name, dna->start->name))
	{
		cp = cp->parent;
		i++;
	}
	return (i);
}

void	get_start_node(t_dna *dna, t_node *cp)
{
	if (!dna->start_node && is_start(dna, cp))
		dna->start_node = cp;
}

t_node		*get_next_node(t_dna *dna, t_node *node, int nb)
{
	int i;
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
	t_link *lst;
	int i;

	i = 0;
	lst = dna->link_lst;
	while (lst)
	{
		if (!ft_strcmp(lst->to, name))
		{
			i++;
			if (i == nb+1)
				return (lst->from);
		}
		if (!ft_strcmp(lst->from, name))
		{
			i++;
			if (i == nb+1)
				return (lst->to);
		}
		lst = lst->next;
	}
	return (NULL);
}

int		end_condition(t_dna *dna, t_node *cp)
{
	if (!ft_strcmp(cp->name, "1"))
		return (0);
	return (1);
}

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
			tmp->next = (t_node*)ft_memalloc(sizeof(t_node));
			tmp = tmp->next;
		}
		else
		{
			node_lst = (t_node*)ft_memalloc(sizeof(t_node));
			tmp = node_lst;

		}
		node_init(tmp, NULL);
		tmp->name = lst->name;
		is_end(dna, tmp);
		if (is_end(dna, tmp))
			dna->end_node = tmp;
		if (is_start(dna, tmp))
			dna->start_node = tmp;

		tmp->nb_lnk = cnt_lnk(dna, tmp->name);
		lst = lst->next;
	}

	return (node_lst);
}

void	create_tree(t_dna *dna)
{
	t_node *tree;
	t_node *lst;
	int i;

	i = 0;
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

void	get_lnk_in_lnk(t_dna *dna, t_node *node, t_node **tab, int *cnt_tab)
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

int		get_all_lnk_2(t_dna *dna, t_node **next_lnk)
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
	i = 0;
	ft_bzero(next_lnk, 32000);
	while (tab[i])
	{
		next_lnk[i] = tab[i];
		i++;
	}
	return (cnt_tab);
}

void	create_node_score_2(t_dna *dna)
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

t_node		*next_node_path(t_node *node)
{
	int i;
	t_node	*tmp;

	i = 0;
	tmp = NULL;
	while (i < node->nb_lnk)
	{
		if (node->lnk[i]->num_path == -1 && node->lnk[i]->active)
		{
			if (!tmp || tmp->score > node->lnk[i]->score)
				tmp = node->lnk[i];
		}
		i++;
	}
	return (tmp);
}

t_node		*next_node_path_new(t_node *node, int num_path)
{
	int i;

		// printf("NEXT NODE PATH NEW NAME >> %s score>%d  num_path> %d\n", node->name, node->score, node->num_path);

	i = 0;
	while (i < node->nb_lnk)
	{
		// printf(" %s child -> %s  score>> %d  num_path> %d\n", node->name, node->lnk[i]->name, node->lnk[i]->score, node->lnk[i]->num_path);
		if (node->lnk[i]->num_path == num_path && node->lnk[i]->score < node->score)
		{
			// printf("ta mere\n");
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

	// printf("NSN in => %s\n", node->name);
	//ne pas envoyer start bordel de merde il ne devrait meme pas avoir de score !


	while (i < node->nb_lnk)
	{
		if (node->lnk[i]->num_path == -1 &&
			node->lnk[i]->score == node->score - 1)
		{
			return (node->lnk[i]);
		}
		i++;
	}
	// printf("NSN out == %p\n", node);
	// printf("NSN out == %s\n", node->name);
	return (tmp);
}

// int		pathfinding(t_dna *dna, int nb)
// {
// 	// return (0);
// 	t_node	*node;
//
// 	node = dna->start_node;
//
// 	while (node && !is_end(dna, node))
// 	{
// 		printf("name node : %s\n", node->name);
// 		node = next_node_path(node);
//
// 		printf("node => %p\n", node);
// 		// if (node)
// 		// 	node->num_path = nb;
// 	}
// 	if (!node || !is_end(dna, node))
// 		return (0);
// 	else
// 		return (1);
// }

int		start_with_end(t_dna *dna)
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

int		pathfinding(t_dna *dna, int num)
{
	t_node	*node;
	int		length;

	length = 0;
	node = dna->start_node->lnk[num];
	// printf("ENTER pathfinding node == %s\n", node->name);

	if (!node->score)
		return (0);
	node->num_path = num;
	while (!is_end(dna, node))
	{
		node = next_shortest_node(node);
		if (!node)
			return  (0);
		is_end(dna, node) ? 0 : (node->num_path = num);
		is_end(dna, node) ? 0 : (node->active = 0);
	}
	return (1);
}
