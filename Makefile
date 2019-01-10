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

NAME = libft_malloc_$(HOSTTYPE).so

GCC_FLAGS = -Werror -Wextra -Wall

FREE_OBJS = free

MALLOC_OBJS = malloc

REALLOC_OBJS = realloc

DISPLAY_OBJS = show_alloc_mem

OBJS_DIR = objs
FREE_OBJS_DIR = $(OBJS_DIR)/free
MALLOC_OBJS_DIR = $(OBJS_DIR)/malloc
REALLOC_OBJS_DIR = $(OBJS_DIR)/realloc
DISPLAY_OBJS_DIR = $(OBJS_DIR)/display
OBJS_DIRS = $(FREE_OBJS_DIR) $(MALLOC_OBJS_DIR) \
	$(REALLOC_OBJS_DIR) $(DISPLAY_OBJS_DIR)

SRCS_DIR = srcs

INCLUDES_DIR = includes
INCLUDES_FILES = malloc
HEADERS = $(addsuffix .h, $(patsubst %, $(INCLUDES_DIR)/%, $(INCLUDES_FILES)))

OBJS = $(addprefix $(FREE_OBJS_DIR)/, $(FREE_OBJS))
OBJS += $(addprefix $(MALLOC_OBJS_DIR)/, $(MALLOC_OBJS))
OBJS += $(addprefix $(REALLOC_OBJS_DIR)/, $(REALLOC_OBJS))
OBJS += $(addprefix $(DISPLAY_OBJS_DIR)/, $(DISPLAY_OBJS))

SRCS = $(patsubst $(OBJS_DIR)/%.o, $(SRCS_DIR)/%.c, $(OBJS))

GREEN_COLOR = "\033[0;32m"
DEFAULT_COLOR = "\033[0m"
CREATED_TEXT = $(NAME) "created!"

all: $(NAME)

$(NAME): $(OBJS_DIRS) $(OBJS) $(HEADERS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo $(CREATED_TEXT)

$(OBJS_DIRS):
	@mkdir -p $(OBJS_DIRS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	@echo Malloc: $(GREEN_COLOR) $< $(DEFAULT_COLOR)
	@cc $(GCC_FLAGS) -c $< -o $@ -I $(INCLUDES_DIR)/

clean:
	@rm -rf $(OBJS) $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
