/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:32:04 by lchety            #+#    #+#             */
/*   Updated: 2017/08/17 15:31:39 by lchety           ###   ########.fr       */
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
	int	best;
	int	i;

	score = dna->start_node->lnk[0]->score;
	best = 0;
	i = 1;

	printf("            SCORE : %d\n", score);

	//tester dans chaque chemin si le total est plus ou moins grand
	//avec a chaque fois un score de +1 si le chemin est deja utilise
	//et un score de tous le chemin sinon
	//en fait non....
	// si j ai deux chemin de score 6
	// et deux fourmis
	//si j envoi la premiere fourmi dans le premier chemin j ai un score total
	// de 6
	// si je l envoi dans le deuxieme j ai un score de 6
	//donc je l envoi dans le premier
	//maintenant si je met la 2 eme fourmi dans le premier chemin le score total
	//passe a nb fourmi - 1 + score du chemin donc 6 + (2-1) = 7
	//si je la place dans le second qui n est pas utilise a la base
	// j obtiens un score de 6
	//en fait le score total est juste le chemin qui a le score le plus grand
	//du coup je dois verifier si mettre ma fourmi dans un autre chemin est
	//plus petit ou egale au score du chemin avec le plus grand score
	//(surement le premier ?)


	while (i < dna->nb_path && i < 100)
	{
		if (dna->start_node->lnk[i]->num_path != -1)
		{
			if (stk[i])
			{
				// score = dna->start_node->lnk[i]->score;
				score = stk[i] + 1;
			}
			else
			{
				score = dna->start_node->lnk[i]->score;

			}
		}
		i++;
	}

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

void	move_ants(t_dna *dna)
{
	int		move;
	// int		*stk;
	int		stk[100];
	t_ants	*lst_ants;

	ft_bzero(stk, 100);

	dispatch_ants(dna, stk);







}
