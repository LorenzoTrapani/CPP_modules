NAME = DiamondTrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -g
SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp 

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re