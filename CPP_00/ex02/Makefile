NAME = account

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ./Account.cpp tests.cpp

OBJDIR = objs
OBJ = $(SRC:.cpp=.o)

GREEN = \033[1;32m
RESET = \033[0m

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	$(CC) $(CPPFLAGS) -o $(NAME) $(addprefix $(OBJDIR)/, $(OBJ))
	@echo "$(GREEN)Account is Ready!$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)Clean done!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean done!$(RESET)"

re: fclean all

.PHONY: all clean fclean re