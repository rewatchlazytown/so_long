NAME		=	libft.a

CC			=	gcc

CFILE		=	ft_atoi.c		\
				ft_isdigit.c	\
				ft_itoa.c		\
				ft_putchar.c	\
				ft_putstr.c		\
				ft_split.c		\
				ft_strchr.c		\
				ft_strdup.c		\
				ft_strjoin.c	\
				ft_strlen.c		\
				ft_strncpy.c	\
				ft_gnl.c		\

CFILE_DIR		=	./src/

SRC				=	$(addprefix $(CFILE_DIR), $(CFILE))

INCLUDE_DIR		=	./includes/

FLAG			=	-Wall -Wextra -Werror

INCLUDE			=	libft.h

OBJ				=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
