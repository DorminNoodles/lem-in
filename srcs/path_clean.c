/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:33:39 by lchety            #+#    #+#             */
/*   Updated: 2017/08/27 20:07:56 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		compare_room(t_dna *dna, t_node *node)
{
	t_node *tmp;

	tmp = dna->node_lst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, node->name) && tmp->active)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
