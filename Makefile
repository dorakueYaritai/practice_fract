CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
SRCDIR		:= ./src
DFLAGS		:= -MMD -MP
SRCS=	$(SRCDIR)/main.c\
		$(SRCDIR)/init.c\
		$(SRCDIR)/exit.c\
		$(SRCDIR)/draw.c\
		$(SRCDIR)/hook_1.c\
		$(SRCDIR)/hook_2.c\
		$(SRCDIR)/draw_mandelbrot.c\
		$(SRCDIR)/draw_julia.c\
		$(SRCDIR)/handle_argument.c\

OBJS = $(SRCS:%.c=%.o)
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
NAME=fractol
MINILIBXDIR = ./minilibx-linux
MINILIBX = $(MINILIBXDIR)/libmlx.a

all:$(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MINILIBX)
	$(CC) $(OBJS)  $(LIBFT) $(MINILIBX) -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	cd $(LIBFTDIR) && make bonus

$(MINILIBX):
	cd $(MINILIBXDIR) && make

clean:
	rm -f $(OBJS) && cd $(LIBFTDIR) && make clean

fclean:clean
	rm -f $(NAME) && cd $(LIBFTDIR) && make fclean

re:fclean
	make

run:
	./fractol 1

debug:
	$(CFLAGS) += -g -fsanitize=address -fsanitize=undefined
	make re
