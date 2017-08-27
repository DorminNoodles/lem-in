/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:42:15 by lchety            #+#    #+#             */
/*   Updated: 2017/08/27 13:44:36 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

// int		ants_in_path(t_dna *dna, t_ants *lst)
// {
// 	t_node *tmp;
// 	int i;
//
// 	i = 0;
// 	while (i < dna->nb_ants)
// 	{
// 		if (!lst->pos)
// 			return (1);
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (0);
// }

void	push_ants(t_dna *dna, int *stk)
{
	int		i;
	int		j;
	t_ants	*tmp;

	i = 0;
	j = 0;
	while (i < dna->start_node->nb_lnk)
	{
		if (dna->start_node->lnk[i]->active && stk[i] > 0)
		{
			j = 0;
			stk[i]--;
			while (j < dna->nb_ants)
			{
				if (is_start(dna, dna->lst_ants[j].pos))
				{
					dna->lst_ants[j].pos = dna->start_node->lnk[i];
					dna->lst_ants[j].active = 1;
					break;
				}
				j++;
			}
		}
		i++;
	}

	// int f = 0;
	// while (f < 10)
	// {
	// 	printf(">> %d\n", stk[f]);
	// 	f++;
	// }
}

// t_ants	*create_lst_ants(t_dna *dna, int nb)
// {
// 	int			i;
// 	t_ants		*lst;
// 	t_ants		*tmp;
//
// 	i = 1;
// 	if (!(lst = (t_ants*)ft_memalloc(sizeof(t_ants))))
// 		error("error : malloc\n");
// 	lst->next = NULL;
// 	lst->pos = dna->start_node;
// 	lst->id = 0;
// 	lst->active = 1;
//
// 	tmp = lst;
// 	while (i < nb)
// 	{
// 		if (!(tmp->next = (t_ants*)ft_memalloc(sizeof(t_ants))))
// 			error("error : malloc\n");
// 		tmp = tmp->next;
// 		tmp->next = NULL;
// 		tmp->id = i;
// 		tmp->pos = dna->start_node;
// 		tmp->active = 1;
// 		// tmp->pos = dna->path;
// 		i++;
// 	}
// 	return (lst);
// }

// void	ants_displace(t_dna *dna, t_ants *lst)
// {
// 	while (lst)
// 	{
// 		if ((t_node*)lst->pos)
// 		{
// 			if (!is_end(dna, (t_node*)lst->pos))
// 				lst->pos = next_node_path((t_node*)lst->pos);
// 			else
// 				lst->active = 0;
// 		}
// 		lst = lst->next;
// 	}
// }
