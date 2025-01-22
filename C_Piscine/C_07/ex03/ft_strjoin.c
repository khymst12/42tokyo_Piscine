#include <stdlib.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char *ft_strcpy(char *dest, char *src)
{
    while ((*dest++ = *src++));
    return dest - 1;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i = 0;
    int total_len = 0;
    int sep_len = ft_strlen(sep);

    while (i < size)
    {
        total_len += ft_strlen(strs[i]);
        i++;
    }
    total_len += sep_len * (size - 1);
    char *result = (char *)malloc(total_len + 1);
    if (!result)
        return NULL;

    char *current = result;
    i = 0;
    while (i < size)
    {
        current = ft_strcpy(current, strs[i]);
        if (i < size - 1)
            current = ft_strcpy(current, sep);
        i++;
    }
    *current = '\0';
    return result;
}

#include <stdio.h>
int main(void)
{
    char *strs[] = {"abc", "def", "ghi"};
    char *sep = "";
    char *result = ft_strjoin(0, strs, sep);

    if (result)
    {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}