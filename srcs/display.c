/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:37:37 by lchety            #+#    #+#             */
/*   Updated: 2017/08/01 14:18:35 by lchety           ###   ########.fr       */
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
	printf("ENTER DISPLAY PATH\n");
	int i;
	t_node *tmp;

	i = 0;
	printf("NB_PATH > %d\n", dna->nb_path);

	printf("Room Start %s\n\n", dna->path->room_name);

	tmp = dna->path->next[0];
	while (tmp)
	{
		printf("Room %s\n", tmp->room_name);
		printf("Num %d\n", tmp->num_path);
		tmp = next_node_path(tmp);
	}
	printf("\n");
	tmp = dna->path->next[1];
	while (tmp)
	{
		printf("Room %s\n", tmp->room_name);
		printf("Num %d\n", tmp->num_path);
		printf("Child num path %d\n", tmp->next[0]->num_path);
		printf("Child num path %p\n", tmp->next[0]);
		printf("Child num path %d\n", tmp->next[1]->num_path);
		printf("Child num path %p\n", tmp->next[1]);
		tmp = next_node_path(tmp);
	}
	printf("test %p\n", tmp);
	printf("\n\n");
}
