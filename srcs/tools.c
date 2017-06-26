/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:27:18 by lchety            #+#    #+#             */
/*   Updated: 2017/06/26 18:40:56 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		split_length(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		only_blank(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int		is_com(char *str)
{
	if (*str && *str == '#')
	{
		if (*(str + 1) && *(str + 1) == '#')
			return (0);
		return (1);
	}
	return (0);
}
