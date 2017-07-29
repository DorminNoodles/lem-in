/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:32:04 by lchety            #+#    #+#             */
/*   Updated: 2017/07/29 20:51:03 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	move_ants(t_dna *dna)
{
	int		move;
	int		*stk;
	t_ants	*lst_ants;

	move = 1;
	if (!(stk = (int*)ft_memalloc(sizeof(int) * dna->path->nb_chld)))
		error("error : malloc\n");
	dispatch_ants(dna, stk);


	lst_ants = create_lst_ants(dna, dna->nb_ants);
	push_ants(dna, stk, lst_ants);
	display(dna, lst_ants);
	while (ants_in_path(dna, lst_ants))
	{
		printf("666\n");
		ants_displace(dna, lst_ants);
		push_ants(dna, stk, lst_ants);
		display(dna, lst_ants);
	}
	if (stk)
		ft_memdel((void**)&stk);
	free_lst_ants(lst_ants);
}
