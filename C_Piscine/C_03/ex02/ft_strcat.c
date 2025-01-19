char    *ft_strcat(char *dest, char *src)
{
    int dest_i;
    int src_i;

    dest_i = 0;
    src_i = 0;
    while (dest[dest_i])
    {
            dest_i++;
    }    
    while (src[src_i])
    {
        dest[dest_i] = src[src_i];
        dest_i++;
        src_i++;
    }
    dest[dest_i] = '\0';
    return (dest);
}
#include <stdio.h>
int main(void)
{
    char    dest[100] = "Hello ";
    char    *src = "World!";

    ft_strcat(dest, src);
    printf("%s\n", dest);
    return (0);
}