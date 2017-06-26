/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:20:49 by lchety            #+#    #+#             */
/*   Updated: 2017/06/26 18:38:10 by lchety           ###   ########.fr       */
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

void		add_node_lst(t_dna *dna, t_node *node)
{
	if (!dna->node_lst)
	{
		dna->node_lst = node;
		dna->tmp_node_lst = node;
	}
	else
	{
		while (dna->tmp_node_lst->joint)
			dna->tmp_node_lst = dna->tmp_node_lst->joint;
		dna->tmp_node_lst->joint = node;
	}
}

t_node		*set_cur_path(t_dna *dna, char *name, t_node *parent)
{
	t_node *cp;

	if (!(cp = (t_node*)malloc(sizeof(t_node))))
		error("error : malloc\n");
	cp_init(cp, parent);
	if (name)
	{
		if (!(cp->room_name = ft_strnew(ft_strlen(name))))
			error("error : strnew\n");
		ft_strcpy(cp->room_name, name);
	}
	else
	{
		if (!(cp->room_name = ft_strnew(ft_strlen(dna->start->name))))
			error("error : ft_strnew\n");
		ft_strcpy(cp->room_name, dna->start->name);
	}
	return (cp);
}

int		path_length(t_node *cp)
{
	int i;

	i = 0;
	while (ft_strcmp(cp->room_name, "start"))
	{
		cp = cp->parent;
		i++;
	}
	return (i);
}

t_node		*create_raw_path(t_dna *dna, char *name, t_node *parent)
{
	int		i;
	t_node	*cp;
	char	**chld_name;

	i = -1;
	cp = set_cur_path(dna, name, parent);
	if (is_end(dna, cp))
	{
		dna->nb_path++;
		set_score(dna, cp);
		add_node_lst(dna, cp);
		return (cp);
	}
	if (repeat_room(cp) || path_length(cp) > dna->node_limits)
	{
		free_one_node(&cp);
		return (NULL);
	}
	cp->nb_chld = cnt_lnk(dna, cp->room_name);
	chld_name = get_chlds_name(dna, cp);
	cp->next = set_child(cp);
	while (chld_name[++i])
		cp->next[i] = create_raw_path(dna, chld_name[i], cp);
	ft_memdel((void**)&chld_name);
	if (chld_exist(dna, cp))
	{
		add_node_lst(dna, cp);
		return (cp);
	}
	else
		free_one_node(&cp);
	return (NULL);
}
