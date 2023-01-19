# NAME		:= fractol
# CC			:= gcc 
# RM			:= rm -f
# CFLAGS		:= -Wall -Wextra -Werror -O3
# DFLAGS		:= -MMD -MP
# MFLAGS		:= -Lminilibx-linux -lmlx -lXext -lX11 -lm
#iMac		:= -L/usr/X11/lib
# SRCDIR		:= ./src/
# SRCS=	$(SRCDIR)main.c\
# 		$(SRCDIR)init.c\
# 		$(SRCDIR)exit.c\
# 		$(SRCDIR)argc_check.c\

# LIBFT		= $(LIBDIR)libft.a
# INCLUDE		= -I$(INCDIR)


# DEPENDS		= $(OBJECTS:.o=.d)

# OBJS		= $(SRCS:%.c=%.o)
# OBJECTS		= $(addprefix $(OBJDIR)/, $(OBJS))

# B_OBJS		= $(SRCS_B:%.c=%.o)
# B_OBJECTS   = $(addprefix $(OBJDIR)/, $(B_OBJS))
# ifdef WITH_BONUS
# 	OBJS += $(B_OBJECTS)
# endif

# INCDIR		= include/
# LIBDIR		= libft/
# OBJDIR		= obj/
# ifeq "$(strip $(OBJDIR))" ""
#   OBJDIR	= .
# endif
# SRCDIR    = src/
# ifeq "$(strip $(SRCDIR))" ""
#   SRCDIR  = .
# endif


# $(NAME): $(OBJECTS) $(LIBFT)
# 	$(CC) -o $@ $^ $(CFLAGS) $(DFLAGS) $(INCLUDE) $(MFLAGS)
# 	@echo $(GREEN)"----- $(NAME) $(CC) done-----"$(RESET)

# $(OBJDIR)/%.o: %.c
# 	-mkdir -p $(OBJDIR)
# 	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@

# $(LIBFT): FORCE
# 	$(MAKE) -C $(LIBDIR)
# 	@echo $(GREEN)"----- $(LIBFT) $(CC) done-----"$(RESET)
# FORCE:

# all: $(NAME) 

# clean:
# 	$(MAKE) clean -C $(LIBDIR)
# 	@echo $(YELLOW)"----- $(LIBFT) clean done-----"$(RESET)
# 	$(RM) $(OBJECTS) $(DEPENDS)
# 	@echo $(YELLOW)"----- $(NAME) clean done-----"$(RESET)

# fclean:	clean
# 	$(MAKE) fclean -C $(LIBDIR)
# 	@echo $(RED)"----- $(LIBFT) fclean done-----"$(RESET)
# 	$(RM) $(NAME)
# 	@echo $(RED)"----- $(NAME) fclean done-----"$(RESET)

# re: fclean all

# -include $(DEPENDS)

# bonus: 
# 	make WITH_BONUS=1

# debug: CFLAGS +=  -g -fsanitize=address -fsanitize=undefined
# debug: re

# .PHONY: all clean fclean re bonus

# RED			=	"\033[31m"
# GREEN		=	"\033[32m"
# YELLOW		=	"\033[33m"
# RESET		=	"\033[0m"

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
# CFLAGS		:= 
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

all:$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS)  $(LIBFT) ./minilibx-linux/libmlx.a -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	cd $(LIBFTDIR) && make bonus

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
