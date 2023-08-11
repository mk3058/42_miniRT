CC = gcc
CFALGS = -Wall -Wextra -Werror
INC = ./
NAME = libft.a
SRCS = ft_isalnum.c ft_strrchr.c ft_isprint.c ft_strlcpy.c ft_tolower.c ft_isalpha.c ft_memchr.c \
ft_memset.c ft_strlen.c ft_toupper.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strncmp.c \
ft_bzero.c ft_isdigit.c ft_memcpy.c ft_strlcat.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_memmove.c
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstmap.c ft_lstiter.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(OBJS_BONUS)
	@rm -f all
	@touch bonus
	@ar rc $(NAME) $(OBJS_BONUS)

$(NAME) : $(OBJS)
	@rm -f bonus
	@touch all
	@ar rc $(NAME) $(OBJS)

.c.o :
	@$(CC) $(CFLAGS) -c -I $(INC) -o $@ $<

clean :
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean : clean
	@rm -f $(NAME)
	@rm -f all
	@rm -f bonus

re : fclean all

.PHONY : clean fclean re
