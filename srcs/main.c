/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:58:44 by lchety            #+#    #+#             */
/*   Updated: 2017/08/01 17:26:14 by lchety           ###   ########.fr       */
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

void	drop_in_best(t_dna *dna, int *stk)
{
	int	i;
	int	score;
	int best;

	score = -1;
	best = 0;
	i = 0;
	while (i < dna->path->nb_lnk)
	{
		// printf("ECTO child[%d]  :  %p\n", i, dna->path->next[i]);
		if (dna->path->next[i])
			printf("ACTIVE child[%d]  :  %d\n", i, dna->path->next[i]->active);
		if (dna->path->next[i] && dna->path->next[i]->active)
		{
			if (cost_of_path(dna, stk, i) < score || score == -1)
			{
				score = cost_of_path(dna, stk, i);
				best = i;
			}
		}
		i++;
	}
	stk[best]++;
}

int		main(int argc, char **argv)
{
	t_dna dna;

	dna_init(&dna);
	if (argc != 2)
		error("usage: ./lem-in input_file\n");
	if (parsing(&dna, argv[1]))
	{
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
		// printf(">> %s\n", dna.path->next[0]->room_name);

		dna.path = create_raw_path(&dna, dna.start->name, NULL);

		// printf("Start_node : %p\n", dna.start_node);
		// printf("Start_node(path) : %p\n", dna.path);

		// move_ants(&dna);
		// dna_free(&dna);
	}
	else
		ft_putstr("ERROR\n");
	return (0);
}
