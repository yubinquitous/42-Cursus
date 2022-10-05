#include <stdarg.h>
#include <unistd.h>

int ft_print_s(char *str)
{
    int i = -1;
    if (!str)
        str = "(null)";
    else
    {
        while (str[++i])
            write(1, &str[i], 1);
    }
    return (i);
}

int ft_print_x(unsigned int i, int base)
{
    char *arr = "0123456789abcdef";
    int cnt = 0;
    int n = i % base;

    if (i / base != 0)
        cnt += ft_print_x(i / base, base);
    write(1, &(arr[n]), 1);
    ++cnt;
    return (cnt);
}

int ft_print_d(int i)
{
    int cnt = 0;

    if (i == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }
    if (i < 0)
    {
        write(1, "-", 1);
        i *= -1;
        ++cnt;
    }
    cnt += ft_print_x(i, 10);
    return (cnt);
}

int ft_print_percent(void)
{
    write(1, "%", 1);
    return (1);
}

int ft_printf(char *string, ...)
{
    int cnt = 0;
    va_list args;
    int i = 0;

    va_start(args, string);
    while (string[i])
    {
        if (string[i] == '%')
        {
            ++i;
            if (string[i] == 's')
                cnt += ft_print_s(va_arg(args, char *));
            else if (string[i] == 'd')
                cnt += ft_print_d(va_arg(args, int));
            else if (string[i] == 'x')
                cnt += ft_print_x(va_arg(args, unsigned int), 16);
            else
                cnt += ft_print_percent();
        }
        else
        {
            write(1, &string[i], 1);
            ++cnt;
        }
        ++i;
    }
    va_end(args);
    return (cnt);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("ft : %d\n", ft_printf("%s ", "hello"));
    printf("pt : %d\n", printf("%s ", "hello"));

    printf("ft : %d\n", ft_printf("%d ", INT_MAX));
    printf("pt : %d\n", printf("%d ", INT_MAX));

    printf("ft : %d\n", ft_printf("%d ", INT_MIN));
    printf("pt : %d\n", printf("%d ", INT_MIN));

    printf("ft : %d\n", ft_printf("%x ", 10));
    printf("pt : %d\n", printf("%x ", 10));

    printf("ft : %d\n", ft_printf("%x ", UINT_MAX));
    printf("pt : %d\n", printf("%x ", UINT_MAX));

    printf("ft : %d\n", ft_printf("%x ", 0));
    printf("pt : %d\n", printf("%x ", 0));
    return (0);
}