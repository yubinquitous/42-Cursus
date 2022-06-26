/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubchoi <yubchoi@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:39:37 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/16 14:15:20 by yubchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

char	**ft_split(char const *s, char c);
int		ft_issign(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	free_all(char **str, int l);

#endif
