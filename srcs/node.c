/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:51:10 by lchety            #+#    #+#             */
/*   Updated: 2017/08/27 23:56:17 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_node		*create_node_lst(t_dna *dna)
{
	t_room	*lst;
	t_node	*node_lst;
	t_node	*tmp;

	lst = dna->room_lst;
	node_lst = NULL;
	while (lst)
	{
		if (node_lst)
		{
			if (!(tmp->next = (t_node*)ft_memalloc(sizeof(t_node))))
				error("error : malloc\n");
			tmp = tmp->next;
		}
		else
		{
			if (!(node_lst = (t_node*)ft_memalloc(sizeof(t_node))))
				error("error : malloc\n");
			tmp = node_lst;
		}
		node_init(dna, tmp, NULL, lst->name);
		lst = lst->next;
	}
	return (node_lst);
}
