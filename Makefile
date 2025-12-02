# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrgarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 09:49:50 by gabrgarc          #+#    #+#              #
#    Updated: 2025/12/02 17:12:00 by gabrgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror -Iincludes

SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_issignal.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_atol.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_revsplit.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_itoa_base.c \
	ft_uitoa_base.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

SRCS_GNL = \
	get_next_line.c \
	get_next_line_utils.c

SRCS_PRINTF = \
	ft_printf.c \
	ft_aux_chrs.c \
	ft_aux_nbrs.c \
	ft_aux_ptr.c \
	printf_utils.c \
	flags_utils.c \
	padded.c

OBJSDIR = objdir
GNLDIR = get_next_line
PRINTFDIR = ft_printf

OBJS = $(SRCS:%.c=$(OBJSDIR)/%.o)
OBJS_GNL = $(SRCS_GNL:%.c=$(OBJSDIR)/%.o)
OBJS_PRINTF = $(SRCS_PRINTF:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
	ar rcs $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)

$(OBJSDIR)/%.o: %.c | $(OBJSDIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJSDIR)/%.o: $(GNLDIR)/%.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR)/%.o: $(PRINTFDIR)/%.c | $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
