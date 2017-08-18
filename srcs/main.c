/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:58:44 by lchety            #+#    #+#             */
/*   Updated: 2017/08/18 14:13:00 by lchety           ###   ########.fr       */
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
	if (!(dna->lst_ants = ft_memalloc(sizeof(t_ants) * dna->nb_ants)))
		error("error : Malloc failed\n");
}

int		main(int argc, char **argv)
{
	t_dna dna;
	int ret;

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


		cnt_lnk(&dna, "end");

		printf("end parsing\n");

		create_node_score_2(&dna);
		// debug_display_all(&dna);

		// int ret = 0;

		// ret = pathfinding(&dna, 0);
		// printf("      RET = %d\n", ret);
		// ret = pathfinding(&dna, 1);
		// printf("      RET = %d\n", ret);
		// ret = pathfinding(&dna, 2);
		// printf("      RET = %d\n", ret);
		// ret = pathfinding(&dna, 3);
		// printf("      RET = %d\n", ret);

		//IF START-END or END-START move all in end

		if (start_with_end(&dna))
		{
			printf("Soon\n");
			return (0);
		}

		debug_display_all(&dna);


		printf("                               nb_path == %d\n", dna.nb_path);

		int i = 0;
		while (i < dna.start_node->nb_lnk)
		{
			printf("\nCALL PATHFINDING\n");
			if (pathfinding(&dna, dna.nb_path))
				dna.nb_path++;
			// printf("HAAAAAAAAAAAAAAAAAAAAAAA\n");
			i++;
		}
		if (i == 0)
		{
			error("error : no path\n");
		}


		// if (!i)
		// {
		// 	printf("A pas de chemin connard\n");
		// 	return (0);
		// }
		// debug_display_all(&dna);

		int f = 0;
		while (f < dna.nb_path)
		{
			debug_display_path(&dna, f);
			f++;
		}

		t_node *k;

		k = dna.end_node;

		printf("                         ton nom : %s  num : %d\n", k->lnk[0]->name, k->lnk[0]->num_path);
		printf("                         ton nom : %s  num : %d\n", k->lnk[1]->name, k->lnk[1]->num_path);
		printf("                         ton nom : %s  num : %d\n", k->lnk[2]->name, k->lnk[2]->num_path);
		//
		k = k->lnk[1];
		printf("--------------------\n");
		printf("                         ton nom : %s  num : %d\n", k->lnk[0]->name, k->lnk[0]->num_path);

		k = k->lnk[0];
		printf("--------------------\n");
		printf("                         ton nom : %s  num : %d\n", k->lnk[0]->name, k->lnk[0]->num_path);
		printf("                         ton nom : %s  num : %d\n", k->lnk[1]->name, k->lnk[1]->num_path);
		printf("                         ton nom : %s  num : %d\n", k->lnk[2]->name, k->lnk[2]->num_path);
		printf("                         ton nom : %s  num : %d\n", k->lnk[3]->name, k->lnk[3]->num_path);


		k = k->lnk[3];
		printf("--------------------\n");
		printf("                         ton nom : %s  num : %d\n", k->lnk[0]->name, k->lnk[0]->num_path);
		printf("                         ton nom : %s  num : %d\n", k->lnk[1]->name, k->lnk[1]->num_path);
		printf("                         ton nom : %s  num : %d  score : %d\n", k->lnk[2]->name, k->lnk[2]->num_path, k->lnk[2]->score);
		printf("                         ton nom : %s  num : %d  score : %d\n", k->lnk[3]->name, k->lnk[3]->num_path, k->lnk[3]->score);
		printf("                         ton nom : %s  num : %d  score : %d\n", k->lnk[4]->name, k->lnk[4]->num_path, k->lnk[4]->score);


		// move_ants(&dna);
		// ret = pathfinding(&dna, 3);
		// printf("      RET = %d\n", ret);
		// printf("%p\n", dna.start_node);

		// t_node *monky = best_node(dna.start_node);

		// printf("nb_lnk %d\n", dna.start_node->nb_lnk);

		// printf("best test %s\n", best_node(dna.start_node)->name);



		// pathfinding(&dna, 1);
		// while (pathfinding(&dna, i))
		// {
		// 	i++;
		// 	printf("FIND path\n");
		// }
		// debug_display_all(&dna);
		//
		// printf("\n\n    fichtre \n\n");
		//
		// debug_display_path_2(&dna, 1);


		// printf("Start_node : %p\n", dna.start_node);
		// printf("Start_node(path) : %p\n", dna.path);

		// move_ants(&dna);
		// dna_free(&dna);

	}
	else
		ft_putstr("ERROR\n");
	return (0);
}
