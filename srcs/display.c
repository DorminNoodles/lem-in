/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:37:37 by lchety            #+#    #+#             */
/*   Updated: 2017/08/22 01:40:37 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		display(t_dna *dna)
{
	t_node	*tmp;
	char	*itoa;
	int i;

	i = 0;

	while (i < dna->nb_ants)
	{
		// printf("fchier\n");
		// if (dna->lst_ants[i].active)
		// {
		// 	printf("popol\n");
		// 	//printf("L%d-%s\n", dna->lst_ants[i].id+1, dna->lst_ants[i].pos->name);
		// }
		i++;
	}



	ft_putstr("\n");
}

void	display_path_debug(t_dna *dna)
{
	int i;
	t_node *tmp;

	i = 0;


	tmp = &dna->path->next[0];
	while (tmp)
	{
		tmp = next_node_path(tmp);
	}
	tmp = &dna->path->next[1];
	while (tmp)
	{
		tmp = next_node_path(tmp);
	}
}
