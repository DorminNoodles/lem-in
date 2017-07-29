/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:58:44 by lchety            #+#    #+#             */
/*   Updated: 2017/07/29 18:40:21 by lchety           ###   ########.fr       */
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
	while (i < dna->path->nb_chld)
	{
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
	// printf("BORDEL DE MERDE\n");
	t_dna dna;

	dna_init(&dna);
	if (argc != 2)
		error("usage: ./lem-in input_file\n");
	if (parsing(&dna, argv[1]))
	{
		while (!(dna.path = create_raw_path(&dna, NULL, NULL)))
		{
			printf("BORDEL DE MERDE\n");
			if (dna.node_limits < 30)
				dna.node_limits++;
			else
				break ;
		}
		// printf("SEGFAULT\n");
		// printf("dna ->path %s \n", dna.path->room_name);
		// printf("dna ->path %d \n", dna.path->next[2]->nb_chld);
		// printf("dna ->path %s \n", dna.path->next[2]->room_name);

		if (!dna.nb_path)
			error("error : no path\n");
		clean_useless_path(&dna);

		dna.start_node = dna.path;

		// printf("Start_node : %p\n", dna.start_node);
		// printf("Start_node(path) : %p\n", dna.path);

		move_ants(&dna);
		dna_free(&dna);
	}
	else
		ft_putstr("ERROR\n");
	return (0);
}
