/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:51:48 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/17 17:35:02 by mde-figu         ###   ########.fr       */
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

	ptr = argv;
	write(1, ft_itoa(argc), sizeof(argc));
	while (*ptr)
	{
		write(1, *ptr, sizeof(*ptr));
		//*ptr++;
	}
	write(1, "\n", 1);
	free (ptr); //isso não pode ficar assim
}

int	main(int argc, char **argv)
{
	t_lst	*l_a;
	int		len;
	//t_lst	*ptr;
	//int		i;

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
//	while (l_a)
//		pop(&l_a); << estava pensando op pop
}
