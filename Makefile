#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huweber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 16:21:27 by huweber           #+#    #+#              #
#    Updated: 2017/03/30 21:29:14 by huweber          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libftprintf.a

SRCS	= 	libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c\
			libft/ft_memccpy.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_memcmp.c\
			libft/ft_strlen.c libft/ft_strdup.c libft/ft_strcpy.c libft/ft_strncpy.c\
			libft/ft_strcat.c libft/ft_strncat.c libft/ft_strlcat.c libft/ft_strchr.c\
			libft/ft_strrchr.c libft/ft_strstr.c libft/ft_strnstr.c libft/ft_strcmp.c\
			libft/ft_strncmp.c libft/ft_atoi.c libft/ft_isalpha.c libft/ft_isdigit.c\
			libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_toupper.c\
			libft/ft_tolower.c libft/ft_memalloc.c libft/ft_memdel.c libft/ft_strnew.c libft/ft_strdel.c\
			libft/ft_strclr.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strmap.c libft/ft_strmapi.c\
			libft/ft_strequ.c libft/ft_strnequ.c libft/ft_strsub.c libft/ft_strjoin.c libft/ft_strtrim.c\
			libft/ft_strsplit.c libft/ft_itoa.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_putendl.c\
			libft/ft_putnbr.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c\
			libft/ft_lstnew.c libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstadd.c libft/ft_lstiter.c\
			libft/ft_lstmap.c libft/ft_btree_apply_infix.c libft/ft_btree_apply_prefix.c\
			libft/ft_btree_apply_suffix.c libft/ft_btree_create_node.c libft/ft_btree_level_count.c\
			libft/ft_btree_search_item.c libft/ft_max.c libft/ft_swap.c libft/ft_realloc.c libft/get_next_line.c\
			libft/ft_abs.c\
			srcs/check_conv.c srcs/handler_hexa.c srcs/handler_int.c\
			srcs/handler_char_str.c srcs/handler_long.c srcs/handler_octal.c\
			srcs/handler_w_str.c srcs/handler_wchar.c srcs/init_env.c srcs/ft_printf.c srcs/parse_buffer.c\
			srcs/put_precision_padding.c srcs/parse_handler.c srcs/misc.c

LIBFT	= -L ./libft -l ft

LFT		= libft/libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror $(INC)

INC		= -I ./includes/ -I ./libft/includes/

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar -rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(LFT)
		rm -rf $(NAME)

re:	fclean all
