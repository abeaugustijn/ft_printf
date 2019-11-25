# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: abe <abe@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/04 19:52:15 by abe            #+#    #+#                 #
#    Updated: 2019/11/25 15:26:53 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
SRCS			=\
	handle_format\
	main output\
	t_format_info/t_fi_check_width_precision\
	t_format_info/t_fi_create\
	t_format_info/t_fi_get_info\
	t_format_info/t_fi_handle_plus_space\
	t_format_info/t_fi_handle_zero_minus\
	formats/f_char\
	formats/f_int\
	formats/f_string\
	formats/f_percentage\
	formats/f_hex\
	utils/ft_putchar_fd_count\
	utils/ft_putstr_fd_count\
	utils/ft_putstr_n_fd_count

BONUS_SRCS		=	

TESTS_SRCS		=\
	string

CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)

BONUS_CFILES	=	$(BONUS_SRCS:%=src/%_bonus.c)
BONUS_OFILES	=	$(BONUS_SRCS:%=src/%_bonus.o)

TESTS_CFILES	=	$(TESTS_SRCS:%=tests/%.c)
TESTS_OFILES	=	$(TESTS_SRCS:%=tests/%.o)

INCLUDES		=	include -I libft

FLAGS			=	-Wall -Werror -Wextra
#FLAGS			=

AR_COMMAND		=	ar rs

LIBFT_DIR		=	./libft

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Linking lib"
	@$(AR_COMMAND) $(NAME) $(OFILES) libft/*.o
	@echo "Done"

%.o: %.c libft/libft.a
	@echo "Compiling: $<"
	@clang -g -o $@ -c $< $(FLAGS) -I $(INCLUDES)

clean: _clean
	@echo "Cleaning..."
	@make clean -C libft

fclean: _clean
	@echo "Fucking cleaning..."
	@make fclean -C libft
	@rm -f $(NAME)

_clean:
	@rm -f $(OFILES) $(BONUS_OFILES)

re: fclean all 

bonus: $(OFILES) $(BONUS_OFILES) $(NAME)
	@echo "Linking bonus lib"
	@$(AR_COMMAND) $(NAME) $(OFILES) $(BONUS_OFILES)
	@echo "Bonus done"

libft/libft.a:
	make -C libft

main: main.c
	@clang -g -o main\
		-Wall -Werror -Wextra\
		-I $(INCLUDES)\
		$(FLAGS)\
		$(CFILES)\
		libft/*.c\
		main.c

test:
	@clang -o run_tests\
		-I $(INCLUDES)\
		$(TESTS_CFILES)\
		$(FLAGS)\
		$(CFILES)\
		libft/*.c\
		-I/Users/aaugusti/.brew/include\
		-L/Users/aaugusti/.brew/lib\
		-lcriterion\
		-Wformat=0
	./run_tests
