NAME = avm

#-----------------------------------------#
# Sources

SRC = 	sources/main.cpp\
		sources/Token.cpp

#-----------------------------------------#
# Objects

OBJDIR = objs
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
DEP = $(OBJ:.o=.d)


#-----------------------------------------#
# Compiler

CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -MMD -MP -std=c++11
INC = -I./includes


#-----------------------------------------#
# Colors

ORANGE = \033[38;5;208m
RED    = \033[31m
GREEN  = \033[32m
RESET  = \033[0m

#-----------------------------------------#
# Rules

all: $(NAME)
	@echo "$(GREEN)Done!$(RESET)"

$(NAME): $(OBJ) 
	@$(CXX) $(CXXFLAGS) $(INC) $^ -o $@

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(GREEN)Project compiling : $<$(RESET)"
	@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@


clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all re clean fclean 