/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:58:44 by lchety            #+#    #+#             */
/*   Updated: 2017/08/10 18:15:28 by lchety           ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_dna dna;

	dna_init(&dna);
	if (argc != 2)
		error("usage: ./lem-in input_file\n");
	if (parsing(&dna, argv[1]))
	{
		t_link *pouet;

		pouet = dna.link_lst;
		while (pouet)
		{
			// printf("linkou => %s   => %s\n", pouet->from, pouet->to);
			// printf("next => %p\n", pouet->next);
			pouet = pouet->next;
		}
		// t_link *fuck = dna.link_lst;
		// while (fuck)
		// {
		// 	printf("lnk => %s-%s\n", fuck->from, fuck->to);
		// 	fuck = fuck->next;
		// }
		// while (!(dna.path = create_raw_path(&dna, NULL, NULL)))
		// {
		// 	printf("BORDEL DE MERDE\n");
		// 	if (dna.node_limits < 30)
		// 		dna.node_limits++;
		// 	else
		// 		break ;
		// }
		//
		// if (!dna.nb_path)
		// 	error("error : no path\n");
		// clean_useless_path(&dna);
		// display_path_debug(&dna);
		//
		// dna.start_node = dna.path;
		//
		// printf("nb_child => %d\n", dna.path->nb_lnk);
		// printf(">> %s\n", dna.path->next[0]->name);

		// dna.path = create_raw_path(&dna, dna.start->name, NULL);
			// printf("test => %s\n", dna->start->name);
		if (!(dna.node_lst = create_node_lst(&dna)))
			error("error : create tree failed\n");

		// if (!(dna.tree = create_tree(&dna)))
		// 	error("error : create tree failed\n");

		create_tree(&dna);


		cnt_lnk(&dna, "end");

		//Y A QU UN SEUL PUTAIN DE LNK !!!!!



		t_node *tmp = dna.node_lst;

		while (tmp)
		{
			int v = 0;
			printf("ROOM > %s\n", tmp->name);
			// printf("NB_LNK > %d\n", tmp->nb_lnk);

			while (v < tmp->nb_lnk)
			{
				printf("	child -> %s\n", tmp->lnk[v]->name);
				v++;
			}

			printf("\n\n");
			tmp = tmp->next;
		}

		// printf("LINK_LST => %p\n", dna.link_lst);


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

		// if (start_with_end(&dna))
		// {
		// 	printf("Soon\n");
		// 	return (0);
		// }


		// int i = 0;
		// while (pathfinding(&dna, i))
		// {
		// 	printf("HAAAAAAAAAAAAAAAAAAAAAAA\n");
		// 	i++;
		// }
		//
		// if (!i)
		// {
		// 	printf("A pas de chemin connard\n");
		// 	return (0);
		// }

		// ret = pathfinding(&dna, 3);
		// printf("      RET = %d\n", ret);
		// printf("%p\n", dna.start_node);

		// t_node *monky = best_node(dna.start_node);

		// printf("nb_lnk %d\n", dna.start_node->nb_lnk);

		// printf("best test %s\n", best_node(dna.start_node)->name);

		// debug_display_path(&dna, 0);


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
