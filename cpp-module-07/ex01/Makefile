SRCS = main.cpp

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = iter

CXX = c++

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all