#include <unistd.h>

void    ft_print_params(char *name)
{
   while (*name)
   {
       write(1, name, 1);
       name++;
   }
   write(1, &"\n", 1);
}


int main(int argc, char *argv[])
{
   int i;


   i = argc - 1;
   while (i > 0)
   {
       ft_print_params(argv[i]);
       i--;
   }
   return (0);
}
