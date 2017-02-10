cmake_minimum_required(VERSION 3.6)
project(printf)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ft_printf.c libft/ft_putstr.c libft/ft_putchar.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putchar_fd.c)
add_executable(printf ${SOURCE_FILES})