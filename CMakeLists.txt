cmake_minimum_required(VERSION 3.6)
project(printf)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin/lib/)
set(CMAKE_C_STANDARD 99)


set(SOURCE_FILES ft_printf.c libft/ft_amount_d.c libft/ft_itoa.c libft/ft_strjoin.c libft/ft_atoi.c libft/ft_strnew.c libft/ft_bzero.c libft/ft_putstr.c libft/ft_putchar.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putchar_fd.c libft/ft_strlen.c create_struct.c go_through_struct.c src/ft_itoa_base.c handle_type.c handle_flag.c handle_width.c handle_size.c length_of_a.c)
add_executable(printf ${SOURCE_FILES})