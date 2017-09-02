/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:17:32 by lchety            #+#    #+#             */
/*   Updated: 2017/09/02 11:21:55 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_room_lst(t_room **lst)
{
	if ((*lst)->next)
		free_room_lst(&(*lst)->next);
	ft_memdel((void**)&(*lst)->name);
	ft_memdel((void**)lst);
}

void	free_link_lst(t_link **lst)
{
	if ((*lst)->next)
		free_link_lst(&(*lst)->next);
	ft_memdel((void**)&(*lst)->from);
	ft_memdel((void**)&(*lst)->to);
	ft_memdel((void**)lst);
}
