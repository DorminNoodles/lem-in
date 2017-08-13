/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:58:56 by lchety            #+#    #+#             */
/*   Updated: 2017/08/13 17:20:29 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			redundancy_link(t_dna *dna, char *str)
{
	char	*s1;
	char	*s2;
	t_link	*lst_link;

	lst_link = dna->link_lst;
	s1 = get_name(str, FROM);
	s2 = get_name(str, TO);
	while (lst_link)
	{
		if (!ft_strcmp(lst_link->from, s1) || !ft_strcmp(lst_link->from, s2))
		{
			if (!ft_strcmp(lst_link->to, s1) || !ft_strcmp(lst_link->to, s2))
			{
				ft_memdel((void**)&s1);
				ft_memdel((void**)&s2);
				return (1);
			}
		}
		lst_link = lst_link->next;
	}
	ft_memdel((void**)&s1);
	ft_memdel((void**)&s2);
	return (0);
}

int			redundancy_link_2(t_dna *dna, char *from, char *to)
{
	t_link	*lst_link;

	lst_link = dna->link_lst;
	while (lst_link)
	{
		if (!ft_strcmp(lst_link->from, from) || !ft_strcmp(lst_link->from, to))
		{
			if (!ft_strcmp(lst_link->to, from) || !ft_strcmp(lst_link->to, to))
				return (1);
		}
		lst_link = lst_link->next;
	}
	return (0);
}

void		add_roomlst(t_dna *dna, t_room *room)
{
	t_room *tmp;

	if (dna->room_lst)
	{
		tmp = dna->room_lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = room;
	}
	else
		dna->room_lst = room;
}

t_list		*nb_ants(t_dna *dna, t_list *data)
{
	int		i;
	char	*tmp;
	t_list	*tmp_data;

	i = 0;
	tmp_data = data;
	while (is_com((char*)tmp_data->content))
		tmp_data = tmp_data->next;
	tmp = (char*)tmp_data->content;
	while (tmp[i] && tmp[i] != 13)
	{
		if (!ft_isdigit(tmp[i]))
			error("Bad ants number\n");
		i++;
	}
	dna->nb_ants = ft_atoi(tmp);
	if (!dna->nb_ants || dna->nb_ants < 0)
		error("error : ants bad number\n");
	return (tmp_data);
}

void		free_data(t_list *data)
{
	if (data->next)
		free_data(data->next);
	ft_memdel(&data->content);
	ft_memdel((void**)&data);
}

int			parsing(t_dna *dna, char *filename)
{
	t_list	*data;
	t_list	*tmp_data;

	if (!(data = open_file(filename)))
		error("error : echec open file\n");
	if (!(tmp_data = nb_ants(dna, data)))
		error("error : nb_ants\n");
	tmp_data = tmp_data->next;
	if (!(tmp_data = room(dna, tmp_data)))
		error("error : room\n");
	pars_link(dna, tmp_data);
	free_data(data);
	if (dna->link_lst)
		return (1);
	return (0);
}
