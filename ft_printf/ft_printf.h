/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:06:19 by yubchoi           #+#    #+#             */
/*   Updated: 2022/01/01 15:42:44 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define ERR -1

int		ft_printf(const char *arg, ...);
int		parse_arg(va_list ap, char *arg);
int		check_format(va_list ap, char type, int *nprintf);

int		print_nbr(char type, unsigned long nbr);
char	*check_base(char type);
int		ft_put_nbr(char type, unsigned long nbr, char *base);

int		print_str(char *str);
int		print_char(char c);

int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
int		ft_putchar(char c);
int		ft_putstr(char *s);

#endif
