/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:39:03 by lchety            #+#    #+#             */
/*   Updated: 2017/06/26 18:42:25 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		is_name_link(t_dna *dna, char *str)
{
	t_link	*lst_link;

	lst_link = dna->link_lst;
	while (lst_link)
	{
		if (!ft_strcmp(lst_link->from, str) || !ft_strcmp(lst_link->to, str))
			return (1);
		lst_link = lst_link->next;
	}
	return (0);
}

int		is_room_name(t_dna *dna, char *str)
{
	t_room	*tmp;

	tmp = dna->room_lst;
	if (str[ft_strlen(str) - 1] == 13)
		str[ft_strlen(str) - 1] = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, str))
			return (1);
		tmp = tmp->next;
	}
	if (dna->start->name && !ft_strcmp(dna->start->name, str))
		return (1);
	if (dna->end->name && !ft_strcmp(dna->end->name, str))
		return (1);
	return (0);
}

int		is_empty(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int		is_order(char *str)
{
	if (*str == '#' && *(str + 1) == '#')
		return (1);
	return (0);
}

int		is_link(char *str)
{
	while (*str)
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}
