/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:42:15 by lchety            #+#    #+#             */
/*   Updated: 2017/07/27 14:39:20 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ants_in_path(t_dna *dna, t_ants *lst)
{
	t_node *tmp;
	int i;

	i = 0;
	while (i < dna->nb_ants)
	{
		if (!lst->pos)
			return (1);
		lst = lst->next;
		i++;
	}
	return (0);
}

void	dispatch_ants(t_dna *dna, int *stk)
{
	int	ants;

	ants = dna->nb_ants;
	while (ants)
	{
		drop_in_best(dna, stk);
		ants--;
	}
}

void	push_ants(t_dna *dna, int *stk, t_ants *lst_ants)
{
	int		i;
	t_ants	*tmp;
	i = 0;
	while (i < dna->path->nb_chld)
	{
		if (stk[i])
		{
			tmp = lst_ants;
			while (tmp->pos)
				tmp = tmp->next;
			tmp->pos = (void*)dna->path->next[i];
			stk[i]--;
		}
		i++;
	}
}

t_ants	*create_lst_ants(t_dna *dna, int nb)
{
	int			i;
	t_ants		*lst;
	t_ants		*tmp;

	i = 1;
	if (!(lst = (t_ants*)ft_memalloc(sizeof(t_ants))))
		error("error : malloc\n");
	lst->next = NULL;
	lst->pos = NULL;
	lst->id = 0;
	lst->active = 1;
	// lst->pos = dna->path;
	//printf("TEST > %s\n", dna->start_node->room_name);
	// lst->pos = dna->start_node;
	tmp = lst;
	while (i < nb)
	{
		if (!(tmp->next = (t_ants*)ft_memalloc(sizeof(t_ants))))
			error("error : malloc\n");
		tmp = tmp->next;
		tmp->next = NULL;
		tmp->id = i;
		tmp->pos = NULL;
		tmp->active = 1;
		// tmp->pos = dna->path;
		i++;
	}
	return (lst);
}

void	ants_displace(t_dna *dna, t_ants *lst)
{
	while (lst)
	{
		if ((t_node*)lst->pos)
		{
			if (!is_end(dna, (t_node*)lst->pos))
				lst->pos = next_node_path((t_node*)lst->pos);
			else
				lst->active = 0;
		}
		lst = lst->next;
	}
}
