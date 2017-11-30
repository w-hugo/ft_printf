/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:45:23 by huweber           #+#    #+#             */
/*   Updated: 2017/01/30 16:45:01 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int					free_all(t_list **lst, int fd, char **line, char *tmp)
{
	t_gnl			*gnl;
	t_list			**temp;
	t_list			*ptr;

	ft_strdel(&tmp);
	ft_strdel(line);
	temp = lst;
	while (*temp)
	{
		gnl = (t_gnl *)((*temp)->content);
		if (gnl->fd == fd)
			break ;
		*temp = ((*temp)->next);
	}
	if (*temp)
	{
		ptr = (*temp)->next;
		if (gnl->save)
			ft_strdel(&(gnl->save));
		ft_memdel((void **)&gnl);
		ft_memdel((void **)temp);
		*temp = ptr;
	}
	return (0);
}

t_gnl				*init_gnl(t_list **lst, int fd)
{
	t_gnl			*gnl;
	t_list			*temp;

	temp = *lst;
	while (temp)
	{
		gnl = (t_gnl *)(temp->content);
		if (gnl->fd == fd)
			return (gnl);
		temp = temp->next;
	}
	if (!(gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	gnl->fd = fd;
	gnl->eof = 0;
	gnl->len = BUFF_SIZE;
	if (!(gnl->save = ft_strnew(gnl->len))
		|| !(temp = ft_lstnew(gnl, sizeof(t_gnl))))
		return (NULL);
	ft_memdel((void **)&gnl);
	ft_lstadd(lst, temp);
	return ((t_gnl *)(temp->content));
}

int					parse_line(t_gnl *gnl, char **line, char *tmp)
{
	int				i;

	i = -1;
	if (!(tmp = ft_strnew(gnl->len)))
		return (-1);
	while (gnl->save[++i] != '\n' && gnl->save[i] != '\0')
		tmp[i] = gnl->save[i];
	gnl->save = ft_strcpy(gnl->save, &gnl->save[i + 1]);
	if (!(*line = ft_strdup(tmp)))
		return (-1);
	if (tmp[0] != '\0')
		return (1);
	return (0);
}

int					read_line(t_gnl *gnl, char **line, char *tmp)
{
	int				nb_read;
	int				ret;

	while (!ft_strchr(gnl->save, '\n')
		&& (nb_read = read(gnl->fd, tmp, BUFF_SIZE)) > 0)
	{
		gnl->len += nb_read;
		gnl->save = ft_realloc((void **)gnl->save, gnl->len);
		gnl->save = ft_strcat(gnl->save, tmp);
		ft_strclr(tmp);
	}
	if (nb_read < 0)
		return (-1);
	ret = parse_line(gnl, line, tmp);
	if (nb_read == 0 || (ret == 0 && nb_read == 0))
	{
		gnl->eof = 1;
		if (ret == 0)
			return (0);
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_gnl			*gnl;
	char			*tmp;
	int				ret;

	ret = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1 || !(gnl = init_gnl(&lst, fd)))
		return (-1);
	if (!(tmp = ft_strnew(gnl->len)))
		return (-1);
	if (!gnl->eof)
		ret = read_line(gnl, line, tmp);
	else
		return (free_all(&lst, fd, line, tmp));
	if (ret == 0)
		free_all(&lst, fd, line, tmp);
	return (ret);
}
