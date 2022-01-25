/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbekasov <vbekasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:00:13 by vbekasov          #+#    #+#             */
/*   Updated: 2022/01/21 05:31:34 by vbekasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_fun(int num, int rub, int *count)
{
	char	*str;
	int		tmp;

	str = ft_itoa(num);
	tmp = str_len(str);
	write(1, str, tmp);
	*count += tmp - 1;
	free(str);
	rub++;
}

void	uni_fun(size_t num, int rub, int *count)
{
	char	*str;
	int		tmp;

	str = ft_utoa(num);
	tmp = str_len(str);
	write(1, str, tmp);
	*count += tmp - 1;
	free(str);
	rub++;
}
