/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integrity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 17:01:40 by lchety            #+#    #+#             */
/*   Updated: 2017/08/04 21:05:34 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		check_link_str(t_dna *dna, char *str)
{
	char **split;

	if (!ft_strchr(str, '-') || !(split = ft_strsplit(str, '-')))
		return (0);

	// printf(" fuck fuck strcmp %d\n", ft_strcmp("0000", "0000"));
	// printf("SALOPERIE %d  %s\n", is_name(dna, split[1]), split[1]);
	if (!split[0] || !split[1] || !is_name(dna, split[0]) ||
	!is_name(dna, split[1]))
	{

		free_split(split, 0);
		return (0);
	}
	// printf("CRASH %s \n", str);
	free_split(split, 2);
	return (1);
}

int		link_integrity(t_dna *dna, char *str)
{
	char *s1;
	char *s2;

	if (!check_link_str(dna, str))
		return (0);
	s1 = get_name(str, FROM);
	s2 = get_name(str, TO);
	if (!ft_strcmp(s1, s2))
	{
		ft_memdel((void**)&s1);
		ft_memdel((void**)&s2);
		return (0);
	}
	ft_memdel((void**)&s1);
	ft_memdel((void**)&s2);
	if (dna->link_lst && redundancy_link(dna, str))
		return (0);
	return (1);
}

int		coord_integrity(char *a, char *b)
{
	if (!ft_str_isdigit(a) || !ft_str_isdigit(b))
		return (0);
	return (1);
}

int		check_edge_integrity(t_dna *dna)
{
	if (!dna->start)
		return (0);
	if (!dna->end)
		return (0);
	return (1);
}
