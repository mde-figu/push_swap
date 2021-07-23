/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:26:11 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/19 14:27:01 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	atoi2(const char *str, char *err)
{
	static unsigned int	val;
	static unsigned int	mx;
	static int			sg;

	if (!str)
		return ((*err = 1));
	sg = 1;
	if (*str == '+')
		str++;
	if (*str == '-' && str++)
		sg = -1;
	if (sg == 1)
		mx = 2147483647;
	else
		mx = 2147483648;
	if (!(*str >= '0' && *str <= '9'))
		return (*err = 1);
	val = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		val = val * 10 + *str++ - '0';
		if (val > mx)
			return ((*err = 1));
	}
	return (val * sg);
}

_Bool	appears_twice(char *c, char **argv, size_t index)
{
	size_t		i;

	i = 0;
	while (i < index)
		if (!ft_strcmp(c, argv[i++]))
			return (TRUE);
	return (FALSE);
}

_Bool	valid_num(char *str)
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

_Bool	greater_than_int(char *num)
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
