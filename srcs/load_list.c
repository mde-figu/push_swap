/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:09:56 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/28 11:15:06 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	to_list(char *str, t_lst **l)
{
	char	err;
	t_lst	*new;

	err = '\0';
	if (!l)
		return (0);
	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
	{
		free(new);
		return (0);
	}
	new->value = atoi2(str, &err);
	new->next = NULL;
	if (!(*l))
		*l = new;
	else
	{
		new->next = *l;
		*l = new;
	}
	free(new);
	return (1);
}
