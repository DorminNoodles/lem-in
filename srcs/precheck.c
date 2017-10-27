/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 19:06:21 by lchety            #+#    #+#             */
/*   Updated: 2017/10/27 16:36:55 by lchety           ###   ########.fr       */
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
