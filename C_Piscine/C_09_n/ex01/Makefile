# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyamashi <kyamashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 14:23:21 by kyamashi          #+#    #+#              #
#    Updated: 2025/01/29 16:05:20 by kyamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
OBJDIR = srcs
INCDIR = includes
LIBNAME = libft.a

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(LIBNAME)
$(LIBNAME): $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re
