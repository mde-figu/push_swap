/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:49:51 by mde-figu          #+#    #+#             */
/*   Updated: 2021/08/31 13:31:20 by mde-figu         ###   ########.fr       */
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
void	testargs(char **argv);
int		to_list(char *str, t_lst **l);
int		test_n(int argc, char **argv);
void	add_to_back(t_lst **head, int input);
int		lst_len(t_lst *ls);
t_lst	*new_lst(int input);

#endif
