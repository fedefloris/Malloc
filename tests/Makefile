# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 09:39:19 by ffloris           #+#    #+#              #
#    Updated: 2019/02/21 20:16:29 by ffloris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = malloc_test
TEST_SCRIPT = run_tests

GCC_FLAGS = -fPIC -Werror -Wextra -Wall

LIBFT_DIR = ../libft
LIBFT_FILE = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = $(LIBFT_DIR)/includes

MALLOC_DIR=..
LIBFT_MALLOC_FILE = $(MALLOC_DIR)/libft_malloc.so

MAIN_FILES = test

ALLOC_FILES = test_malloc

FREE_FILES = test_free

ERRORS_FILES = error_exit

BLOCKS_FILES = test_block \
	test_block_header

MAIN_OBJS = $(addsuffix .o, $(MAIN_FILES))
ALLOC_OBJS = $(addsuffix .o, $(ALLOC_FILES))
FREE_OBJS = $(addsuffix .o, $(FREE_FILES))
ERRORS_OBJS = $(addsuffix .o, $(ERRORS_FILES))
ERRORS_OBJS = $(addsuffix .o, $(ERRORS_FILES))

OBJS_DIR = objs
MAIN_OBJS_DIR = $(OBJS_DIR)/main
ALLOC_OBJS_DIR = $(OBJS_DIR)/alloc
FREE_OBJS_DIR = $(OBJS_DIR)/free
BLOCKS_OBJS_DIR = $(OBJS_DIR)/blocks
ERRORS_OBJS_DIR = $(OBJS_DIR)/errors
OBJS_DIRS = $(MAIN_OBJS_DIR) \
	$(ALLOC_OBJS_DIR) \
	$(FREE_OBJS_DIR) \
	$(BLOCKS_OBJS_DIR) \
	$(ERRORS_OBJS_DIR)

SRCS_DIR = srcs

MALLOC_INCLUDES = ../includes
INCLUDES_DIR = includes
INCLUDES_FILES = malloc_test
HEADERS = $(addsuffix .h, $(patsubst %, $(INCLUDES_DIR)/%, $(INCLUDES_FILES)))
HEADERS += $(LIBFT_INCLUDES)/libft.h $(MALLOC_INCLUDES)/malloc.h

OBJS = $(addprefix $(MAIN_OBJS_DIR)/, $(MAIN_OBJS))
OBJS += $(addprefix $(ALLOC_OBJS_DIR)/, $(ALLOC_OBJS))
OBJS += $(addprefix $(FREE_OBJS_DIR)/, $(FREE_OBJS))
OBJS += $(addprefix $(BLOCKS_OBJS_DIR)/, $(BLOCKS_OBJS))
OBJS += $(addprefix $(ERRORS_OBJS_DIR)/, $(ERRORS_OBJS))

SRCS = $(patsubst $(OBJS_DIR)/%.o, $(SRCS_DIR)/%.c, $(OBJS))

DEFAULT_COLOR = $(shell tput setaf 7)
GREEN_COLOR = $(shell tput setaf 2)
CREATED_TEXT = $(NAME) "created!"

all: comp_libft $(NAME)

tests: all
	./$(TEST_SCRIPT)

comp_libft:
	@make -C $(LIBFT_DIR)/ GCC_FLAGS=$(GCC_FLAGS)

$(NAME): $(LIBFT_FILE) $(OBJS_DIRS) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT_FILE) $(LIBFT_MALLOC_FILE) -o $(NAME)
	@echo $(CREATED_TEXT)

$(OBJS_DIRS):
	@mkdir -p $(OBJS_DIRS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	@echo Malloc_test: $(GREEN_COLOR) $< $(DEFAULT_COLOR)
	@$(CC) $(GCC_FLAGS) -c $< -o $@ -I $(INCLUDES_DIR) -I $(LIBFT_INCLUDES) \
		-I $(MALLOC_INCLUDES)

clean:
	@make -C $(LIBFT_DIR)/ clean
	@rm -rf $(OBJS) $(OBJS_DIR)

fclean:
	@make -C $(LIBFT_DIR)/ fclean
	@rm -rf $(NAME) $(OBJS) $(OBJS_DIR)

re: fclean all

.PHONY: all tests comp_libft clean fclean re