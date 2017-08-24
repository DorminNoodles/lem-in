/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:58:44 by lchety            #+#    #+#             */
/*   Updated: 2017/08/24 16:13:02 by lchety           ###   ########.fr       */
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

void	create_lst_ants(t_dna *dna)
{
	int i;

	i = 0;
	if (!(dna->lst_ants = ft_memalloc(sizeof(t_ants) * dna->nb_ants)))
		error("error : Malloc failed\n");
	init_lst_ants(dna);
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
		ft_putchar('-');
		ft_putstr(dna->start_node->name);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	i = 0;
	while (i < dna->nb_ants)
	{
		ft_putchar('L');
		itoa = ft_itoa(i);
		ft_putstr(itoa);
		ft_putchar('-');
		ft_putstr(dna->end_node->name);
		ft_putchar(' ');
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
		if (dna.nb_path)
			move_ants(&dna);
		else
			ft_putstr("error : no path\n");
	}
	else
		ft_putstr("ERROR\n");
	return (0);
}
