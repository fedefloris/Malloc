# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffloris <ffloris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 09:39:19 by ffloris           #+#    #+#              #
#    Updated: 2018/10/06 15:27:33 by ffloris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE), )
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LIB_NAME = libft_malloc_$(HOSTTYPE).so
SYM_LIB_NAME = libft_malloc.so

NAME = $(SYM_LIB_NAME) $(LIB_NAME)

GCC_FLAGS = -fPIC -Werror -Wextra -Wall

LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = $(LIBFT_DIR)/includes

FREE_FILES = free

MALLOC_FILES = malloc \
	malloc_small \
	malloc_large

REALLOC_FILES = realloc

BLOCK_FILES = get_free_block

DISPLAY_FILES = show_alloc_mem

FREE_OBJS = $(addsuffix .o, $(FREE_FILES))
MALLOC_OBJS = $(addsuffix .o, $(MALLOC_FILES))
REALLOC_OBJS = $(addsuffix .o, $(REALLOC_FILES))
BLOCK_OBJS = $(addsuffix .o, $(BLOCK_FILES))
DISPLAY_OBJS = $(addsuffix .o, $(DISPLAY_FILES))

OBJS_DIR = objs
FREE_OBJS_DIR = $(OBJS_DIR)/free
MALLOC_OBJS_DIR = $(OBJS_DIR)/malloc
REALLOC_OBJS_DIR = $(OBJS_DIR)/realloc
BLOCK_OBJS_DIR = $(OBJS_DIR)/block
DISPLAY_OBJS_DIR = $(OBJS_DIR)/display
OBJS_DIRS = $(FREE_OBJS_DIR) \
	$(MALLOC_OBJS_DIR) \
	$(REALLOC_OBJS_DIR) \
	$(BLOCK_OBJS_DIR) \
	$(DISPLAY_OBJS_DIR)

SRCS_DIR = srcs

INCLUDES_DIR = includes
INCLUDES_FILES = malloc
HEADERS = $(addsuffix .h, $(patsubst %, $(INCLUDES_DIR)/%, $(INCLUDES_FILES)))
HEADERS += $(LIBFT_INCLUDES)/libft.h

OBJS = $(addprefix $(FREE_OBJS_DIR)/, $(FREE_OBJS))
OBJS += $(addprefix $(MALLOC_OBJS_DIR)/, $(MALLOC_OBJS))
OBJS += $(addprefix $(REALLOC_OBJS_DIR)/, $(REALLOC_OBJS))
OBJS += $(addprefix $(BLOCK_OBJS_DIR)/, $(BLOCK_OBJS))
OBJS += $(addprefix $(DISPLAY_OBJS_DIR)/, $(DISPLAY_OBJS))

SRCS = $(patsubst $(OBJS_DIR)/%.o, $(SRCS_DIR)/%.c, $(OBJS))

GREEN_COLOR = "\033[0;32m"
DEFAULT_COLOR = "\033[0m"
CREATED_TEXT = $(LIB_NAME) "and" $(SYM_LIB_NAME) "created!"

all: comp_libft $(NAME)

comp_libft:
	@make -C $(LIBFT_DIR)/

$(SYM_LIB_NAME):
	@ln -s $(LIB_NAME) $(SYM_LIB_NAME)

$(LIB_NAME): $(LIBFT_FILE) $(OBJS_DIRS) $(OBJS)
	@$(CC) -shared $(OBJS) -o $(LIB_NAME)
	@echo $(CREATED_TEXT)

$(OBJS_DIRS):
	@mkdir -p $(OBJS_DIRS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	@echo Malloc: $(GREEN_COLOR) $< $(DEFAULT_COLOR)
	@$(CC) $(GCC_FLAGS) -c $< -o $@ -I $(INCLUDES_DIR) -I $(LIBFT_INCLUDES)

clean:
	@make -C $(LIBFT_DIR)/ clean
	@rm -rf $(OBJS) $(OBJS_DIR)

fclean:
	@make -C $(LIBFT_DIR)/ fclean
	@rm -rf $(NAME) $(OBJS) $(OBJS_DIR)

re: fclean all

.PHONY: all comp_libft clean fclean re
