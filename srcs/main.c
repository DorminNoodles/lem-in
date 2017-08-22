/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:58:44 by lchety            #+#    #+#             */
/*   Updated: 2017/08/22 19:11:40 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		stk_is_empty(int *stk, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		if (stk[i] > 0)
			return (0);
		i++;
	}
	return (1);
}

// void	drop_in_best(t_dna *dna, int *stk)
// {
// 	int	i;
// 	int	score;
// 	int best;
//
// 	score = -1;
// 	best = 0;
// 	i = 0;
// 	while (i < dna->path->nb_lnk)
// 	{
// 		// printf("ECTO child[%d]  :  %p\n", i, dna->path->next[i]);
// 		if (dna->path->next[i])
// 			printf("ACTIVE child[%d]  :  %d\n", i, dna->path->next[i]->active);
// 		if (dna->path->next[i] && dna->path->next[i]->active)
// 		{
// 			if (cost_of_path(dna, stk, i) < score || score == -1)
// 			{
// 				score = cost_of_path(dna, stk, i);
// 				best = i;
// 			}
// 		}
// 		i++;
// 	}
// 	stk[best]++;
// }

void	create_lst_ants(t_dna *dna)
{
	int i;

	i = 0;
	if (!(dna->lst_ants = ft_memalloc(sizeof(t_ants) * dna->nb_ants)))
		error("error : Malloc failed\n");
	init_lst_ants(dna);



	// while (i < dna->nb_ants)
	// {
	// 	if(!(dna->lst_ants[i] = ft_memalloc(sizeof(t_ants))))
	// 		error("error : Malloc failed\n");
	// }
}

void	start_to_end(t_dna *dna)
{
	int		i;
	char	*itoa;

	i = 0;
	while (i < dna->nb_ants)
	{
		ft_putchar('L');
		itoa = ft_itoa(i);
		ft_putstr(itoa);
		i++;
	}

}

int		main(int argc, char **argv)
{
	t_dna dna;
	int ret;
	int i;

	i = 0;
	ret = 0;

	// sleep(10);

	dna_init(&dna);
	if (argc != 2)
		error("usage: ./lem-in input_file\n");
	if (parsing(&dna, argv[1]))
	{
		create_lst_ants(&dna);

		if (!(dna.node_lst = create_node_lst(&dna)))
			error("error : create tree failed\n");

		create_tree(&dna);
		create_node_score_2(&dna);

		if (start_with_end(&dna))
		{
			start_to_end(&dna);
			printf("Soon\n");
			return (0);
		}

		while (i < dna.start_node->nb_lnk)
		{
			if (pathfinding(&dna, i))
			{
				dna.nb_path++;
				dna.start_node->lnk[i]->active = 1;
			}
			i++;
		}
		move_ants(&dna);
		// printf("Start_node : %p\n", dna.start_node);
		// printf("Start_node(path) : %p\n", dna.path);

		// move_ants(&dna);
		// dna_free(&dna);

	}
	else
		ft_putstr("ERROR\n");
	return (0);
}
