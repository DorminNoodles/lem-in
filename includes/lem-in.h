/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 13:23:39 by lchety            #+#    #+#             */
/*   Updated: 2017/07/27 11:18:08 by lchety           ###   ########.fr       */
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
	int				nb_chld;
	int				num_path;
	int				active;
	int				ant;
	char			*room_name;
	struct s_node	*parent;
	struct s_node	**next;
	struct s_node	*joint;
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
}t_dna;

int			parsing(t_dna *dna, char *filename);
void		error(char *str);
int			is_com(char *str);
t_list		*open_file(char *filename);
int			is_end(t_dna *dna, t_node *cp);
int			repeat_room (t_node *cp);
int			cnt_lnk(t_dna *dna, const char *name);
char		**get_chlds_name(t_dna *dna, const t_node *p);
t_node		**set_child(t_node *cp);
int			chld_exist(t_dna *dna, t_node *path);
void		dna_init(t_dna *dna);
t_list		*room(t_dna *dna, t_list *data);
void		free_split(char **tab, int nb);
int			is_order(char *str);
int			link_integrity(t_dna *dna, char *str);
int			check_edge_integrity(t_dna *dna);
int			is_link(char *str);
t_list		*precheck(t_list *data);
char		*check_name(t_list *data);
char		*get_room_name(char *str, int flag);
void		add_roomlst(t_dna *dna, t_room *room);
int			only_blank(char *str);
void		free_room_lst(t_room **lst);
void		free_link_lst(t_link *lst);
int			pars_link(t_dna *dna, t_list *data);
void		clean_useless_path(t_dna *dna);
t_node		*best_chld(t_dna *dna, t_node *node);
t_node		*next_node_path(t_node *node);
t_node		*create_raw_path(t_dna *dna, char *name, t_node *parent);
t_list		*check_order(t_dna *dna, t_list *data, char *tmp);
t_list		*start(t_dna *dna, t_list *data);
t_list		*end(t_dna *dna, t_list *data);
void		clean_null_path(t_dna *dna);
void		sort_node_by_score(t_dna *dna);
int			compare_room(t_dna *dna, t_node *node);
int			check_path(t_dna *dna, t_node *node);
void		cp_init(t_node *cp, t_node *parent);
void		dna_free(t_dna *dna);
int			cost_of_path(t_dna *dna, int *stk, int nb);
void		display(t_ants *lst);
void		dispatch_ants(t_dna *dna, int *stk);
void		push_ants(t_dna *dna, int *stk, t_ants *lst_ants);
void		drop_in_best(t_dna *dna, int *stk);
t_ants		*create_lst_ants(t_dna *dna, int nb);
void		move_ants(t_dna *dna);
void		free_one_node(t_node **n);
void		free_lst_ants(t_ants *lst_ants);
int			ants_in_path(t_dna *dna, t_ants *lst);
void		ants_displace(t_dna *dna, t_ants *lst);
int			is_room_name(t_dna *dna, char *str);
int			redundancy_link(t_dna *dna, char *str);
int			check_coord(char *str);
void		add_node_lst(t_dna *dna, t_node *node);
int			is_start(t_dna *dna, t_node *cp);
#endif
