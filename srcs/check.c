/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:15:53 by lchety            #+#    #+#             */
/*   Updated: 2017/10/27 16:32:29 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_coord_digit(t_dna *dna, char *str)
{
	char **split;

	if (str[ft_strlen(str) - 1] == 13)
		str[ft_strlen(str) - 1] = 0;
	split = ft_strsplit(str, ' ');
	if (!split)
		error(dna, "error : malloc beuargh\n");
	if (!ft_str_isdigit(split[0]) || !ft_str_isdigit(split[1]))
	{
		free_split(split, 2);
		return (0);
	}
	free_split(split, 2);
	return (1);
}

int		check_coord(t_dna *dna, char *str)
{
	int		i;
	char	*start;
	int		size;
	int		nb_coord;

	nb_coord = 0;
	i = 0;
	start = str;
	while (*str)
		str++;
	size = (int)(str - start);
	while (str >= start && nb_coord < 2)
	{
		if (ft_isdigit(*str) && str - 1 >= start && *(str - 1) == ' ')
			nb_coord++;
		str--;
	}
	if (str == start)
		return (0);
	if (nb_coord != 2)
		return (0);
	if (!check_coord_digit(dna, str))
		return (0);
	return (nb_coord);
}

char	*check_name(t_dna *dna, t_list *data)
{
	int		coord;
	int		size;
	char	*tmp;
	char	*str;
	char	*new;

	coord = 0;
	size = 0;
	str = (char*)data->content;
	tmp = str;
	while (*tmp)
		tmp++;
	while (coord < 2 && tmp > str)
	{
		if (ft_isdigit(*tmp) && *(tmp - 1) == ' ')
			coord++;
		tmp--;
	}
	size = (int)(tmp - str);
	if (!(new = ft_strnew((size_t)size)))
		error(dna, "error : malloc\n");
	return (ft_strncpy(new, str, (size_t)size));
}

t_list	*check_order(t_dna *dna, t_list *data, char *tmp)
{
	if (!ft_strcmp(tmp, "##start"))
	{
		data = start(dna, data->next);
		if (!data)
			return (NULL);
	}
	else if (!ft_strcmp(tmp, "##end"))
	{
		data = end(dna, data->next);
		if (!data)
			return (NULL);
	}
	return (data);
}
