#include "ft_printf.h"

int	ft_strlen(char* s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

char* ft_strchr(char* s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		++s;
	}
	if (*s == (char)c)
		return (s);
	return (NULL);
}

int	ft_putchar(char c)
{
	return ((int)write(fd, &c, 1));
}

int	ft_putstr(char* s)
{
	int	len;

	len = ft_strlen(s);
	return ((int)write(fd, s, len));
}