/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:26:11 by mde-figu          #+#    #+#             */
/*   Updated: 2021/09/17 15:19:34 by mde-figu         ###   ########.fr       */
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

size_t	lst_len(t_lst *ls)
{
	int		len;

	len = 0;
	while (ls && ++len)
		ls = ls->next;
	return (len);
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return ((void *)0);
	while (size)
		((unsigned char *)mem)[--size] = 0;
	return (mem);
}

void	ft_error_memory(void)
{
	write(2, "Memory allocated error.\n", 24);
	exit(1);
}
