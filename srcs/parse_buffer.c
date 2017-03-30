/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:25:54 by huweber           #+#    #+#             */
/*   Updated: 2017/03/30 21:28:31 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			wnl(char *s, int size, t_env *e)
{
	int			i;

	i = 0;
	while (i < size)
	{
		e->b_disp[e->len] = s[i];
		e->len++;
		i++;
	}
}

void			wnil(int i, t_env *e)
{
	e->b_disp[e->len] = (char)i;
	e->len++;
}

void			wncl(char c, t_env *e)
{
	e->b_disp[e->len] = (char)c;
	e->len++;
}
