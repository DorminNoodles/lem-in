/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:42:03 by lchety            #+#    #+#             */
/*   Updated: 2017/09/02 11:21:55 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		addtolst(t_list **data, t_list *new)
{
	t_list	*lst;

	if (*data)
	{
		lst = *data;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*data = new;
}

t_list			*open_file(t_dna *dna)
{
	int		ret;
	char	*tmp;
	t_list	*lst;
	t_list	*data;

	ret = 0;
	data = NULL;
	tmp = NULL;
	while ((ret = get_next_line(0, &tmp)) > 0)
	{
		if (!(lst = (t_list*)ft_memalloc(sizeof(t_list))))
			error(dna, "error : malloc\n");
		lst->content = tmp;
		addtolst(&data, lst);
	}
	return (data);
}
