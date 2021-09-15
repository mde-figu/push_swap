/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:51:48 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/14 20:58:19 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	test_n(int argc, char **argv)
{
	int		var[3];
	char	err;

	err = 0;
	if (argc <= 1)
	{
		if (argc < 0 || atoi2(*argv++, &err))
			return (write(1, "No numbers\n", 6));
	}
	var[0] = atoi2(*argv++, &err);
	var[1] = atoi2(*argv++, &err);
	if ((var[0]) || (var[1]))
		return (write(1, "error2\n", 6));
	var[2] = atoi2(*argv, &err);
	if (var[2])
		return (write(1, "error3\n", 6));
	return (0);
}


void	init_stack(char **tmp, t_lst **l_a)
{
	t_lst	*head;
	void	*val;

	if (!(val = ft_memalloc(sizeof(int))))
		ft_error_memory();
	head = 0;
	while (*tmp)
	{
		*((int*)val) = ft_atoi(*tmp++);
		ft_lstadd(&head, new_lst(val, sizeof(int)));
	}
	free(val);
	*l_a = 0;
	while (head)
		un_push(l_a, &head);
}

int	main(int argc, char **argv)
{
	t_lst	*l_a;
	t_lst	*l_b;
	t_vars	*vars;
	char	**tmp;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		tmp = ft_strsplit(*(argv + 1), ' ');
	else
		tmp = argv + 1;
	l_b = 0;
	testargs(tmp);
	init_stack(tmp, &l_a);
	vars = set_vars(l_a);
	sort(&l_a, &l_b, vars);
	ops_print(vars->opers);
	//printf("%i", *l_a->value);
	//printf("%i", *l_a->next->value);
	//printf("%i", *l_a->next->next->value);
	//printf("%i", *l_a->next->next->next->value);
	//printf("%i", *l_a->next->next->next->next->value);
	return (0);
}
