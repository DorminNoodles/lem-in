/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:32:04 by lchety            #+#    #+#             */
/*   Updated: 2017/08/22 18:08:55 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem-in.h"

// void	move_ants(t_dna *dna)
// {
// 	int		move;
// 	int		*stk;
// 	t_ants	*lst_ants;
//
// 	move = 1;
// 	if (!(stk = (int*)ft_memalloc(sizeof(int) * dna->path->nb_lnk)))
// 		error("error : malloc\n");
// 	dispatch_ants(dna, stk);
//
//
// 	lst_ants = create_lst_ants(dna, dna->nb_ants);
// 	push_ants(dna, stk, lst_ants);
// 	display(dna, lst_ants);
// 	while (ants_in_path(dna, lst_ants))
// 	{
// 		// ants_displace(dna, lst_ants);
// 		push_ants(dna, stk, lst_ants);
// 		display(dna, lst_ants);
// 	}
// 	if (stk)
// 		ft_memdel((void**)&stk);
// 	free_lst_ants(lst_ants);
// }

void	stk_drop(t_dna *dna, int *stk)
{
	int	score;
	int tmp;
	int	best;
	int	i;

	// score = dna->start_node->lnk[0]->score + stk[0];
	best = 0;
	i = 0;
	score = 2147483647;
	tmp = 0;
// printf("SCORE FIRST ==> %d\n", score);
// printf("TMP FIRST ==> %d\n", tmp);
	best = 0;

	// printf("Ants START\n");
	while (i < dna->start_node->nb_lnk)
	{
		if (dna->start_node->lnk[i]->active)
		{
			tmp = dna->start_node->lnk[i]->score + stk[i];
			// printf ("TMP === %d\n", tmp);
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
		// drop_in_best(dna, stk);
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

void	move_ants(t_dna *dna)
{
	int		move;
	int		i;
	int		stk[100];
	t_node	*tmp;

	i = 0;

	while (i < dna->nb_ants)
	{
		dna->lst_ants[i].pos = dna->start_node;
		i++;
	}

	ft_bzero(stk, 100);

	dispatch_ants(dna, stk);


	while (!all_in_end(dna))
	{
		push_ants(dna, stk);

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

		display(dna);
		// sleep(1);
	}

}
