/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:26:36 by huweber           #+#    #+#             */
/*   Updated: 2017/04/03 15:27:32 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>
# define TRUE 1
# define FALSE 0
# define BSIZE 5000

typedef struct		s_flag
{
	int				zero;
	int				plus;
	int				min;
	int				pres;
	int				ispres;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
	int				hash;
	int				space;
	int				skip;
	int				si;
}					t_flag;

typedef struct		s_env
{
	int				nbargs;
	int				currconv;
	char			*b;
	char			*b_disp;
	int				i_disp;
	char			type;
	int				len;
	int				pad;
	struct s_flag	*fl;
}					t_env;

void				pad_left(intmax_t nb, t_env *e);
void				pad_right(t_env *e);
int					put_simple(const char *s, t_env *e);
int					get_nbconv(const char *format);
void				reset_specs(t_flag *fl);
void				wnl(char *s, int size, t_env *e);
void				wnil(int i, t_env *e);
void				wncl(char c, t_env *e);
void				get_next_conv(t_env *e);
void				get_wrong_conv(t_env *e);
int					check_conv(char c);
int					wrong_char(char c);
int					get_precision(t_env *e, int i);
int					parse_handler3(t_flag *fl, char c, char cc);
int					parse_handler2(t_env *e, int i);
int					parse_handler(t_env *e, t_flag *fl);
int					get_nb_len(intmax_t nb, int basesize, t_env *e);
void				pad_left2(intmax_t nb, t_env *e);
void				pad_left(intmax_t nb, t_env *e);
void				pad_right(t_env *e);
void				put_sign(char c, t_env *e);
int					put_sign2(intmax_t nb, t_env *e, int nlen);
void				put_precision(intmax_t nb, int nlen, t_env *e);
int					put_pad_hex(uintmax_t nb, t_env *e, uintmax_t nlen);
int					put_pad_l(long int nb, t_env *e, int flag, int nlen);
int					put_pad_int(intmax_t nb, t_env *e, int nlen);
int					put_pad_p(uintmax_t nb, t_env *e, int nlen);
void				ft_putnbr_base(intmax_t nb, char *base, t_env *e);
void				ft_putnbr_oct(uintmax_t nb, char *base, t_env *e);
void				ft_putnbr_umax(uintmax_t nb,
							char *base, t_env *e, int flag);
void				ft_putnbr_l(long int nb, char *base, t_env *e, int flag);
void				ft_putnbr_slong(long long nb, char *base, t_env *e);
void				ft_putnbr_long(long int nb, char *base, t_env *e, int flag);
void				put_hash(t_env *e, intmax_t nb);
void				ft_putnbr_hex(uintmax_t nb, char *base, t_env *e);
void				ft_putnbr_p(uintmax_t nb, char *base, t_env *e);
void				handler_hexa2(unsigned long long nb, t_env *e);
void				handler_hexa(uintmax_t nb, t_env *e);
void				handler_unsigned(uintmax_t nb, t_env *e);
void				handler_octal(uintmax_t nb, t_env *e);
void				handler_int(intmax_t nb, t_env *e);
int					wchar_to_c(wchar_t c, t_env *e);
int					wchar_to_c2(wchar_t c, t_env *e);
void				pad_str(t_env *e);
void				handler_string(char *s, t_env *e);
void				set_flags(t_env *e);
int					ft_wcrlen(wchar_t *s);
int					get_wide_size(wchar_t *s, t_env *e);
int					sub_size(wchar_t c);
void				handler_wstring(wchar_t *s, t_env *e);
void				handler_char(int c, t_env *e);
void				handler_wchar(wchar_t c, t_env *e);
void				handler_fork(va_list va, t_env *e);
void				parse_conv(va_list va, t_env *e);
int					init_env(const char *format, t_env *e);
void				free_env(va_list va, t_env *e);
int					ft_printf(const char *format, ...);

#endif
