NAME	=	so_long

FILES	=	so_long.c \

LIBFT	=	libft/libft.a

#---------------------------------MLX---------------------------------------------#
HEADERS	:= -I ./include -I $(LIBMLX)/include
INCLUDES	:=	-Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
LIBMLX	=	./MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

FtoO	=	$(FILES:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Ofast
RM		=	rm -f

all:	libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(LIBFT) $(FtoO) $(LIBMLX)
		@$(CC) $(CFLAGS) $(FtoO) $(INCLUDES) $(HEADERS) $(LIBFT) $(LIBS) -o $(NAME)
		

$(LIBFT):
	@make -C ./libft

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	make clean -C libft
	@rm -rf $(LIBMLX)/build
	$(RM) $(FtoO)

fclean: clean
	$(RM) $(NAME) $(FtoO) $(LIBFT) $(LIBMLX)/build

re: fclean libmlx $(NAME)

.PHONY: all, clean, fclean, re, libmlx