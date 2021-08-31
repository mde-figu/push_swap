/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:51:48 by mde-figu          #+#    #+#             */
/*   Updated: 2021/08/31 17:32:48 by mde-figu         ###   ########.fr       */
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
	// aqui ordenaremos
	return (0); //tirar isso
}

static void	**freeentry(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(str[j++]);
	free(str);
	return (0);
}

t_lst	*init_stack(char *argv[])
{
	t_lst *tmp;
	char	*err;
	int		i;

	err = NULL;
	tmp = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		add_to_back(&tmp, atoi2(argv[i], err));
		i++;
	}
	return (tmp);

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
		tmp = ft_strsplit(argv[1], ' ');
	else
		tmp = argv + 1;
	//write(1, tmp[0], 2);
	//write(1, tmp[1], 1);
	//write(1, tmp[2], 1);
	//write(1, tmp[3], 1);
	//write(1, tmp[4], 1);
	testargs(tmp);
	if (argc <= 1)
		return (write(1, "error, argc <= 1\n", 17));
	len = 0;
	l_a = NULL;
	l_a = init_stack(argv);
	printf(" Argc = %i\n", argc - 1);
	//if (argc -1 == 3)
	//	case_three(); 
	if (argc - 1 <= 4)
	{
		test_n(argc - 1, argv);
		freeentry(tmp, sizeof(tmp));
	}
	printf("%i", l_a->value);
	printf("%i", l_a->next->value);
	printf("%i", l_a->next->next->value);
	printf("%i", l_a->next->next->next->value);
	printf("%i", l_a->next->next->next->next->value);
	while (*argv && ++len)
		if (!(to_list(*argv++, &l_a))) // Tem merda acontecendo aqui
			return (write(1, "Error\n", 8));
}
