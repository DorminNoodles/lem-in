/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:32:04 by lchety            #+#    #+#             */
/*   Updated: 2017/08/27 22:31:14 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	stk_drop(t_dna *dna, int *stk)
{
	int	score;
	int tmp;
	int	best;
	int	i;

	best = 0;
	i = 0;
	score = 2147483647;
	tmp = 0;
	best = 0;
	while (i < dna->start_node->nb_lnk)
	{
		if (dna->start_node->lnk[i]->active)
		{
			tmp = dna->start_node->lnk[i]->score + stk[i];
			if (tmp < score)
			{
				score = tmp;
				best = i;
			}
		}
		i++;
	}
	stk[best]++;
}

void	dispatch_ants(t_dna *dna, int *stk)
{
	int	ants;

	ants = dna->nb_ants;
	while (ants)
	{
		stk_drop(dna, stk);
		ants--;
	}
}

int		all_in_end(t_dna *dna)
{
	int i;

	i = 0;
	while (i < dna->nb_ants)
	{
		if (!is_end(dna, dna->lst_ants[i].pos))
			return (0);
		i++;
	}
	return (1);
}

int		all_desactive(t_dna *dna)
{
	int i;

	i = 0;
	while (i < dna->nb_ants)
	{
		if (dna->lst_ants[i].active)
			return (0);
		i++;
	}
	return (1);
}

void	move_ants(t_dna *dna)
{
	int i;

	i = 0;
	while (i < dna->nb_ants)
	{
		if (!is_start(dna, dna->lst_ants[i].pos))
		{
			if (!is_end(dna, dna->lst_ants[i].pos))
			{
				dna->lst_ants[i].pos = next_node_path_new(dna->lst_ants[i].pos, dna->lst_ants[i].pos->num_path);
				if (!dna->lst_ants[i].pos)
				{
					dna->lst_ants[i].pos = dna->end_node;
				}
			}
				else
				dna->lst_ants[i].active = 0;
		}
		i++;
	}
}

void	move(t_dna *dna)
{
	int		move;
	int		i;
	int		stk[100];
	t_node	*tmp;

	i = 0;
	ft_bzero(stk, 100);
	dispatch_ants(dna, stk);
	push_ants(dna, stk);
	while (!all_desactive(dna))
	{
		display(dna);
		move_ants(dna);
		push_ants(dna, stk);
	}
}
