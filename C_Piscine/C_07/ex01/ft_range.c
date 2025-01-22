#include <stdlib.h>
int *ft_range(int min, int max)
{
    int *num;
    int i;

    i = 0;
    if (min >= max)
        return (NULL);
    num = (int *)malloc((max - min + 1) * sizeof(int));
    if (num == NULL)
        return (NULL);
    while (min < max)
    {
        num[i] = min;
        i++;
        min++;
    }
    return (num);
}

#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int *num;
    int i = 0;
    int size = 19 - 10;

    num = ft_range(10, 19);
    while(i < size)
    {
        printf("%d ", num[i]);
        i++;
    }
    return (0);
}