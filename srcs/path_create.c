/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:20:49 by lchety            #+#    #+#             */
/*   Updated: 2017/08/10 18:16:10 by lchety           ###   ########.fr       */
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

// t_node		*set_cur_path(t_dna *dna, char *name, t_node *parent)
// {
// 	t_node *cp;
//
// 	if (!(cp = (t_node*)ft_memalloc(sizeof(t_node))))
// 		error("error : malloc\n");
// 	cp_init(cp, parent);
// 	if (name)
// 	{
// 		if (!(cp->name = ft_strnew(ft_strlen(name))))
// 			error("error : strnew\n");
// 		ft_strcpy(cp->name, name);
// 	}
// 	else
// 	{
// 		if (!(cp->name = ft_strnew(ft_strlen(dna->start->name))))
// 			error("error : ft_strnew\n");
// 		ft_strcpy(cp->name, dna->start->name);
// 	}
// 	cp->nb_lnk = cnt_lnk(dna, cp->name);
// 	if (is_end(dna, cp))
// 		cp->nb_lnk = 0;
// 	else
// 		cp->next = set_child(cp);
// 	return (cp);
// }

// t_node		*set_cur_path(t_dna *dna, char *name, t_node *parent)
// {
// 	t_node *cp;
//
// 	if (!(cp = (t_node*)ft_memalloc(sizeof(t_node))))
// 		error("error : malloc\n");
// 	cp->name = name;
// 	cp->nb_lnk = cnt_lnk(dna, cp->name);
//
// 	// printf("cp->nb_lnk ==> %d\n", cp->nb_lnk);
//
// 	cp->next = (t_node**)ft_memalloc(sizeof(t_node*) * cp->nb_lnk);
//
//
//
// 	return (cp);
// }

int			path_length(t_dna *dna, t_node *cp)
{
	int i;

	i = 0;
	while (cp->name && ft_strcmp(cp->name, dna->start->name))
	{
		// printf("SEGFuck2\n");
		// printf("SEGFAULT > %p\n", cp->parent);
		cp = cp->parent;
		// printf("SEGFuck2,5\n");
		// printf("%p \n", cp);
		// printf("Prob\n");
		i++;
	}
	// printf("SEGFuck3\n");
	return (i);
}

int			raw_path_check_end(t_dna *dna, t_node *cp)
{
	if (is_end(dna, cp))
	{
		dna->nb_path++;
		set_score(dna, cp);
		add_node_lst(dna, cp);
		return (1);
	}
	return (0);
}

void	get_start_node(t_dna *dna, t_node *cp)
{
	if (!dna->start_node && is_start(dna, cp))
		dna->start_node = cp;
}

// t_node		*create_raw_path(t_dna *dna, char *name, t_node *parent)
// {
// 	// printf("CREATE_RAW_PATH\n");
// 	int		i;
// 	t_node	*cp;
// 	char	**chld_name;
//
// 	i = -1;
// 	cp = set_cur_path(dna, name, parent);
// 	get_start_node(dna, cp);
// 	if (raw_path_check_end(dna, cp))
// 		return (cp);
// 	// printf("SEGV\n");
// 	if (repeat_room(cp) || path_length(dna, cp) > dna->node_limits)
// 	{
// 		free_one_node(&cp);
// 		return (NULL);
// 	}
// 	chld_name = get_chlds_name(dna, cp);
// 	while (chld_name[++i])
// 		cp->next[i] = create_raw_path(dna, chld_name[i], cp);
// 	ft_memdel((void**)&chld_name);
// 	if (chld_exist(dna, cp))
// 	{
// 		add_node_lst(dna, cp);
// 		return (cp);
// 	}
// 	else
// 		free_one_node(&cp);
// 	return (NULL);
// }

t_node		*get_next_node(t_dna *dna, t_node *node, int nb)
{
	int i;
	char	*name;
	t_node	*lst;

	// printf("FUCK\n");

	i = 0;
	name = get_next_lnk(dna, node->name, nb);
	if (!name)
		return (NULL);
	// printf("name %p\n", name);
	lst = dna->node_lst;
	while (lst)
	{
		// printf ("name -> %s\n", name);
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

// t_node		*create_raw_path(t_dna *dna, char *name, t_node *parent)
// {
// 	// printf("CREATE_RAW_PATH\n");
// 	t_node	*cp;
// 	int i;
//
// 	i = 0;
//
// 	cp = set_cur_path(dna, name, parent);
//
// 	if (end_condition(dna, cp))
// 		return (NULL);
//
//
// 	//open childs
// 	while (i < cp->nb_lnk)
// 	{
// 		create_raw_path(dna, get_next_lnk(dna, cp->name, i), cp);
// 		// printf("lnk => %s\n", get_next_lnk(dna, cp->name, i));
// 		i++;
// 	}
//
// 	return (NULL);
// }

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
		// tmp = (t_node*)ft_memalloc(sizeof(t_node));
		// node_init(tmp, NULL);
		// tmp->name = lst->name;
		// //
		// if (node_lst)
		// {
		// 	printf("debug %s\n", lst->name);
		// 	node_lst->next = tmp;
		// 	node_lst = node_lst->next;
		// }
		// else
		// 	node_lst = tmp;
		// printf("ta mere %s\n", lst->name);
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

		while (i < cnt_lnk(dna, lst->name))
		{
			lst->lnk[i] = get_next_node(dna, lst, i);
			i++;
		}
		lst = lst->next;
	}
}

