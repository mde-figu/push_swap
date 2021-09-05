/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:49:51 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/05 14:00:10 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# define TRUE 1
# define FALSE 0

typedef struct s_lst
{
	int				value;
	size_t			value_size;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_vars
{
	char			**opers;
	int				*parts_a;
	int				*parts_b;
	int				index;
	int				piv;
	_Bool			need_rev;
}					t_vars;

int			atoi2(const char *str, char *err);
void		testargs(char **argv);
void		*ft_memalloc(size_t size);
void		**freeentry(char **str, size_t i);
void		ft_error_memory(void);
t_vars		*set_vars(t_lst *l_a);
int			to_list(char *str, t_lst **l);
int			test_n(int argc, char **argv);
void		add_to_back(t_lst **head, int input);
int			lst_len(t_lst *ls);
t_lst		*new_lst(int input);

/* sorting */
int			sorted(t_lst **l_a);
/* backtracking */
int			backtrack(t_lst **l, int n, t_vars vars, _Bool label);
void		push(t_lst **dst, t_lst **src, t_vars vars, char *op);
void		swap(t_lst **l, t_vars *vars, char *op);
void		rotate(t_lst **l, t_vars *vars, char *op);
void		rev_rotate(t_lst **l, t_vars *vars, char *op);
void		un_push(t_list **dst, t_lst **src);
void		un_swap(t_lst **head);
void		un_rotate(t_lst **head);
void		un_rev_rotate(t_lst **head);


#endif
