# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haelee <haelee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 17:19:08 by haelee            #+#    #+#              #
#    Updated: 2020/11/28 22:11:45 by haelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RFLAGS = rm -f
ARFLAGS = ar -cr

NAME = libft.a
SRCS = ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
	   ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
	   ft_calloc.c ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c \
	   ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_split.c ft_itoa.c \

BON_S = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c \
		ft_lstiter.c ft_lstclear.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BON_O = $(BON_S:.c=.o)

all : $(NAME)

.PHONY: all clean fclean re bonus

%.o : %.c
		$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS)
		$(ARFLAGS) $(NAME) $(OBJS)

bonus : $(BON_O)
		$(ARFLAGS) $(NAME) $(BON_O)

clean :
		$(RFLAGS) $(OBJS) $(BON_O)

fclean : clean
		$(RFLAGS) $(NAME)

re : fclean all
