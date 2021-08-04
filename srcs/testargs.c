/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testargs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:04:26 by mde-figu          #+#    #+#             */
/*   Updated: 2021/08/04 13:38:36 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static _Bool	valid_num(char *str)
{
	if (*str == '-')
		++str;
	while (*str)
		if (!ft_isdigit(*str++))
			return (FALSE);
	if (*(str - 1) == '-')
		return (FALSE);
	else
		return (TRUE);
}

static _Bool	greater_than_int(char *num)
{
	_Bool	minus;
	size_t	len;

	if (*num == '-' && ++num)
		minus = TRUE;
	else
		minus = FALSE;
	len = ft_strlen(num);
	if (len == 10)
	{
		if (minus && ft_strcmp(num, "2147483648") > 0)
			return (TRUE);
		else if (!minus && ft_strcmp(num, "2147483647") > 0)
			return (TRUE);
	}
	else if (len > 10)
		return (TRUE);
	return (FALSE);
}

static _Bool	appears_twice(char *c, char **argv, size_t index)
{
	size_t		i;

	i = 0;
	while (i < index)
		if (!ft_strcmp(c, argv[i++]))
			return (TRUE);
	return (FALSE);
}

void	testargs(char **argv)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = argv;
	while (*argv && ++i)
	{
		if (!valid_num(*argv) != 0 || appears_twice(*argv, ptr, i - 1) != 0
			|| greater_than_int(*argv) != 0)
			write(1, "Error", 5);
		argv++;
	}
}
