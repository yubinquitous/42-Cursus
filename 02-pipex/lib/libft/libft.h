/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:40:38 by yubchoi           #+#    #+#             */
/*   Updated: 2022/07/01 13:40:39 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

char *ft_strdup(const char *s1);
int ft_strncmp(char *s1, char *s2, int n);
void ft_putendl_fd(char *s, int fd);
int ft_strlen(const char *s);
char **ft_split(char *s, char c);
int ft_strlcat(char *dst, char *src, int dstsize);
int ft_strlcpy(char *dst, char *src, int dstsize);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(char *s, int c);

#endif