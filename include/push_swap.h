/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:49:51 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/19 14:27:06 by mde-figu         ###   ########.fr       */
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
	struct s_lst	*next;
}					t_lst;

int		atoi2(const char *str, char *err);
void	testargs(int argc, char **argv);
char	to_list(char *str, t_lst **l);
int		test_n(int argc, char **argv);
_Bool	greater_than_int(char *num);
_Bool	valid_num(char *str);
_Bool	appears_twice(char *c, char **argv, size_t index);

#endif
