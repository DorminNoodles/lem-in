/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:15:53 by lchety            #+#    #+#             */
/*   Updated: 2017/06/27 19:13:11 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		check_coord_digit(char *str)
{
	char **split;

	if (str[ft_strlen(str) - 1] == 13)
		str[ft_strlen(str) - 1] = 0;
	split = ft_strsplit(str, ' ');
	if (!split)
		error("error : malloc beuargh\n");
	if (!ft_str_isdigit(split[0]) || !ft_str_isdigit(split[1]))
	{
		free_split(split, 2);
		return (0);
	}
	free_split(split, 2);
	return (1);
}

int		check_coord(char *str)
{
	int		i;
	char	*start;
	int		size;
	int		coord;

	coord = 0;
	i = 0;
	start = str;
	while (*str)
		str++;
	size = str - start;
	while (str >= start && coord < 2)
	{
		if (ft_isdigit(*str) && str - 1 >= start && *(str - 1) == ' ')
			coord++;
		str--;
	}
	if (str == start)
		return (0);
	if (coord != 2)
		return (0);
	if (!check_coord_digit(str))
		return (0);
	return (coord);
}

char	*check_name(t_list *data)
{
	int		coord;
	int		size;
	char	*tmp;
	char	*str;

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
	size = tmp - str;
	return (ft_strncpy(ft_strnew(size), str, size));
}

t_list	*check_order(t_dna *dna, t_list *data, char *tmp)
{
	if (ft_strstr(tmp, "##start"))
	{
		data = start(dna, data->next);
		if (!data)
			return (NULL);
	}
	else if (ft_strstr(tmp, "##end"))
	{
		data = end(dna, data->next);
		if (!data)
			return (NULL);
	}
	return (data);
}
