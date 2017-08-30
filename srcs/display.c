/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:37:37 by lchety            #+#    #+#             */
/*   Updated: 2017/08/30 09:47:30 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	display_map(t_list *data, t_list *limit)
{
	if (limit)
	{
		while (data && data->content != limit->content)
		{
			ft_putstr((char*)data->content);
			ft_putchar('\n');
			data = data->next;
		}
	}
	else
	{
		while (data)
		{
			ft_putstr((char*)data->content);
			ft_putchar('\n');
			data = data->next;
		}
	}
	ft_putchar('\n');
}

void	display(t_dna *dna)
{
	t_node	*tmp;
	char	*itoa;
	int		i;

	i = 0;
	while (i < dna->nb_ants)
	{
		if (dna->lst_ants[i].active)
		{
			ft_putchar('L');
			itoa = ft_itoa(dna->lst_ants[i].id + 1);
			ft_putstr(itoa);
			ft_memdel((void**)&itoa);
			ft_putchar('-');
			ft_putstr(dna->lst_ants[i].pos->name);
			ft_putchar(' ');
		}
		i++;
	}
	ft_putstr("\n");
}
