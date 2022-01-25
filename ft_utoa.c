/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbekasov <vbekasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:56:01 by vbekasov          #+#    #+#             */
/*   Updated: 2022/01/21 05:24:01 by vbekasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static void	sup_utoa(size_t n, char *ret)
{
	int		power;
	int		i;

	ret[0] = (n % 10) + '0';
	n = (n / 10);
	i = 0;
	power = 1;
	while ((n / power) > 0)
	{
		ret[++i] = (n / power) % 10 + '0';
		power *= 10;
	}
	sup_reverse_string(ret);
}

char	*ft_utoa(const size_t n)
{
	char	*ret;
	char	tmp[12];
	int		i;

	ft_memset(tmp, '\0', 12);
	sup_utoa(n, tmp);
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
