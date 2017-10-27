/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:42:15 by lchety            #+#    #+#             */
/*   Updated: 2017/10/27 16:28:53 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	push_ants(t_dna *dna, int *stk)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < dna->start_node->nb_lnk)
	{
		if (dna->start_node->lnk[i]->active && stk[i] > 0)
		{
			j = 0;
			stk[i]--;
			while (j < dna->nb_ants)
			{
				if (is_start(dna, dna->lst_ants[j].pos))
				{
					dna->lst_ants[j].pos = dna->start_node->lnk[i];
					dna->lst_ants[j].active = 1;
					break ;
				}
				j++;
			}
		}
		i++;
	}
}

void	create_lst_ants(t_dna *dna)
{
	int i;
	unsigned long nb;

	i = 0;
	nb = (unsigned long)dna->nb_ants;
	if (!(dna->lst_ants = ft_memalloc(sizeof(t_ants) * nb)))
		error(dna, "error : Malloc failed\n");
	init_lst_ants(dna);
}
