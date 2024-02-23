NAME	=	so_long

FILES	=	so_long.c \
			map_checker.c \
			so_utils.c \
			init_game.c \
			move.c \
			pic.c  \

LIBFT	=	libft/libft.a

#---------------------------------MLX---------------------------------------------#
HEADERS	= -I ./include -I $(LIBMLX)/include/MLX42/
INCLUDES	:=	-Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
LIBMLX	=	./MLX42
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

FtoO	=	$(FILES:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Ofast
RM		=	rm -f

all:	$(LIBFT) libmlx $(NAME)

$(NAME): $(FtoO) so_long.h
	$(CC) $(CFLAGS) $(FtoO) $(INCLUDES) $(HEADERS) $(LIBFT) $(LIBS) -o $(NAME)

libmlx:
	if [ ! -d $(LIBMLX)/build ]; then cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; fi

$(LIBFT):
	@make -C ./libft

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	@make fclean -C libft
	@rm -rf $(LIBMLX)/build
	$(RM) $(FtoO)

fclean: clean
	$(RM) $(NAME) $(FtoO) $(LIBFT) $(LIBMLX)/build

re: fclean all

.PHONY: all, clean, fclean, re, libmlx