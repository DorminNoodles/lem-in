/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 13:23:39 by lchety            #+#    #+#             */
/*   Updated: 2017/09/01 14:16:21 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEMIN_H
#define LEMIN_H

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

#define BUFFER_SIZE 65535
#define FROM 1
#define TO 2

#define POUET   "test\n pouet2"

typedef struct s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
}t_room;

typedef struct s_link
{
	char			*from;
	char			*to;
	struct s_link	*next;
}t_link;

typedef struct s_line
{
	int nb;
	char *data;
}t_line;

typedef struct s_node
{
	int				score;
	int				nb_lnk;
	int				num_path;
	int				active;
	int				ant;
	char			*name;
	struct s_node	*parent;
	struct s_node	**lnk;
	struct s_node	*next;
}t_node;

typedef struct s_ants
{
	int				id;
	int				active;
	t_node			*pos;
	struct	s_ants	*next;
}t_ants;

typedef struct s_dna
{
	int		nb_ants;
	int		nb_path;
	int		node_limits;
	t_room	*start;
	t_room	*end;
	t_node	*start_node;
	t_node	*end_node;
	t_room	*room_lst;
	t_link	*link_lst;
	t_node	*node_lst;
	t_node	*tmp_node_lst;
	t_node	*path;
	t_list	*path_done;
	t_node	*tree;
	t_ants	*lst_ants;
	char	*data;
	char	*data_end;
}t_dna;

int			parsing(t_dna *dna, char *filename);
void		error(t_dna *dna, char *str);
t_list		*open_file(t_dna *dna, char *filename);
int			is_com(char *str);
int			is_end(t_dna *dna, t_node *cp);
int			repeat_room (t_node *cp);
int			cnt_lnk(t_dna *dna, const char *name);
void		dna_init(t_dna *dna);
t_list		*room(t_dna *dna, t_list *data);
void		free_split(char **tab, int nb);
int			is_order(char *str);
int			link_integrity(t_dna *dna, char *str);
int			check_edge_integrity(t_dna *dna);
int			is_link(char *str);
t_list		*precheck(t_dna *dna, t_list *data);
char		*check_name(t_list *data);
char		*get_name(t_dna *dna, char *str, int flag);
void		add_roomlst(t_dna *dna, t_room *room);
int			only_blank(char *str);
void		free_room_lst(t_room **lst);
void		free_link_lst(t_link **lst);
t_list		*pars_link(t_dna *dna, t_list *data);
t_list		*check_order(t_dna *dna, t_list *data, char *tmp);
t_list		*start(t_dna *dna, t_list *data);
t_list		*end(t_dna *dna, t_list *data);
int			compare_room(t_dna *dna, t_node *node);
int			check_path(t_dna *dna, t_node *node);
void		cp_init(t_node *cp, t_node *parent);
void		dna_free(t_dna *dna);
void		display(t_dna *dna);
void		push_ants(t_dna *dna, int *stk);
void		move_ants(t_dna *dna);
void		free_lst_ants(t_ants **lst_ants);
int			is_name(t_dna *dna, char *str);
int			redundancy_link(t_dna *dna, char *str);
int			check_coord(t_dna *dna, char *str);
void		add_node_lst(t_dna *dna, t_node *node);
int			is_start(t_dna *dna, t_node *cp);
void		display_path_debug(t_dna *dna);
t_node		*create_node_lst(t_dna *dna);
void		node_init(t_dna *dna, t_node *node, char *name);
t_node		*get_next_node(t_dna *dna, t_node *node, int nb);
char		*get_next_lnk(t_dna *dna, char *name, int nb);
int			pathfinding(t_dna *dna, int num);
t_node		*next_node_path(t_node *node, int num_path);
void		debug_display_path(t_dna *dna, int num);
void		debug_display_all(t_dna *dna);
int			start_with_end(t_dna *dna);
void		debug_display_path_2(t_dna *dna, int num);
void		create_node_score(t_dna *dna);
int			redundancy_link_2(t_dna *dna, char *from, char *to);
int			get_all_lnk(t_dna *dna, t_node **next_lnk);
void		create_lst_ants(t_dna *dna);
void		debug_display_path_reverse(t_dna *dna, int num);
void		init_lst_ants(t_dna *dna);
void		start_to_end(t_dna *dna);
void		main_free(t_dna *dna);
void		display_map(t_list *data, t_list *tmp_data);
void		move(t_dna *dna);
void		create_tree(t_dna *dna);
t_node		*next_shortest_node(t_node *node);
int			create_path(t_dna *dna);
#endif
