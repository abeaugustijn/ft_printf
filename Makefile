# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: abe <abe@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/04 19:52:15 by abe            #+#    #+#                 #
#    Updated: 2019/12/09 15:29:46 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
SRCS			=\
	handle_format\
	main output\
	t_format_info/t_fi_check_width_precision\
	t_format_info/t_fi_create\
	t_format_info/t_fi_get_info\
	t_format_info/t_fi_handle_zero_minus\
	t_format_info/t_fi_parse_functions\
	formats/f_char\
	formats/f_int\
	formats/f_string\
	formats/f_percentage\
	formats/f_hex\
	formats/f_pointer\
	formats/f_unsigned\
	formats/f_n\
	utils/ft_putchar_fd_count\
	utils/ft_putstr_fd_count\
	utils/ft_putstr_n_fd_count\
	utils/ft_putnbr_ll_fd_count\
	utils/ft_putunsigned_fd_count\
	utils/ft_puthex_fd_count\
	sizes/sz_int\
	sizes/sz_hex

LIBFT_SRCS		=\
	atoi\
	atoi_ul\
	hexlen\
	intlen\
	isdigit\
	putchar_fd\
	strlen\
	unsignedlen

CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)

LIBFT_CFILES	=	$(LIBFT_SRCS:%=libft/ft_%.c)
LIBFT_OFILES	=	$(LIBFT_SRCS:%=libft/ft_%.o)

INCLUDES		=	include -I libft

FLAGS			=	-Wall -Werror -Wextra

AR_COMMAND		=	ar rs

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT_OFILES)
	@echo "Linking lib"
	@$(AR_COMMAND) $(NAME) $(OFILES)
	@echo "Done"

%.o: %.c
	@echo "Compiling: $<"
	@clang -g -o $@ -c $< $(FLAGS) -I $(INCLUDES)

clean: _clean
	@echo "Cleaning..."

fclean: _clean
	@echo "Cleaning..."
	@rm -f $(NAME)

_clean:
	@rm -f $(OFILES) $(LIBFT_OFILES)

re: fclean all

bonus: $(NAME)
