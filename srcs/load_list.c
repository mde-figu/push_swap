/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:09:56 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/02 14:46:36 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*new_lst(int input)
{
	t_lst	*head;

	head = (t_lst *)malloc(sizeof(t_lst)); //ta dando merda aqui
	head->value = input;
	head->next = NULL;
	return (head);
}

void	add_to_back(t_lst **head, int input)
{
	t_lst *tmp;
	t_lst *add;

	if (*head == NULL)
	{
		*head = new_lst(input);
	}
	else
	{
		add = (t_lst *)malloc(sizeof(t_lst));
		add->value = input;
		add->next = NULL;
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = add;
		//free(tmp); //ainda nao ta bom
	}
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
