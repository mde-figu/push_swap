/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:51:48 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/23 18:02:39 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

char	to_list(char *str, t_lst **l)
{
	char	err;
	t_lst	*new;

	err = '\0';
	if (!l)
		return (0);
	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (0);
	new->value = atoi2(str, &err);
	if (err)
		return (0);
	new->next = NULL;
	if (!(*l))
		*l = new;
	else
	{
		new->next = *l;
		*l = new;
	}
	return (1);
}

int	test_n(int argc, char **argv)
{
	int		var[3];
	char	err;

	err = 0;
	if (argc <= 1)
	{
		if (argc < 0 || atoi2(*argv++, &err))
			return (write(1, "Error1\n", 6));
	}
	else
		return (0);
	var[0] = atoi2(*argv++, &err);
	var[1] = atoi2(*argv++, &err);
	if ((var[0] && err) || (var[1] && err))
		return (write(1, "error2\n", 6));
	var[2] = atoi2(*argv, &err);
	if (var[2] && err)
		return (write(1, "error3\n", 6));
	// aqui ordenaremos
	return (0); //tirar isso
}

void	testargs(int argc, char **argv)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = argv;
	printf("%i", argc);
	while (*argv && ++i)
	{
		if (valid_num(*argv) != 0 || appears_twice(*argv, ptr, i - 1) != 0
			|| greater_than_int(*argv) != 0)
			write(1, "errooou", 7);
		argv++;
	}
}

int	main(int argc, char **argv)
{
	t_lst	*l_a;
	t_lst	*l_b;
	int		len;
	char	**tmp;

	(void)l_b;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		tmp = ft_strsplit(*(argv + 1), ' ');
	testargs(argc, argv);
	l_a = NULL;
	if (argc <= 1)
		return (write(1, "error\n", 6));
	len = 0;
	l_a = NULL;
	if (argc <= 4)
		return (test_n(argc - 1, argv));
	while (*argv && ++len)
		if (!(to_list(*argv++, &l_a)))
			return (write(1, "Error\n", 6));
}
