NAME = fixedPoint

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
VALFLAGS = valgrind --leak-check=full --show-leak-kinds=all

SRC = main.cpp Fixed.cpp

OBJDIR = objs
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

GREEN = \033[1;32m
YELLOW = \033[33m
RESET = \033[0m

# ===================== RULES =====================

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Fixed Point is Ready!$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ===================== VALGRIND =====================

leak: re
	@echo "$(YELLOW)\nRunning Valgrind...$(RESET)"
	@$(VALFLAGS) ./$(NAME)

# ===================== CLEAN =====================

clean:
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)Clean done!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f test test.replace
	@echo "$(GREEN)Full clean done!$(RESET)"

re: fclean all

.PHONY: all clean fclean re leak