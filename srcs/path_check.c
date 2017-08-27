/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 10:36:04 by lchety            #+#    #+#             */
/*   Updated: 2017/08/27 22:31:34 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		is_end(t_dna *dna, t_node *cp)
{
	if (!ft_strcmp(cp->name, dna->end->name))
		return (1);
	return (0);
}

int		is_start(t_dna *dna, t_node *cp)
{
	if (!ft_strcmp(cp->name, dna->start->name))
		return (1);
	return (0);
}
