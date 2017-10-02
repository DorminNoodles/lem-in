/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:30:05 by lchety            #+#    #+#             */
/*   Updated: 2017/10/02 11:38:13 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*newroom(t_dna *dna)
{
	t_room	*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	if (!room)
		error(dna, "error : malloc\n");
	room->next = NULL;
	return (room);
}

t_list		*end(t_dna *dna, t_list *data)
{
	int		length;
	t_room	*room;

	length = 0;
	room = newroom(dna);
	if (!precheck(dna, data))
		return (NULL);
	if (!(room->name = check_name(dna, data)))
		error(dna, "error : check_name failed\n");
	dna->end = room;
	return (data);
}

t_list		*start(t_dna *dna, t_list *data)
{
	t_room	*room;

	room = newroom(dna);
	if (!(data = precheck(dna, data)))
		return (NULL);
	if (!(room->name = check_name(dna, data)))
		error(dna, "error : start check_name failed\n");
	if (only_blank(room->name))
		error(dna, "error : start bad name\n");
	dna->start = room;
	return (data);
}

t_list		*std_room(t_dna *dna, t_list *data)
{
	char	*tmp;
	t_room	*room;

	tmp = data->content;
	room = newroom(dna);
	if (!precheck(dna, data))
		return (NULL);
	if (!(room->name = check_name(dna, data)))
		return (NULL);
	if (only_blank(room->name))
		error(dna, "error : empty name\n");
	add_roomlst(dna, room);
	return (data);
}

t_list		*room(t_dna *dna, t_list *data)
{
	char *tmp;

	while (data)
	{
		tmp = (char*)data->content;
		if (!is_com(tmp))
		{
			if (*tmp == 'L')
				return (NULL);
			else if (is_link(tmp) && check_edge_integrity(dna))
				return (data);
			else if (is_link(tmp) && !check_edge_integrity(dna))
				error(dna, "error : bad room integrity\n");
			else if (is_order(tmp))
			{
				if (!(check_order(dna, data, tmp)))
					return (NULL);
			}
			else if (!(data = std_room(dna, data)))
				return (NULL);
		}
		if (data)
			data = data->next;
	}
	return (data);
}
