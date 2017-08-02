/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 19:06:21 by lchety            #+#    #+#             */
/*   Updated: 2017/06/27 19:07:00 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_list	*precheck(t_list *data)
{
	char *str;

	if (!data)
		return (NULL);
	str = (char*)data->content;
	if (is_link(str))
		error("error : precheck link in room\n");
	if (is_com(str))
		error("error : commentary in cmd\n");
	if (!(check_coord(str)))
		error("error : bad coordinates\n");
	return (data);
}

t_list	*start_precheck(t_list *data)
{
	char	*str;
	int		length;

	length = 0;
	if (!data)
		return (NULL);
	str = (char*)data->content;
	if (is_link(str))
		error("error : link under ##start\n");
	if (is_com(str))
		error("error : commentary in ##start, try again\n");
	if (check_coord(str) == -1)
		error("error : bad coordinates\n");
	return (data);
}
