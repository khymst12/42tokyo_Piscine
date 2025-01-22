#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void ft_sort_params(int argc, char *argv[])
{
    int i;
    int j;
    char *tmp;

    j = 1;
    while (j < argc - 1) 
    {
        i = 1;
        while (i < argc - j) 
        {
            if (ft_strcmp(argv[i], argv[i + 1]) > 0)
            {
                tmp = argv[i];
                argv[i] = argv[i + 1];
                argv[i + 1] = tmp;
            }
            i++;
        }
        j++;
    }
}

void ft_print_params(char *name)
{
    while (*name) 
    {
        write(1, name, 1);
        name++;
    }
    write(1, "\n", 1);
}

int main(int argc, char *argv[])
{
    int i;

    i = 1;
    if (argc > 1)
    {
        ft_sort_params(argc, argv);
        while (i < argc)
        {
            ft_print_params(argv[i]);
            i++;
        }
    }
    return 0;
}
