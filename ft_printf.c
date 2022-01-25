/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbekasov <vbekasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:03:26 by vbekasov          #+#    #+#             */
/*   Updated: 2022/01/24 18:39:27 by vbekasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	sup_int_fun(char fun_char, int arg, int *rub)
{
	int	count;

	count = 0;
	if (fun_char == 'c')
		char_fun(arg, 1, &count);
	else if (fun_char == 'i' || fun_char == 'd')
		int_fun(arg, 1, &count);
	*rub += 1;
	return (count);
}

static int	sup_void_fun(char char_fun, void *arg, int *i)
{
	int	count;

	count = 0;
	if (char_fun == 's')
		str_fun(arg, 1, &count);
	else if (char_fun == 'p')
		point_fun(arg, 1, &count);
	*i += 1;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else if (str[i +1] == '%')
			write(1, &str[++i], 1);
		else if (str[i +1] == 'c' || str[i +1] == 'i' || str[i +1] == 'd')
			count += sup_int_fun(str[i +1], va_arg(args, int), &i);
		else if (str[i +1] == 's' || str[i +1] == 'p')
			count += sup_void_fun(str[i +1], va_arg(args, void *), &i);
		else if (str[i +1] == 'u')
			uni_fun(va_arg(args, size_t), ++i, &count);
		else if (str[i +1] == 'x' || str[i +1] == 'X')
			dec_to_hex(va_arg(args, long long int), (int)str[i +1], &i, &count);
		count++;
	}
	va_end(args);
	return (count);
}
