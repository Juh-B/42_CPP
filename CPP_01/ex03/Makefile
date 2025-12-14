NAME = unnecessaryViolence

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
ASANFLAGS = -fsanitize=address -g

SRC = ./main.cpp ./HumanA.cpp ./HumanB.cpp ./Weapon.cpp

OBJDIR = objs
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

GREEN = \033[1;32m
YELLOW = \033[33m
RESET = \033[0m

# ===================== RULES =====================

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Unnecessary Violence is Ready!$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ===================== LEAK =====================

leak: CFLAGS += $(ASANFLAGS)
leak: fclean $(OBJ) $(NAME)
	@echo "$(YELLOW)\nRunning with AddressSanitizer...$(RESET)"
	@./$(NAME)

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
