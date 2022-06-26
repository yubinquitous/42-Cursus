/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:37:06 by yubchoi           #+#    #+#             */
/*   Updated: 2021/12/13 21:17:46 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_lst	*find_fd(t_lst	*head, int fd)
{
	t_lst	*lst;

	lst = head->next;
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->fd = fd;
	lst->prev = head;
	lst->next = head->next;
	if (head->next)
		head->next->prev = lst;
	head->next = lst;
	lst->save = NULL;
	return (lst);
}

char	*read_file(int fd, char *save)
{
	ssize_t	nread;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	nread = read(fd, buf, BUFFER_SIZE);
	while (nread > 0)
	{
		buf[nread] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(save, '\n') || !save)
			break ;
		nread = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	buf = NULL;
	if (nread < 0)
		return (NULL);
	return (save);
}

char	*get_line(char *save)
{
	char	*line;
	size_t	i;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
		++i;
	if (save[i] == '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		line[i] = save[i];
		++i;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*return_line(t_lst	**tmp)
{
	char	*save_tmp;
	char	*line;
	t_lst	*lst;

	lst = *tmp;
	if (!(lst->save))
		return (NULL);
	else if (!*(lst->save))
	{
		free(lst->save);
		lst->save = NULL;
		return (NULL);
	}
	line = get_line(lst->save);
	if (!line)
		return (NULL);
	save_tmp = lst->save;
	lst->save = ft_strdup(lst->save + ft_strlen(line));
	free(save_tmp);
	save_tmp = NULL;
	if (!lst->save)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_lst	head;
	t_lst			*lst;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	lst = find_fd(&head, fd);
	if (!lst)
		return (NULL);
	lst->save = read_file(fd, lst->save);
	line = return_line(&lst);
	if (!line)
	{
		lst->prev->next = lst->next;
		if (lst->next)
			lst->next->prev = lst->prev;
		free(lst);
		lst = NULL;
	}
	return (line);
}
