#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i;
    int size;
   
    i = 0;
    if (min >= max)
    {
        *range = NULL;
        return (0);
    }
    size = max - min;
    *range = (int *)malloc((size) * sizeof(int));
    if (*range == NULL)
        return (-1);
    while (min < max)
    {
        (*range)[i] = min;
        i++;
        min++;
    }
    return (size);
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    (void)argc;
    int *range;
    int i;

    i = ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2]));
    printf("%d\n", i);
}
