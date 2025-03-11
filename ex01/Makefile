# Project Name
NAME		=	$(BIN_DIR)/harl
# Directories
SRC_DIR		=	src
BUILD_DIR	=	build
BIN_DIR		=	bin

# Source & Object Files
SRCS		=	$(wildcard $(SRC_DIR)/*.cpp)
OBJS		=	$(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Compiler & Flags
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++17

# Bold Colors
BLACK	= \033[1;30m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
MAGENT	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m
CLEAR	= \033[0m# Reset color

# Default Rule
all: $(BIN_DIR) $(BUILD_DIR) $(NAME)

# Compile Executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅$(notdir $(NAME)) Compiled!$(CLEAR)"

# Compile Object Files in build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create Directories if not exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile Rule && Run
run: all
	@echo "$(BLUE)$(notdir $(NAME)) $(RED)&& $(YELLOW)Executed: 👇$(CLEAR)"
	./$(NAME) $(ARGS)

valgrind: all
	@echo "$(BLUE)$(notdir $(NAME)) 🦹‍♂️\033[47mMr.Valgrind$(CLEAR) is here!💪"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 
	# --verbose for more info

# Cleaning Rules
clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -rf $(BIN_DIR)
	@echo "$(MAGENT)🧹$(notdir $(NAME)) Cleaning!$(CLEAR)"

re: fclean all

# Ignore File Name Conflicts
.PHONY: all run clean fclean re
