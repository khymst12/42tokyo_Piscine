#include <unistd.h>


void    ft_print_program_name(char *name)
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
   (void)argc;
   ft_print_program_name(argv[0]);
   return (0);
}
