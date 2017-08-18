/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:20:49 by lchety            #+#    #+#             */
/*   Updated: 2017/08/18 13:53:54 by lchety           ###   ########.fr       */
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

	i = 0;
	name = get_next_lnk(dna, node->name, nb);
	if (!name)
		return (NULL);
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

		while (i < lst->nb_lnk)
		{
			lst->lnk[i] = get_next_node(dna, lst, i);
			i++;
		}
		lst = lst->next;
	}
}
//
// void	create_node_score(t_dna *dna, t_node *node, int score)
// {
// 	int		i;
// 	t_node	*lnk;
//
// 	// printf("\n\n");
// 	// printf("START   %s\n", node->name);
// 	debug_display_all(dna);
// 	i = 0;
//
// 	lnk = NULL;
//
// 	if (score > 5)
// 		return;
//
// 	if (is_start(dna, node))
// 	{
// 		node->score = score;
// 		return;
// 	}
// 	if (score > node->score && node->score != -1)
// 		return;
// 	else
// 	{
// 		node->active = 1;
// 		node->score = score;
// 	}
//
// 	while ((lnk = get_next_node(dna, node, i)))
// 	{
// 		// printf("root : %s     open : %s\n", node->name, lnk->name);
//
// 		create_node_score(dna, lnk, score + 1);
// 		i++;
// 	}
// }

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

	// printf("22222 > name == %s\n", (*next_lnk[0]).name);

	while (next_lnk[i])
	{
		// printf("fuck lnk 2\n");

		get_lnk_in_lnk(dna, next_lnk[i], tab, &cnt_tab);

		i++;
	}
	i = 0;
	ft_bzero(next_lnk, 32000);
	while (tab[i])
	{
		// printf("GAL2 Name > %s\n", tab[i]->name);
		next_lnk[i] = tab[i];
		i++;
	}
	return (cnt_tab);
}

// int		get_all_lnk(t_dna *dna, t_node **next_lnk)
// {
// 	t_node	*tmp[32000];
// 	int i;
// 	int j;
// 	int cnt_nod;
//
// 	i = 0;
// 	cnt_nod = 0;
// 	ft_bzero(tmp, 32000);
// 	while (next_lnk[i])
// 	{
// 		j = 0;
//
// 		while ((tmp[cnt_nod] = get_next_node(dna, next_lnk[i], j)))
// 		{
// 			printf("PAPA \"%s\" Node next => %s\n", next_lnk[i]->name,  tmp[cnt_nod]->name);
// 			if (tmp[cnt_nod]->score != 0)
// 				tmp[cnt_nod] = 0;
//
// 			j++;
// 			cnt_nod++;
// 		}
// 		// printf("fuck j i = %d   %s\n", i, next_lnk[i]->name);
// 		i++;
// 	}
// 	i = -1;
// 	ft_bzero(next_lnk, 32000);
// 	while (tmp[++i])
// 		next_lnk[i] = tmp[i];
// 	return (cnt_nod);
// }

void	create_node_score_2(t_dna *dna)
{
	t_node	*next_lnk[32000];
	int i;
	int ret;

	ret = 1;
	i = 2;
	ft_bzero(next_lnk, 32000);
	next_lnk[0] = dna->end_node;
	next_lnk[0]->score = 1;

	while (ret)
	{
		ret = get_all_lnk_2(dna, next_lnk);
		// ret = get_all_lnk(dna, next_lnk);
		printf("RET = %d\n", ret);
		int k = 0;
		while (next_lnk[k])
		{
			// printf("                 pikmin %s\n", next_lnk[k]->name);
			k++;
		}

		int g = 0;
		while (g < ret)
		{
			if (next_lnk[g])
				next_lnk[g]->score = i;
			g++;
		}
		printf("\n\n\n");
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

	printf("NEXT NODE PATH NEW NAME >> %s score>%d  num_path> %d\n", node->name, node->score, node->num_path);

	i = 0;
	while (i < node->nb_lnk)
	{
		printf(" %s child -> %s  score>> %d  num_path> %d\n", node->name, node->lnk[i]->name, node->lnk[i]->score, node->lnk[i]->num_path);
		if (node->lnk[i]->num_path == num_path && node->lnk[i]->score < node->score)
		{
			printf("ta mere\n");
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

	printf("NSN in => %s\n", node->name);
	//ne pas envoyer start bordel de merde il ne devrait meme pas avoir de score !


	while (i < node->nb_lnk)
	{
		// if (!ft_strcmp(node->lnk[i]->name, "12"))
		// {
		// 	printf(">>>> %s\n", node->lnk[i]->name);
		// 	printf(">>>> %d\n", node->lnk[i]->num_path);
		// 	printf(">>>> %d\n", node->lnk[i]->score - 1);
		// 	printf(">>>> %d\n", node->score);
		// }
		printf(">>>> %s\n", node->lnk[i]->name);

		if (node->lnk[i]->num_path == - 1 &&
			node->lnk[i]->score == node->score - 1)
		{
			return (node->lnk[i]);
		}
		i++;
	}
	printf("NSN out == %p\n", node);
	printf("NSN out == %s\n", node->name);
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
	printf("ENTER pathfinding node == %s\n", node->name);

	if (!node->score)
		return (0);
	node->num_path = num;

	// printf("TESTHAHAHAHAHA ELKGJNROGHN %s\n", node->name);
	// node = next_node_path(node);
	// printf("SEGV1\n");
	while (!is_end(dna, node))
	{
		// printf("node name %s\n", node->name);
		// printf("HIGHWAY\n");
		// printf("node name %s\n", node->name);
		node = next_shortest_node(node);
		// printf("NEXT->NODE %s\n", node->name);
		// printf("SEGV1_2\n");
		if (!node)
			return  (0);
		printf("NSN out => %s\n\n", node->name);
		// printf("node after %s, %d\n", node->name, node->active);

		// printf("node after %s, active => %d, num_path => %d\n", node->name, node->active, node->num_path);
		// node->num_path = num;
		is_end(dna, node) ? 0 : (node->num_path = num);
		is_end(dna, node) ? 0 : (node->active = 0);
	}
	return (1);
}
