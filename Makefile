NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

SOURCES = main.c utils.c error_message.c philo.c

OBJECTS = $(SOURCES:.c=.o)

GREEN = \033[0;32m
NC = \033[0m
RED = \033[0;31m
YELLOW = \033[0;33m
TOTAL_OBJ = $(words $(OBJECTS))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@$(MAKE) -s progress
	@echo ""
	@echo "$(GREEN)¡Compilación del philo completada!$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(MAKE) -s progress

clean:
	@$(RM) $(OBJECTS)
	@echo "$(YELLOW)¡Dejamos todo preparado para el philo!$(NC)"


fclean:
	@$(RM) $(OBJECTS) $(NAME)
	@echo "$(RED)¡Todo limpio del philo!$(NC)"

re: fclean all

progress:
	@$(eval COMPLETED = $(shell ls -1 $(OBJECTS) 2>/dev/null | wc -l))
	@$(eval PERCENTAGE = $(shell echo "scale=2; 100 * $(COMPLETED) / $(TOTAL_OBJ)" | bc))
	@$(eval BAR_LENGTH = 50)
	@$(eval FILLED_LENGTH = $(shell echo "$(BAR_LENGTH) * $(COMPLETED) / $(TOTAL_OBJ)" | bc))
	@$(eval EMPTY_LENGTH = $(shell echo "$(BAR_LENGTH) - $(FILLED_LENGTH)" | bc))
	@echo -n "$(GREEN)["
	@$(eval BAR = $(shell yes "=" | head -n $(FILLED_LENGTH) | tr -d '\n'))
	@$(eval EMPTY = $(shell yes " " | head -n $(EMPTY_LENGTH) | tr -d '\n'))
	@echo -n "$(BAR)$(EMPTY)"
	@echo -n "] $(PERCENTAGE)%"
	@echo -n "\r"
	@sleep 0.05

.PHONY: all clean fclean re progress