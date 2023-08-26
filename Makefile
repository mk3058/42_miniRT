################################################################################
# Compile option
NAME := miniRT
CC := cc
CFLAGS := -MMD -Wall -Wextra -Werror
OBJ_DIR := make_object

##### Exclude Directory Settings #####
EXCLUDE_SRCS_PATHS := ./mlx ./libft
EXCLUDE_HDRS_PATHS := 

# Library Path
LIBFT := libft/libft.a
MLX := mlx/libmlx.a
MLX_LIB := -L./mlx -lmlx -framework OpenGL -framework AppKit
LIBFT_LIB := -L libft -lft
################################################################################

# excluded sources and headers, dependencies
EXCLUDE_SRCS := $(addprefix ! -path ", $(addsuffix /*.c", $(EXCLUDE_SRCS_PATHS)))
EXCLUDE_HDRS := $(addprefix ! -path ", $(addsuffix /*.h", $(EXCLUDE_HDRS_PATHS)))
SRCS := $(shell find . -name "*.c" $(EXCLUDE_SRCS) ! -path "./libft/*")
HDRS := $(shell find . -name "*.h" $(EXCLUDE_HDRS))
INCLUDES := $(dir $(sort $(HDRS)))
CFLAGS += $(addprefix -I, $(INCLUDES))
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEP := $(OBJS:.o=.d)

# Progress bar
TOTAL_FILES := $(words $(SRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@printf "\033[0;32mLinking... "
	@$(CC) $(CFLAGS) $(LIBFT_LIB) $(MLX_LIB) $^ -o $@
	@echo "Done!\033[0m"

$(LIBFT):
	@make -C libft

$(MLX):
	@make -C mlx

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@CURRENT_FILES=$$(ls $(OBJS) 2> /dev/null | wc -l | awk '{print $$1 + 1}'); \
	printf "\033[0;32mCompiling [$$CURRENT_FILES/$(TOTAL_FILES)]\033[0m $<\n"; \
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@make clean -C libft
	@make clean -C mlx
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

bonus: all

-include $(DEP)

.PHONY: all clean fclean re bonus