void	create_node_score(t_dna *dna, t_node *node, int score)
{
	int		i;
	t_node	*lnk;

	// printf("\n\n");
	// printf("START   %s\n", node->name);
	debug_display_all(dna);
	i = 0;

	lnk = NULL;

	if (score > 5)
		return;

	if (is_start(dna, node))
	{
		node->score = score;
		return;
	}
	if (score > node->score && node->score != -1)
		return;
	else
	{
		node->active = 1;
		node->score = score;
	}

	while ((lnk = get_next_node(dna, node, i)))
	{
		// printf("root : %s     open : %s\n", node->name, lnk->name);

		create_node_score(dna, lnk, score + 1);
		i++;
	}

	// printf("\n\n");
	// lnk = get_next_node(dna, node, i);
	// printf(">> %s\n", lnk->name);
	// lnk = get_next_node(dna, node, i+1);
	// printf(">> %s\n", lnk->name);
	// printf("create_node_score END\n\n");
}

int		get_all_lnk(t_dna *dna, t_node **next_lnk)
{
	t_node	*tmp[32000];
	int i;
	int cnt_nod;

	i = 0;
	cnt_nod = 0;
	ft_bzero(tmp, 32000);
	while (next_lnk[i])
	{
		int j = 0;

		while ((tmp[cnt_nod] = get_next_node(dna, next_lnk[i], j)))
		{
			printf("PAPA \"%s\" Node next => %s\n", next_lnk[i]->name,  tmp[cnt_nod]->name);
			j++;
			cnt_nod++;
		}
		// printf("fuck j i = %d   %s\n", i, next_lnk[i]->name);
		i++;
	}
	i = -1;
	ft_bzero(next_lnk, 32000);
	while (tmp[++i])
		next_lnk[i] = tmp[i];

	return (cnt_nod);
}

void	create_node_score_2(t_dna *dna)
{
	t_node	*next_lnk[32000];
	int i;

	i = 0;
	ft_bzero(next_lnk, 32000);
	next_lnk[0] = dna->end_node;

	while (i < 10)
	{
		int ret = 0;
		ret = get_all_lnk(dna, next_lnk);

		printf("RET = %d\n", ret);
		int g = 0;
		while (g < ret)
		{
			printf("next_lnk ta mere => %s\n", next_lnk[g]->name);
			g++;
		}
		printf("\n");
		//
		// int j = 0;
		// while (j < ret)
		// {
		// 	printf("LNK => %s\n", next_lnk[j]->name);
		// 	j++;
		// }
		i++;
	}
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

	i = 0;
	while (i < node->nb_lnk)
	{
		if (node->lnk[i]->num_path == num_path)
			return (node->lnk[i]);
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
		if (node->lnk[i]->num_path == -1 && node->lnk[i]->active)
		{
			if (!tmp || tmp->score > node->lnk[i]->score)
				tmp = node->lnk[i];
		}
		i++;
	}
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
	node = dna->start_node;

	// node = next_node_path(node);

	// printf("Hello -> %s score-> %d\n", node->name, node->score);


	while (!is_end(dna, node))
	{
		printf("while\n");
		// printf("cur node -> %s score=%d     next_node -> %s score=%d\n", node->name, node->score,  next_node_path(node)->name, next_node_path(node)->score);

		printf("node before => %s  num_path=> %d\n\n", node->name, node->num_path);

		node = next_shortest_node(node);
		printf("node %p\n", node);
		if (!node)
			return  (0);
		printf("node after %s, %d\n", node->name, node->active);

		printf("node after %s, active => %d, num_path => %d\n", node->name, node->active, node->num_path);
		// node->num_path = num;
		is_end(dna, node) ? 0 : (node->num_path = num);
		is_end(dna, node) ? 0 : (node->active = 0);
		printf("node after => %s\n", node->name);
	}
	return (1);
}
