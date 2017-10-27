/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:27:18 by lchety            #+#    #+#             */
/*   Updated: 2017/10/27 16:33:03 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
