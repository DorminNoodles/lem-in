/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:32:04 by lchety            #+#    #+#             */
/*   Updated: 2017/08/27 13:20:23 by lchety           ###   ########.fr       */
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
	int		move;
	int		i;
	int		stk[100];
	t_node	*tmp;
	int		once;

	once = 1;
	i = 0;

	while (i < dna->nb_ants)
	{
		dna->lst_ants[i].pos = dna->start_node;
		i++;
	}
	ft_bzero(stk, 100);
	dispatch_ants(dna, stk);

	// printf("STK > %d\n", stk[0]);
	// printf("STK > %d\n", stk[1]);
	// printf("STK > %d\n", stk[2]);
	// printf("STK > %d\n", stk[3]);
	// printf("STK > %d\n", stk[4]);
	// printf("STK > %d\n", stk[5]);
	// printf("STK > %d\n", stk[6]);
	// printf("STK > %d\n", stk[7]);
	// printf("STK > %d\n", stk[8]);
	// printf("STK > %d\n", stk[9]);
	// printf("STK > %d\n", stk[10]);

	while (once || !all_desactive(dna))
	{
		push_ants(dna, stk);
		display(dna);
		i = 0;
		once = 0;
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
		// printf("FUCK %d  >  %s  > active %d\n", dna->lst_ants[1].id +1, dna->lst_ants[1].pos->name, dna->lst_ants[1].active);
	}
}
