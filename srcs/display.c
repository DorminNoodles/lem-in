/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:37:37 by lchety            #+#    #+#             */
/*   Updated: 2017/07/29 21:22:39 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		display(t_dna *dna, t_ants *lst)
{
	t_node	*tmp;
	char	*itoa;


	printf("SEGV %p\n", lst->pos);
	while (lst)
	{
		printf("lst->id = %d\n", lst->id);
		if (lst->pos)
			printf("pos : %s\n", lst->pos->room_name);
		// if (lst->pos && lst->active)
		// {
		// 	tmp = (t_node*)lst->pos;
		// 	ft_putstr("L");
		// 	ft_putstr(((itoa = ft_itoa(lst->id))));
		// 	free(itoa);
		// 	ft_putstr("-");
		// 	ft_putstr((char*)tmp->room_name);
		// 	ft_putstr(" ");
		// 	if (is_end(dna, tmp))
		// 	{
		// 		printf("REDRUM\n");
		// 		return;
		// 	}
		// }
		lst = lst->next;
	}
	ft_putstr("\n");
}


void	display_path_debug(t_dna *dna)
{
	int i;
	t_node *tmp;

	i = 0;
	printf("NB_PATH : %d\n", dna->nb_path);
	while (i < dna->nb_path)
	{
		tmp = dna->path->next[i];
		while (tmp)
		{
			tmp = next_node_path(tmp);
		}
		i++;
	}
}
