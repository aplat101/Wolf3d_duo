#**************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/28 12:06:19 by ztrouill     #+#   ##    ##    #+#        #
#    Updated: 2019/11/08 18:33:05 by ztrouill    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = Wolf3D

# FLAGS

FLAGS = -Wall -Wextra -Werror

FLAGS_FRMWRK = -framework OpenGL -framework AppKit

# PATH_GENERAL

INCLUDE_PATH = ./includes/

LIB_PATH = ./lib/

SRCS_PATH = ./srcs/

OBJ_PATH = ./obj/

# LIB_PATH

LIBFT_PATH = $(LIB_PATH)libft/

LIBMLX_PATH = $(LIB_PATH)minilibx_macos/


# INCLUDES

INCLUDE = $(INCLUDE_PATH)wolf.h

INCLUDE_STRUCT = $(INCLUDE_PATH)wolf_struct.h

INCLUDE_DEFINE = $(INCLUDE_PATH)wolf_define.h
# LIB

LIBFT = $(LIBFT_PATH)libft.a

LIBMLX = $(LIBMLX_PATH)libmlx.a


# SRCS & OBJ

SRCS_NAME = main.c parsing.c draw_floor.c raycasting.c events.c init.c init_struct.c \
			texture.c gradient.c init_xpm.c movement.c draw_menu.c sky.c \
			pause_events.c mouse_events.c shade.c init_str_xpm.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

OBJ_NAME = $(SRCS_NAME:.c=.o)


# RULES // COMP AND CLEANING

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "."
		@sleep 0.5
		@echo "."
		@sleep 0.5
		@echo "."
		@sleep 0.5
	@make -C $(LIBFT_PATH)
	@make -C $(LIBMLX_PATH)
	@gcc $(FLAGS) $(LIBFT) $(LIBMLX) $(FLAGS_FRMWRK) $^ -o  $@
	@echo ":)"

$(OBJ_PATH)%.o : $(SRCS_PATH)%.c $(INCLUDE) $(INCLUDE_STRUCT) $(INCLUDE_DEFINE)
	@mkdir $(OBJ_PATH) 2< /dev/null || true
	@gcc $(FLAGS) -c $< -o $@

clean :
	@echo "."
	@sleep 0.5
	@echo "."
	@sleep 0.5
	@echo "."
	@sleep 0.5
	@echo "Bye Bye"
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(LIBMLX_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH) 2< /dev/null || true

fclean : clean
	@make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
