/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:20:49 by lchety            #+#    #+#             */
/*   Updated: 2017/08/07 18:19:44 by lchety           ###   ########.fr       */
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
		lst->lnk = (t_node**)ft_memalloc(sizeof(t_node*) * lst->nb_lnk);

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
	int i;
	t_node *lnk;

	printf("ta mere\n");
	i = 0;

	//printf("lst -> %p\n", dna->link_lst);

	// lnk = get_next_node(dna, node, i);
	// printf("LNK => %p\n", lnk);
	// lnk = get_next_node(dna, node, i+1);
	// printf("LNK => %p\n", lnk);
	// lnk = get_next_node(dna, node, i+2);
	// printf("LNK => %p\n", lnk);
	// lnk = get_next_node(dna, node, i+3);
	// printf("LNK => %p\n", lnk);


	while ((lnk = get_next_node(dna, node, i)))
	{

		// printf("Fuck\n");
		printf("LNK => %s\n", lnk->name);
		i++;
	}

	// printf(">> %s\n", dna->end_node->name);
	// while ((lnk = get_next_node(dna, node->name, i)))
	// {
	// 	// printf("lnk => %s\n", lnk->name);
	// 	i++;
	// }

	// lnk = get_next_node(dna, node, i);
	// printf(">> %s\n", lnk->name);
	// lnk = get_next_node(dna, node, i+1);
	// printf(">> %s\n", lnk->name);


	// if (lnk)
	// 	printf("lnk exist\n");
	// else
	// 	printf("NOoooo\n");


	// get_next_node(dna, node, i);

	// while ((lnk = get_next_node(dna, node, i)))
	// {
	// 	// printf ("> %s\n", lnk->name);
	// 	i++;
	// }
	printf("create_node_score END\n");
}
