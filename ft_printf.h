/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbekasov <vbekasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:00:43 by vbekasov          #+#    #+#             */
/*   Updated: 2022/01/24 18:36:29 by vbekasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		str_len(const char *str);
char	*ft_itoa(const int n);
char	*ft_utoa(const size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	sup_reverse_string(char *s);
int		char_fun(char t, int rub, int *count);
int		str_fun(char *c, int rub, int *count);
void	int_fun(int num, int rub, int *count);
void	uni_fun(size_t num, int rub, int *count);
void	dec_to_hex(size_t n, int up, int *rub, int *count);
void	point_fun(void *adr, int rub, int *count);

#endif