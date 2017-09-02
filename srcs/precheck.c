/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 19:06:21 by lchety            #+#    #+#             */
/*   Updated: 2017/09/02 11:21:55 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list	*precheck(t_dna *dna, t_list *data)
{
	char *str;

	if (!data)
		return (NULL);
	str = (char*)data->content;
	if (is_link(str))
		error(dna, "ERROR\n");
	if (is_com(str))
		error(dna, "ERROR\n");
	if (is_order(str))
		error(dna, "ERROR\n");
	if (!(check_coord(dna, str)))
		error(dna, "ERROR\n");
	return (data);
}

t_list	*start_precheck(t_dna *dna, t_list *data)
{
	char	*str;
	int		length;

	length = 0;
	if (!data)
		return (NULL);
	str = (char*)data->content;
	if (is_link(str))
		error(dna, "error : link under ##start\n");
	if (is_com(str))
		error(dna, "error : commentary in ##start, try again\n");
	if (check_coord(dna, str) == -1)
		error(dna, "error : bad coordinates\n");
	return (data);
}
