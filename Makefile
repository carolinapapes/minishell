# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: capapes <capapes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 15:55:17 by capapes           #+#    #+#              #
#    Updated: 2024/08/03 15:52:57 by capapes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
DEFLAGS = -MMD -MP 
INCLUDE = -I./include
LDFLAGS = -lreadline

PREQ = Makefile
NAME = minishell

SRC_DIR = ./src
BUILD_DIR = ./build

SRC = 	main.c \
		ms_redir/ms_redir_outfile.c \
		ms_err/ms_err_print.c \
		test/test_ms_redir_outfile.c \
		ms_redir/ms_redir_fd_h.c \
		test/test_aux.c 
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)


# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)$(NAME) has been created$(DEF_COLOR)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(PREQ) | $(BUILD_DIR) $(BUILD_DIR)/ms_redir $(BUILD_DIR)/ms_err $(BUILD_DIR)/test
	@$(CC) $(CFLAGS) $(DEFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GRAY)⏳Compiling $<$(DEF_COLOR)"

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/ms_redir:
	mkdir -p $@

$(BUILD_DIR)/ms_err:
	mkdir -p $@

$(BUILD_DIR)/test:
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
	echo "$(RED)🧹clean		${NAME}$(DEF_COLOR)"

fclean: clean
	rm -f $(NAME)
	rm -f $(BUG)
	echo "$(RED)🧹fclean		${NAME}$(DEF_COLOR)"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re

.SILENT:
