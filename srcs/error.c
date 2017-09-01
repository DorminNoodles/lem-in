/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:55:49 by lchety            #+#    #+#             */
/*   Updated: 2017/09/01 11:52:22 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	error(char *str)
{
	if (str)
		ft_putstr(str);
	exit(EXIT_FAILURE);
}

void	error_2(t_dna *dna, char *str)
{
	if (str)
		ft_putstr(str);
	main_free(dna);
	exit(EXIT_FAILURE);
}
