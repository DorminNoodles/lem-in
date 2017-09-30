/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:58:56 by lchety            #+#    #+#             */
/*   Updated: 2017/09/30 11:26:53 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
			error(dna, "Bad ants number\n");
		i++;
	}
	dna->nb_ants = ft_atoi(tmp);
	if (!dna->nb_ants || dna->nb_ants < 0)
		error(dna, "error : ants bad number\n");
	return (tmp_data);
}

void		free_data(t_list *data)
{
	if (data->next)
		free_data(data->next);
	ft_memdel(&data->content);
	ft_memdel((void**)&data);
}

int			parsing(t_dna *dna)
{
	t_list	*data;
	t_list	*tmp_data;

	if (!(data = open_file(dna)))
		error(dna, "error : echec open file\n");
	if (!(tmp_data = nb_ants(dna, data)))
		error(dna, "error : nb_ants\n");
	tmp_data = tmp_data->next;
	if (!(tmp_data = room(dna, tmp_data)))
		error(dna, "error : room\n");
	display_map(data, pars_link(dna, tmp_data));
	free_data(data);
	if (dna->link_lst)
		return (1);
	return (0);
}
