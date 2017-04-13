/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:12:24 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/01 21:09:36 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_type
{
	unsigned long long int	u;
	long long				d;
	unsigned int			c;
	va_list					arguments;
	char					*s;
	int						count;
	int						len_return;
	char					conv;
	char					*print;
	int						i;
	int						j;
	int						fd;
}				t_conv;

/*
 ** ft_printf.c
*/
void			len_return(t_conv *t);
void			printstr(const char *s, t_conv *t);
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
void			get_conv(const char *s, t_conv *t);

/*
 ** ft_checkconv.c
*/
void			which_conv(const char *s, int i, t_conv *t);

/*
 ** ft_conv_u.c
*/
void			conv_u(t_conv *t);

/*
 ** ft_conv_s.c
*/
void			conv_s(t_conv *t);

/*
 ** ft_utils.c
*/
int				ft_len_int(long int nbr);
char			next_conv(const char *s, int i);
void			init(t_conv *t);
void			init_start(t_conv *t);

/*
 ** ft_conv_d.c
*/
void			conv_d(t_conv *t);

/*
 ** ft_conv_c.c
*/
void			conv_c(t_conv *t);

#endif
