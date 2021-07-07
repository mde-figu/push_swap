/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:49:51 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/07 15:14:15 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_lst
{
	int				value;
	struct s_lst	*next;
}					t_lst;

int		atoi2(const char *str, char *err);
void	testargs(int argc, char **argv);
char	to_list(char *str, t_lst **l);
int		test_n(int argc, char **argv);

#endif
