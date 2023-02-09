NAME		:=	fractol
CC			:=	gcc
CFLAGS		:=	-Wall -Werror -Wextra
DFLAGS		:=	-MMD -MP
MFLAGS		:=	-fsanitize=address -g
IFLAGS		=	-I $(INCLUDE)

SRCDIR		:=	./src
# SRCDIR		:=	$(PWD)/src
# INCLUDE		:=	$(PWD)/include
INCLUDE		:=	./include\
				-lXext\
				-lX11\
				-lm 

OBJSDIR		:=	./objs
# OBJSDIR		:=	$(PWD)/objs
LIBFTDIR	:=	./libft
MINILIBXDIR	:=	./minilibx-linux

SRCS		:=	$(SRCDIR)/main.c\
				$(SRCDIR)/init.c\
				$(SRCDIR)/exit.c\
				$(SRCDIR)/draw.c\
				$(SRCDIR)/hook_1.c\
				$(SRCDIR)/hook_2.c\
				$(SRCDIR)/draw_mandelbrot.c\
				$(SRCDIR)/draw_julia.c\
				$(SRCDIR)/handle_argument.c
OBJS		=	$(SRCS:$(SRCDIR)%.c=$(OBJSDIR)%.o)
DEPS		=	$(SRCS:$(SRCDIR)%.c=$(OBJSDIR)%.d)
LIBFT		:=	$(LIBFTDIR)/libft.a
MINILIBX	:=	$(MINILIBXDIR)/libmlx.a

.PHONY: all clean fclean re run debug $(NAME) $(LIBFT) $(MINILIBX) $(OBJSDIR)

all:$(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MINILIBX) $(INCLUDE)
	$(CC) $(OBJS)  $(LIBFT) $(MINILIBX) $(IFLAGS)-o $(NAME)

$(LIBFT):$(LIBFT)
	cd $(LIBFTDIR) && make bonus

$(MINILIBX):
	cd $(MINILIBXDIR) && make

$(OBJSDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $< $(CFLAGS) $(IFLAGS) $(DFLAGS) -c -o $@

clean:
	rm -f $(OBJS) && rm -f $(OBJSDIR)/*.d
	cd $(LIBFTDIR) && make clean
	cd $(MINILIBXDIR) && make clean

fclean:clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean

re:fclean
	make

run:
	./fractol 1

debug:
	$(CFLAGS) += -g -fsanitize=address -fsanitize=undefined
	make re
