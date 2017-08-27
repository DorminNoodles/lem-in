/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:39:03 by lchety            #+#    #+#             */
/*   Updated: 2017/08/27 22:32:36 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		is_name(t_dna *dna, char *str)
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
