/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbekasov <vbekasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:56:01 by vbekasov          #+#    #+#             */
/*   Updated: 2022/01/21 07:07:08 by vbekasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	sup_mimax_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static void	sup_itoa(int n, char *ret)
{
	int		power;
	int		sign;
	int		i;

	sign = sup_mimax_sign(n);
	ret[0] = (n % 10) * sign + '0';
	n = (n / 10) * sign;
	i = 0;
	power = 1;
	while ((n / power) > 0)
	{
		ret[++i] = (n / power) % 10 + '0';
		power *= 10;
	}
	if (sign < 0)
		ret[++i] = '-';
	sup_reverse_string(ret);
}

char	*ft_itoa(const int n)
{
	char	*ret;
	char	tmp[12];
	int		i;

	ft_memset(tmp, '\0', 12);
	sup_itoa(n, tmp);
	ret = (char *)malloc(sizeof(char) * (str_len(tmp) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (tmp[i] != '\0')
	{
		ret[i] = tmp[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
