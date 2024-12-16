NAME	= a.out
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= \
	main.cpp \
	Fixed.cpp
OBJS	= $(SRCS:.cpp=.o)
INCLUDE	= -I./

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)


re: fclean all

build: all clean

__debug_configure__:
	$(eval CC := c++)
	$(eval CFLAGS := -g -fsanitize=address -Wall -Wextra -Werror -std=c++98 -pedantic)

debug: __debug_configure__ all

.PHONY: all clean fclean re build debug __debug_configure__ norminette norm
