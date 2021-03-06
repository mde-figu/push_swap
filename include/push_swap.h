/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:49:51 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/17 13:44:21 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <inttypes.h>
# include "../libft/libft.h"
# define TRUE 1
# define FALSE 0
# define SHIFT_RIGHT 0
# define SHIFT_LEFT 1

typedef struct s_lst
{
	void			*value;
	size_t			value_size;
	struct s_lst	*next;
}					t_lst;

typedef struct s_vars
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
void		init_stack(char **tmp, t_lst **l_a);
void		*ft_memalloc(size_t size);
void		**freeentry(char **str, size_t i);
void		ft_error_memory(void);
t_vars		*set_vars(t_lst *l_a);
int			test_n(int argc, char **argv);
void		add_to_back(t_lst **head, int input);
t_lst		*lstn(t_lst *ls, size_t n);
size_t		lst_len(t_lst *ls);
t_lst		*new_lst(const void *value, size_t value_size);
void		ft_lstadd(t_lst **alst, t_lst *new);
void		set_mem_free(t_lst *l_a, t_lst *l_b, t_vars *vars);
/* opers */
void		ops_print(char **operations);
void		erase_opers(t_vars *vars);
void		push(t_lst **dst, t_lst **src, t_vars *vars, char *op);
void		swap(t_lst **l, t_vars *vars, char *op);
void		rotate(t_lst **l, t_vars *vars, char *op);
void		rev_rotate(t_lst **l, t_vars *vars, char *op);
/* re_opers */
void		re_push_a(t_lst **l_a, t_lst **l_b, t_vars *vars);
void		re_push_b(t_lst **l_a, t_lst **l_b, t_vars *vars, int c);
int			get_middle(t_lst *ls, int len);
_Bool		eval_rrr(t_lst *ls, int piv, _Bool label);
/* sorting */
int			sorted(t_lst **l_a);
void		sort(t_lst **l_a, t_lst **l_b, t_vars *vars);
int			ps_qsort(t_lst **l_a, t_lst **l_b, t_vars *vars);
_Bool		eval_sort(t_lst *l_a, t_lst *l_b);
int			ran_sort(t_lst *ls, int len, _Bool label);
_Bool		is_between(t_lst *l_a, t_lst *l_b, int one, int two);
_Bool		is_reversed(t_lst *ls);
void		need_to_swap(t_lst **l_a, t_lst **l_b, t_vars *vars);
void		get_back(t_lst **l_a, t_lst **l_b, t_vars *vars);
void		push_rest_b(t_lst **l_a, t_lst **l_b, t_vars *vars);
void		sort_three(t_lst **l_a, t_vars *vars);
void		shift_b_part(t_vars *vars, _Bool label);

/* backtracking */
int			backtrack(t_lst **l, int n, t_vars *vars, _Bool label);
void		un_push(t_lst **dst, t_lst **src);
void		un_swap(t_lst **head);
void		un_rotate(t_lst **head);
void		un_rev_rotate(t_lst **head);

#endif
