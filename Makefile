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

FREE_FILES = free \
	free_block \
	free_large_block \
	free_small_block

ALLOCATE_FILES = allocate \
	allocate_large \
	allocate_small \
	calloc \
	malloc \
	realloc

ZONES_FILES = add_zone \
	remove_zone

BLOCKS_FILES = add_first_blocks \
	find_block_info \
	get_block \
	get_block_from_zones \
	get_block_from_zone

DISPLAY_FILES = display_zones \
	show_alloc_mem

UTILS_FILES = get_size_log2 \
	round_up_to_page_size

FREE_OBJS = $(addsuffix .o, $(FREE_FILES))
ALLOCATE_OBJS = $(addsuffix .o, $(ALLOCATE_FILES))
ZONES_OBJS = $(addsuffix .o, $(ZONES_FILES))
BLOCKS_OBJS = $(addsuffix .o, $(BLOCKS_FILES))
DISPLAY_OBJS = $(addsuffix .o, $(DISPLAY_FILES))
UTILS_OBJS = $(addsuffix .o, $(UTILS_FILES))

OBJS_DIR = objs
FREE_OBJS_DIR = $(OBJS_DIR)/free
ALLOCATE_OBJS_DIR = $(OBJS_DIR)/allocate
ZONES_OBJS_DIR = $(OBJS_DIR)/zones
BLOCKS_OBJS_DIR = $(OBJS_DIR)/blocks
DISPLAY_OBJS_DIR = $(OBJS_DIR)/display
UTILS_OBJS_DIR = $(OBJS_DIR)/utils
OBJS_DIRS = $(FREE_OBJS_DIR) \
	$(ALLOCATE_OBJS_DIR) \
	$(ZONES_OBJS_DIR) \
	$(BLOCKS_OBJS_DIR) \
	$(DISPLAY_OBJS_DIR) \
	$(UTILS_OBJS_DIR)

SRCS_DIR = srcs

INCLUDES_DIR = includes
INCLUDES_FILES = malloc
HEADERS = $(addsuffix .h, $(patsubst %, $(INCLUDES_DIR)/%, $(INCLUDES_FILES)))
HEADERS += $(LIBFT_INCLUDES)/libft.h

OBJS = $(addprefix $(FREE_OBJS_DIR)/, $(FREE_OBJS))
OBJS += $(addprefix $(ALLOCATE_OBJS_DIR)/, $(ALLOCATE_OBJS))
OBJS += $(addprefix $(ZONES_OBJS_DIR)/, $(ZONES_OBJS))
OBJS += $(addprefix $(BLOCKS_OBJS_DIR)/, $(BLOCKS_OBJS))
OBJS += $(addprefix $(DISPLAY_OBJS_DIR)/, $(DISPLAY_OBJS))
OBJS += $(addprefix $(UTILS_OBJS_DIR)/, $(UTILS_OBJS))

SRCS = $(patsubst $(OBJS_DIR)/%.o, $(SRCS_DIR)/%.c, $(OBJS))

GREEN_COLOR = "\033[0;32m"
DEFAULT_COLOR = "\033[0m"
CREATED_TEXT = $(LIB_NAME) "and" $(SYM_LIB_NAME) "created!"

all: comp_libft $(NAME)

comp_libft:
	@make -C $(LIBFT_DIR)/ GCC_FLAGS=$(GCC_FLAGS)

$(SYM_LIB_NAME):
	@ln -s $(LIB_NAME) $(SYM_LIB_NAME)

$(LIB_NAME): $(LIBFT_FILE) $(OBJS_DIRS) $(OBJS)
	@$(CC) -shared $(OBJS) $(LIBFT_FILE) -o $(LIB_NAME)
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
