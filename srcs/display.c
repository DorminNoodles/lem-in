/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:37:37 by lchety            #+#    #+#             */
/*   Updated: 2017/07/27 11:21:21 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		display(t_ants *lst)
{
	t_node	*tmp;
	char	*itoa;

	while (lst)
	{
		if (lst->pos && lst->active)
		{
			tmp = (t_node*)lst->pos;
			ft_putstr("L");
			ft_putstr(((itoa = ft_itoa(lst->id))));
			free(itoa);
			ft_putstr("-");
			ft_putstr((char*)tmp->room_name);
			ft_putstr(" ");
		}
		lst = lst->next;
	}
	ft_putstr("\n");
}
