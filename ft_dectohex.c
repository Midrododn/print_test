/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbekasov <vbekasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:05:13 by vbekasov          #+#    #+#             */
/*   Updated: 2022/01/28 00:27:25 by vbekasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	sup_fun(size_t n, char *r_str, int up)
{
	int	tmp;
	int	pow;
	int	j;

	j = 0;
	pow = 16;
	up -= 89;
	up++;
	while (n > 0)
	{
		tmp = n % pow;
		if (tmp < 10)
			r_str[j] = tmp + 48;
		else
		{
			r_str[j] = tmp + 55 + up;
		}
		n = n / pow;
		j++;
	}
	return (j);
}

void	dec_to_hex(size_t n, int up, int *rub, int *count)
{
	char	r_str[25];
	int		tmp;

	*rub += 1;
	ft_memset(r_str, '\0', 25);
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	r_str[sup_fun(n, r_str, up)] = '\0';
	sup_reverse_string(r_str);
	tmp = str_len(r_str);
	write(1, r_str, tmp);
	*count += tmp - 1;
}

void	point_fun(void *adr, int rub, int *count)
{
	if (adr != 0x00)
	{
		write(1, "0x", 2);
		*count += 2;
		dec_to_hex((long long int)adr, 'x', &rub, count);
	}
	else
	{
		write(1, "0x0", 3);
		*count += 2;
	}
}
