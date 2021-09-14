/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:09:56 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/14 17:09:12 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	*memfree(t_lst *node)
{
	free(node);
	return (0);
}

t_lst	*new_lst(const void *value, size_t value_size)
{
	t_lst	*node;

	if (!(node = (t_lst*)malloc(sizeof(t_lst))))
		return (0);
	node->next = 0;
	if (!value)
	{
		node->value = 0;
		node->value_size = 0;
	}
	else
	{
		node->value_size = value_size;
		if (!(node->value = malloc(node->value_size)))
			return ((t_lst*)memfree(node));
		ft_bzero(node->value, node->value_size);
		ft_memcpy(node->value, value, node->value_size);
	}
	return (node);
}

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
	*new->value = atoi2(str, &err);
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
