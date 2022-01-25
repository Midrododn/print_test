/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbekasov <vbekasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:05:47 by vbekasov          #+#    #+#             */
/*   Updated: 2022/01/24 18:37:41 by vbekasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	str_len(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ret;
	int		i;

	i = -1;
	ret = (char *)str;
	n++;
	while (--n)
		ret[++i] = c;
	return (ret);
}

int	char_fun(char t, int rub, int *count)
{
	write(1, &t, 1);
	rub++;
	*count += 0;
	return (*count);
}

int	str_fun(char *c, int rub, int *count)
{
	int	tmp;

	tmp = str_len(c);
	if (c)
	{
		write(1, c, tmp);
		*count += tmp - 1;
	}
	else
	{
		write(1, "(null)", 6);
		*count += 5;
	}
	rub++;
	return (*count);
}

void	sup_reverse_string(char *s)
{
	char	tmp;
	int		l;
	int		i;
	int		half;

	l = str_len(s);
	i = -1;
	half = l / 2;
	while (++i < half)
	{
		tmp = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = tmp;
	}
	s[l] = '\0';
}
