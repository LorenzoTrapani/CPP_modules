NAME = Real
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRCS = main.cpp \
		Base.cpp \

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re