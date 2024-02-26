NAME 		= ex03

CCPP		= c++
RM			= rm -f
CLONE 		= git clone --depth=1

CPPFLAGS	+= -Wall -Wextra -Werror -std=c++98
CPPLINKS	=

SRC 		= bsp.cpp\
			  Fixed.cpp\
			  main.cpp\
			  Point.cpp

OBJ 		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CCPP) $(CPPFLAGS) -o $(NAME) $(OBJ) $(CPPLINKS)

%.o: %.cpp
	$(CCPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

fast: fclean
	$(MAKE) -j$$(nproc)

.PHONY:		all clean fclean re
