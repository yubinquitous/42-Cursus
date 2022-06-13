#ifndef LIBFT_H
#define LIBFT_H

char **ft_split(char const *s, char c);
int ft_isdigit(int c);
int ft_atoi(const char *str);
void free_all(char **str, int l);

#endif