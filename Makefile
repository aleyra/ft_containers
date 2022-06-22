.PHONY: all clean fclean re
# Name of file
NAME		=	containers

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs

#List of sources
SRCS_TEST	=	test_vector.cpp
SRCS		=	$(addprefix $(PATH_SRC)/tester/, $(SRCS_TEST)) \
				$(addprefix $(PATH_SRC)/, ) main.cpp

OBJS		=	$(addprefix $(PATH_OBJ)/, $(SRCS:.cpp=.o))

INCS_CONT	=	map.hpp vector.hpp
INCS_OTHER	=	enable_if.hpp iterators_traits.hpp pair.hpp equal.hpp \
				make_pair.hpp reverse_iterator.hpp is_integral.hpp
MY_INC		=	my_tests.hpp
INCS		=	$(addprefix $(PATH_INC), $(INCS_CONT)) \
				$(addprefix $(PATH_INC), $(INCS_OTHER)) \
				$(addprefix $(PATH_INC), $(MY_INC))

# Commands of compilation
COMP		=	c++
COMP_FLAG	=	-Wall -Werror -Wextra -std=c++98
COMP_ADD	=	-I$(PATH_INC)

# Others Command
RM			=	/bin/rm

# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
		@ echo "$(_SUCCESS) Compilation done"

init:
		$(shell mkdir -p $(PATH_OBJ))

bonus : all

$(NAME):	$(OBJS)
				$(COMP) $(COMP_FLAG) $(OBJS) -o $(NAME)

$(PATH_OBJ)/%.o : $(PATH_SRC)/*/%.cpp  $(INCS)
		@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
		@ echo "$(_INFO) Compilation of $*"
$(PATH_OBJ)/%.o : $(PATH_SRC)/%.cpp  $(INCS)
		@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
		@ echo "$(_INFO) Compilation of $*"

clean:
		@ $(RM) -rf $(PATH_OBJ)
		@ echo "$(_INFO) Deleted files and directory"

fclean: clean
		@ $(RM) -rf $(NAME)

re: fclean all
