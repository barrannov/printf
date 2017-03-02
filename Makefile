
NAME = libftprintf.a

G = gcc

FLAG = -Wall -Wextra -Werror

SRC =   ft_printf.c \
		go_through_struct.c \
		handle_flag.c \
		handle_size.c \
		handle_type.c \
		handle_width.c \
		length_of_a.c \
		ft_itoa_base.c \
		print.c \
		handle_1_gr.c \
		handle_2_gr.c \
		handle_else_gr.c \
		groups.c \
		handle_per.c \
		handle_p.c\
		create_struct.c

HDR = ft_printf.h

OBJ = $(SRC:.c=.o)

DEL = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	ar -cru $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)
	@echo libftprintf.a is ALIVE!!!

%.o: %.c
	$(G) $(CFLAGS) -c -o $@ $<

clean:
	make clean -C ./libft
	$(DEL) $(OBJ)
	@echo OBJ_libftprintf is DEAD!!!

fclean: clean
	make fclean -C ./libft
	$(DEL) $(NAME)
	@echo libftprintf.a is DESTROYED!!!

re: all
	make all -C ./libft
	@echo ALL DAMM FPS is DESTROYED!!!

norm:
	make norm -C ./libft
	norminette $(SRC) $(HDR) | grep -B 1 "Error"

rmsh:
	make rmsh -C ./libft
	rm *~
	rm \#*
	rm *.out
