NAME = unnecessaryViolence

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
ASANFLAGS = -fsanitize=address -g

SRC = ./main.cpp ./HumanA.cpp ./HumanB.cpp ./Weapon.cpp

OBJDIR = objs
OBJ = $(SRC:.cpp=.o)

GREEN = \033[1;32m
YELLOW = \033[33m
RESET = \033[0m

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	$(CC) $(CPPFLAGS) -o $(NAME) $(addprefix $(OBJDIR)/, $(OBJ))
	@echo "$(GREEN)Zombie Brain is Ready!$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

leak: CPPFLAGS += $(ASANFLAGS)
leak: fclean all
	@echo "$(YELLOW)\nRunning with AddressSanitizer...$(RESET)"
	@./$(NAME)

clean:
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)Clean done!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean done!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
