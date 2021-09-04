DFL			= perms
TEST		= test

SRCS		= 
TEST_SRCS	= ft_print_perms.cpp tester.cpp
OBJS		= $(SRCS:.cpp=.o)
TEST_OBJS	= $(TEST_SRCS:.cpp=.o)
CC			= clang++
FLAGS		= -Wall -Wextra -Werror

ifeq ($(OS), Windows_NT)
	RM		= del /f /q >nul 2>&1
else
	RM		= rm -rf
endif

all: $(DFL)

$(DFL): $(OBJS)
	@$(CC) $(OBJS) $(FLAGS) -o $(DFL)

test: $(TEST_OBJS)
	@$(CC) $(FLAGS) $(TEST_OBJS)  -o $(TEST)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(TEST_OBJS)

ifeq ($(OS), Windows_NT)
fclean: clean
	@$(RM) $(addsuffix .exe,$(DFL))
	@$(RM) $(addsuffix .exe,$(TEST))
else
fclean: clean
	@$(RM) $(DFL)
	@$(RM) $(TEST)
endif

re: fclean all

.PHONY: clean fclean re all