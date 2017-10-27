/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:58:44 by lchety            #+#    #+#             */
/*   Updated: 2017/10/27 16:19:07 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	start_to_end(t_dna *dna)
{
	int		i;
	char	*itoa;

	i = 0;
	while (i < dna->nb_ants)
	{
		ft_putchar('L');
		itoa = ft_itoa(i + 1);
		ft_putstr(itoa);
		ft_putchar('-');
		ft_putstr(dna->end_node->name);
		ft_memdel((void**)&itoa);
		if (i + 1 < dna->nb_ants)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int		main(void)
{
	t_dna	dna;
	int		ret;

	ret = 0;
	dna_init(&dna);
	if (parsing(&dna))
	{
		create_path(&dna);
		if (!start_with_end(&dna))
		{
			if (dna.nb_path)
			{
				create_lst_ants(&dna);
				move(&dna);
			}
			else
				ft_putstr("error : no path\n");
		}
		main_free(&dna);
	}
	else
		ft_putstr("ERROR\n");
	return (0);
}
