NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ_DIR := ./obj
DEP_DIR := $(OBJ_DIR)/.deps
INC_DIRS := ./includes
SRC_DIRS := ./srcs

vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)
vpath %.d $(DEP_DIR)

LIBFT_DIR = $(INC_DIRS)/libft
LIBFT = libft.a
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)
LIBFTFLAGS = -L$(LIBFT_DIR) -lft
LIBFT_REPO = https://github.com/lilikts/42-Libft.git

MLXFT_DIR = $(INC_DIRS)/MLX42
MLXFT = libmlx42.a
MLXFT_BUILD_DIR = $(INC_DIRS)/mlx_build
MLXFT_LIB = $(MLXFT_BUILD_DIR)/$(MLXFT)
MLXFTFLAGS = -L$(MLXFT_BUILD_DIR) -lmlx42 -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
MLXFT_REPO = https://github.com/codam-coding-college/MLX42.git

SRCS =	clear_game.c \
		check_map_accessibilty.c \
		utils.c \
		check_map_chars.c \
		main.c \
		validate_map.c \
		create_game.c \
		create_map.c \
		movement.c \
		image_utils.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
DEPS := $(addprefix $(DEP_DIR)/, $(SRCS:%.c=%.d))

all: init-submodules $(NAME)

-include $(DEPS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@mkdir -p $(DEP_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -MF $(DEP_DIR)/$*.d -I$(INC_DIRS) -I$(LIBFT_DIR) -I$(MLXFT_DIR)/include -c $< -o $@

init-submodules: init-libft init-mlx

init-libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git submodule add $(LIBFT_REPO) $(LIBFT_DIR) > /dev/null 2>&1 || \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	elif [ -z "$$(ls -A $(LIBFT_DIR) 2>/dev/null)" ]; then \
		git submodule update --init --recursive $(LIBFT_DIR) > /dev/null 2>&1 || \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi

init-mlx:
	@if [ ! -d "$(MLXFT_DIR)" ]; then \
		git submodule add $(MLXFT_REPO) $(MLXFT_DIR) > /dev/null 2>&1 || \
		git clone $(MLXFT_REPO) $(MLXFT_DIR); \
	elif [ -z "$$(ls -A $(MLXFT_DIR) 2>/dev/null)" ]; then \
		git submodule update --init --recursive $(MLXFT_DIR) > /dev/null 2>&1 || \
		git clone $(MLXFT_REPO) $(MLXFT_DIR); \
	fi

$(LIBFT_LIB): init-libft
	@$(MAKE) -C $(LIBFT_DIR)

$(MLXFT_LIB): init-mlx
	@cd $(MLXFT_DIR) && cmake -B ../mlx_build
	@$(MAKE) -C $(MLXFT_BUILD_DIR)

$(NAME): $(LIBFT_LIB) $(MLXFT_LIB) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(MLXFTFLAGS)
	@echo "Done Compiling"

remove-libft:
	@if [ -d "$(LIBFT_DIR)" ]; then \
		git submodule deinit -f $(LIBFT_DIR) 2>/dev/null || true; \
		git rm -f $(LIBFT_DIR) 2>/dev/null || rm -rf $(LIBFT_DIR); \
		rm -rf .git/modules/$(LIBFT_DIR) 2>/dev/null || true; \
	fi

remove-mlx:
	@if [ -d "$(MLXFT_DIR)" ]; then \
		git submodule deinit -f $(MLXFT_DIR) 2>/dev/null || true; \
		git rm -f $(MLXFT_DIR) 2>/dev/null || rm -rf $(MLXFT_DIR); \
		rm -rf .git/modules/$(MLXFT_DIR) 2>/dev/null || true; \
	fi

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(LIBFT_DIR)
	@rm -rf $(MLXFT_DIR)
	@rm -rf $(MLXFT_BUILD_DIR)
	@rm -rf .git/modules

cleanall: fclean remove-libft remove-mlx

re: fclean all

.PHONY: all clean fclean re init-submodules init-libft init-mlx remove-libft remove-mlx cleanall