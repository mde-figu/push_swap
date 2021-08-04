/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:51:48 by mde-figu          #+#    #+#             */
/*   Updated: 2021/08/04 13:48:11 by mde-figu         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_lst	*l_a;
	t_lst	*l_b;
	int		len;
	char	**tmp;

	(void)l_b; //tirar
	if (argc < 2)
		return (0);
	else if (argc == 2)
		tmp = ft_strsplit(*(argv + 1), ' ');
	else
		tmp = argv + 1;
	write(1, tmp[0], sizeof(tmp[0]));
	write(1, tmp[1], sizeof(tmp[1]));
	write(1, tmp[2], sizeof(tmp[2]));
	write(1, tmp[3], sizeof(tmp[3]));
	write(1, tmp[4], sizeof(tmp[4]));
	l_a = 0;
	testargs(tmp);
	if (argc <= 1)
		return (0);
	len = 0;
	l_a = NULL;
	if (argc <= 4)
		return (test_n(argc - 1, argv));
	while (*argv && ++len)
		if (!(to_list(*argv++, &l_a)))
			return (write(1, "Error\n", 8));
}
