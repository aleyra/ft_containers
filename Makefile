.PHONY: all clean fclean re bonus
# Name of file
NAME		=	minishell

# Name directory
PATH_INC	=	includes
PATH_SRC	=	srcs
PATH_OBJ	=	objs
PATH_LOG	=	logs


# List of sources
SRCS_TESTER		=	test_vector.cpp
SRCS			=	$(addprefix $(PATH_SRC)/tester/, $(SRCS_TESTER)) \
					$(addprefix $(PATH_SRC)/, )  main.cpp #add files à la racine

OBJS		=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRCS:.c=.o)))
ALL_INCS	=	enable_if.hpp equal.hpp is_integral.hpp iterators_traits.hpp make_pair.hpp map.hpp my_tests.hpp pair.hpp reverse_iterator.hpp vector.hpp
INCS		=	$(addprefix $(PATH_INC)/, $(ALL_INCS))

# Commands of compilation
COMP		=	c++
COMP_FLAG	=	-Wall -Wextra -Werror 
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

bonus :	all

$(NAME): 	$(OBJS)
			$(CC) $(COMP_FLAG) $(OBJS) -o $(NAME)

$(PATH_OBJ)/%.o : $(PATH_SRC)/*/%.cpp  $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
	@ echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.cpp  $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ $(RM) -rf $(NAME)

re: fclean all
