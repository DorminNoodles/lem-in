/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:50:26 by lchety            #+#    #+#             */
/*   Updated: 2017/09/02 11:21:55 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_link	*new_link(t_dna *dna)
{
	t_link	*lk;

	lk = (t_link*)malloc(sizeof(t_link));
	if (!lk)
		error(dna, "error : malloc\n");
	lk->next = NULL;
	lk->from = NULL;
	lk->to = NULL;
	return (lk);
}

char	*get_name(t_dna *dna, char *str, int flag)
{
	char **split;
	char *tmp;

	split = ft_strsplit(str, '-');
	if (!split)
		error(dna, "error : split error\n");
	if (flag == FROM)
	{
		if (!(tmp = ft_strnew(ft_strlen(split[0]))))
			error(dna, "error : malloc\n");
		ft_strcpy(tmp, split[0]);
		free_split(split, 2);
	}
	else
	{
		if (!(tmp = ft_strnew(ft_strlen(split[1]))))
			error(dna, "error : malloc\n");
		ft_strcpy(tmp, split[1]);
		free_split(split, 2);
	}
	return (tmp);
}

void	add_link(t_dna *dna, char *str)
{
	t_link *new;
	t_link *tmp;

	new = new_link(dna);
	new->from = get_name(dna, str, FROM);
	new->to = get_name(dna, str, TO);
	if (new->to[ft_strlen(new->to) - 1] == 13)
		new->to[ft_strlen(new->to) - 1] = 0;
	if (dna->link_lst)
	{
		tmp = dna->link_lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		dna->link_lst = new;
}

t_list	*pars_link(t_dna *dna, t_list *data)
{
	char *tmp;

	while (data)
	{
		tmp = (char*)data->content;
		if (!is_com(tmp) && !is_order(tmp))
		{
			if (!link_integrity(dna, tmp))
				return (data);
			add_link(dna, tmp);
		}
		data = data->next;
	}
	return (data);
}

int		cnt_lnk(t_dna *dna, const char *name)
{
	int		i;
	t_link	*tmp;

	i = 0;
	tmp = dna->link_lst;
	while (tmp)
	{
		if (tmp->from && !ft_strcmp(tmp->from, name))
			i++;
		else if (tmp->to && !ft_strcmp(tmp->to, name))
			i++;
		tmp = tmp->next;
	}
	return (i);
}
