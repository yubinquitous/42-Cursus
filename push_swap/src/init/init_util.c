#include <stdlib.h>
#include "../../includes/push_swap.h"

int is_duplicate(int *data, int num, int cnt)
{
    int i;

    i = 0;
    while (++i < cnt)
    {
        if (data[i] == num)
            error_exit();
    }
    return 0;
}

void bubble_sort(int *data, int size)
{
    int i;
    int j;
    int temp;

    i = size + 1;
    while (--i > 0)
    {
        j = 0;
        while (++j < i)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int *data_cpy(int *data, int size)
{
    int i;
    int *ret;

    i = 0;
    ret = (int *)malloc(sizeof(int) * (size + 1));
    if (!ret)
        error_exit();
    ret[0] = -2147483648;
    while (++i < size + 1)
        ret[i] = data[i];
    return (ret);
}