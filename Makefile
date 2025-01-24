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

# Source files
SRCS = 	clean_game.c \
		map_accessibility.c \
		map_sides.c \
		read_map.c \
        valid_map.c \
		main.c \
		map_chars.c \
		movement.c \
		render_map.c

# Object files
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# Default rule to compile all
all: init-submodules $(NAME)

-include $(OBJS:.o=.d)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Initialize submodules
init-submodules: init-libft init-mlx

#Initialize libft
init-libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git submodule add $(LIBFT_REPO) $(LIBFT_DIR) > /dev/null 2>&1 || (echo "Failed to add libft submodule" && exit 1); \
	elif [ -z "$$(ls -A $(LIBFT_DIR) 2>/dev/null)" ]; then \
		git submodule update --init --recursive $(LIBFT_DIR) > /dev/null 2>&1 || (echo "Failed to update libft submodule" && exit 1); \
	else \
		echo "LIBFT submodule is already initialized"; \
	fi

#Remove submodules
remove-submodules: remove-libft remove-mlx

#Remove libft
remove-libft:
	@if [ -d "$(LIBFT_DIR)" ]; then \
		git submodule deinit -q -f $(LIBFT_DIR) > /dev/null 2>&1; \
		git rm -q -f $(LIBFT_DIR) > /dev/null 2>&1; \
		rm -rf .git/modules/$(LIBFT_DIR) > /dev/null 2>&1; \
	fi

#Remove MLX42
remove-mlx:
	@if [ -d "$(MLXFT_DIR)" ]; then \
		git submodule deinit -q -f $(MLXFT_DIR) > /dev/null 2>&1; \
		git rm -q -f $(MLXFT_DIR) > /dev/null 2>&1; \
		rm -rf .git/modules/$(MLXFT_DIR) > /dev/null 2>&1; \
		rm -rf ./mlx42 > /dev/null 2>&1; \
	fi

#Rule to compile libft
$(LIBFT_LIB): init-libft
	@if [ ! -f "$(LIBFT_LIB)" ]; then \
		$(MAKE) -C $(LIBFT_DIR); \
	fi

#Initialize MLX42
init-mlx:
	@if [ ! -d "$(MLXFT_DIR)" ]; then \
		git submodule add -q $(MLXFT_REPO) $(MLXFT_DIR) > /dev/null 2>&1 || (echo "Failed to add MLX42 submodule" && exit 1); \
		cd $(MLXFT_DIR) && git checkout 7f95e70415705dcc723f94a2696aba84ed3756ad > /dev/null 2>&1 && cd ../; \
	elif [ -z "$$(ls -A $(MLXFT_DIR) 2>/dev/null)" ]; then \
		git submodule update --init --recursive -q $(MLXFT_DIR) > /dev/null 2>&1 || (echo "Failed to update MLX42 submodule" && exit 1); \
		cd $(MLXFT_DIR) && git checkout 7f95e70415705dcc723f94a2696aba84ed3756ad > /dev/null 2>&1 && cd ../; \
	else \
		echo "MLX42 submodule is already initialized"; \
	fi

#Rule to compile MLX42
$(MLXFT_LIB): init-mlx
	@cd $(MLXFT_DIR) && git checkout 7f95e70415705dcc723f94a2696aba84ed3756ad 2>/dev/null
	@if [ ! -f "$(MLXFT_LIB)" ]; then \
		mkdir -p $(MLXFT_BUILD_DIR); \
		cmake -S $(MLXFT_DIR) -B $(MLXFT_BUILD_DIR) > /dev/null 2>&1 && \
		cmake --build $(MLXFT_BUILD_DIR) --parallel > /dev/null 2>&1 || \
		(echo "Failed to build MLX42" && exit 1); \
	fi


#Rule to compile program
$(NAME): init-submodules $(LIBFT_LIB) $(MLXFT_LIB) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(MLXFTFLAGS)
	@echo "Done Compiling"

# Clean object files and libraries
clean: remove-submodules
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLXFT_BUILD_DIR)
	@rm -rf $(MLXFT_DIR)
	@rm -rf $(LIBFT_DIR)

# Clean all generated files
fclean: clean
	@printf "Done Cleaning\n"
	@rm -rf $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re libft mlx init-submodules remove-submodules
