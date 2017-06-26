/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:15:53 by lchety            #+#    #+#             */
/*   Updated: 2017/06/26 18:40:45 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		redundancy_link(t_dna *dna, char *str)
{
	char	*s1;
	char	*s2;
	t_link	*lst_link;

	lst_link = dna->link_lst;
	s1 = get_room_name(str, FROM);
	s2 = get_room_name(str, TO);
	while (lst_link)
	{
		if (!ft_strcmp(lst_link->from, s1) || !ft_strcmp(lst_link->from, s2))
		{
			if (!ft_strcmp(lst_link->to, s1) || !ft_strcmp(lst_link->to, s2))
			{
				ft_memdel((void**)&s1);
				ft_memdel((void**)&s2);
				return (1);
			}
		}
		lst_link = lst_link->next;
	}
	ft_memdel((void**)&s1);
	ft_memdel((void**)&s2);
	return (0);
}

int		link_integrity(t_dna *dna, char *str)
{
	char **split;
	char *s1;
	char *s2;

	if (!ft_strchr(str, '-'))
		return (0);
	if (!(split = ft_strsplit(str, '-')))
		return (0);
	if (!split[0] || !split[1])
	{
		free_split(split, 0);
		return (0);
	}
	if (!is_room_name(dna, split[0]) || !is_room_name(dna, split[1]))
	{
		free_split(split, 0);
		return (0);
	}
	free_split(split, 2);
	s1 = get_room_name(str, FROM);
	s2 = get_room_name(str, TO);
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

t_list	*precheck(t_list *data)
{
	char *str;

	if (!data)
		return (NULL);
	str = (char*)data->content;
	if (is_link(str))
		error("error : precheck link in room\n");
	if (is_com(str))
		error("error : commentary in cmd\n");
	if (!(check_coord(str)))
		error("error : bad coordinates\n");
	return (data);
}

t_list	*start_precheck(t_list *data)
{
	char	*str;
	int		length;

	length = 0;
	if (!data)
		return (NULL);
	str = (char*)data->content;
	if (is_link(str))
		error("error : link under ##start\n");
	if (is_com(str))
		error("error : commentary in ##start, try again\n");
	if (check_coord(str) == -1)
		error("error : bad coordinates\n");
	return (data);
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
