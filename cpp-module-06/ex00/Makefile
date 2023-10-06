SRCS = main.cpp Convert.cpp

CXXFLAGS =  -Wall -Werror -Wextra -std=c++98

NAME = convert

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
