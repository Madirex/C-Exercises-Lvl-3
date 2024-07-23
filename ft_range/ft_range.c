#include <stdlib.h>

int abs_int(int n)
{
    if (n < 0)
        return (n * -1);
    return (n);
}

int     *ft_range(int start, int end)
{
    int len = abs_int(start - end) + 1;
    int *res = malloc(len * sizeof(int));
    int i = 0;
    
    if (!res)
        return (NULL);
    while (i < len)
    {
        res[i] = start;
        if (start < end)
            start++;
        else
            start--;
        i++;
    }
    return (res);
}