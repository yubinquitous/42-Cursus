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

#endif