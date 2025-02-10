MAKEFLAGS += -s -j
.DEFAULT_GOAL = all

# --- Printf Utils --- #
RPATH := $(shell realpath --relative-to=${PWD} ${CURDIR})/
RPATH := ${shell if [ "${RPATH}" != "./" ]; then echo ${RPATH}; fi}
NORMAL := ${shell tput sgr0}
RED := ${shell tput setaf 1}
GREEN := ${shell tput setaf 2}
BLUE := ${shell tput setaf 4}
green_plus := $(BLUE)[$(GREEN)+$(BLUE)]$(NORMAL)
red_minus := $(BLUE)[$(RED)-$(BLUE)]$(NORMAL)
# -------------------- #

# --- Project sources --- #
SRCDIR	:= srcs/
SRC		:= load_textures.c \
		   main.c \
		   parsing/check_file_data.c \
		   parsing/check_map.c \
		   parsing/check_start.c \
		   parsing/fill_map.c \
		   parsing/manage_ceil_floor.c \
		   parsing/manage_data.c \
		   parsing/manage_loops.c \
		   parsing/init_parsing.c \
		   raycast.c \
		   textures.c \
		   player_motions.c
OBJDIR	:= objs/
OBJ		:= $(addprefix $(OBJDIR), $(SRC:.c=.o))
HDRDIR	:= inc/
HDR		:= constants.h \
		   cub3D.h \
		   game_struct.h \
		   matrix.h \
		   parsing.h \
		   vector.h
HDR		:= $(addprefix $(HDRDIR), $(HDR))
NAME	:= cub3D
# ----------------------- #

# --- Project bonus sources --- #
SRCDIR_B := srcs_bonus/
SRC_B := load_textures_bonus.c \
		 main_bonus.c \
		 parsing/check_file_data_bonus.c \
		 parsing/check_map_bonus.c \
		 parsing/check_start_bonus.c \
		 parsing/fill_map_bonus.c \
		 parsing/init_parsing_bonus.c \
		 parsing/manage_ceil_floor_bonus.c \
		 parsing/manage_data_bonus.c \
		 parsing/manage_loops_bonus.c \
		 player_motions_bonus.c \
		 raycast_bonus.c \
		 textures_bonus.c \
		 minimap_bonus.c
OBJ_B := $(addprefix $(OBJDIR), $(SRC_B:.c=.o))
HDRDIR_B := inc_bonus/
HDR_B := constants_bonus.h \
		 cub3D_bonus.h \
		 game_struct_bonus.h \
		 matrix_bonus.h \
		 parsing_bonus.h \
		 vector_bonus.h
HDR_B := $(addprefix $(HDRDIR_B), $(HDR_B))
NAME_B := cub3D_bonus
# ----------------------------- #

CC		:= clang
LD		:= $(CC)
MKDIR	:= mkdir -p

LIBMLX_DIR	:= libs/mlx
LIBMLX	:= $(LIBMLX_DIR)/build/libmlx42.a
LIBFT	:= libs/libft
LIBS	:=  -lmlx42 -L$(LIBMLX_DIR)/build/ -L$(LIBFT) -lft

CFLAGS	:= -Wall -Wextra -Werror
LDFLAGS	:= -ldl -lglfw -pthread -lm
INCLUDE	:= -I $(LIBMLX_DIR)/include -I $(LIBFT)

all: $(NAME)

bonus: $(NAME_B)

$(LIBMLX):
	cmake  $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4

libft:
	make -j -C $(LIBFT)

$(NAME): $(OBJ) $(LIBMLX)
	$(MAKE) libft
	$(LD) $(OBJ) $(LIBS) $(LDFLAGS) -o $@
	printf "$(green_plus) $(BLUE)$(RPATH)$@$(NORMAL)\n"

$(NAME_B): $(OBJ_B) $(LIBMLX)
	$(MAKE) libft
	$(LD) $(OBJ_B) $(LIBS) $(LDFLAGS) -o $@
	printf "$(green_plus) $(BLUE)$(RPATH)$@$(NORMAL)\n"

$(OBJDIR)%.o: $(SRCDIR)%.c $(HDR)
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -I ./inc -c $< -o $@
	printf "$(green_plus) $(BLUE)$(RPATH)$@$(NORMAL)\n"

$(OBJDIR)%.o: $(SRCDIR_B)%.c $(HDR_B)
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -I ./inc_bonus -c $< -o $@
	printf "$(green_plus) $(BLUE)$(RPATH)$@$(NORMAL)\n"

clean:
	make -C $(LIBFT) fclean
	rm -rf $(LIBMLX_DIR)/build
	printf "$(red_minus) $(BLUE)$(RPATH)$(LIBMLX_DIR)/build$(NORMAL)\n"
	rm -rf $(OBJDIR)
	printf "$(red_minus) $(BLUE)$(RPATH)$(OBJDIR)$(NORMAL)\n"

fclean: clean
	rm -rf $(NAME)
	printf "$(red_minus) $(BLUE)$(RPATH)$(NAME)$(NORMAL)\n"
	rm -rf $(NAME_B)
	printf "$(red_minus) $(BLUE)$(RPATH)$(NAME_B)$(NORMAL)\n"

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
