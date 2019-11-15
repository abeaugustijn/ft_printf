# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: abe <abe@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/04 19:52:15 by abe            #+#    #+#                 #
#    Updated: 2019/11/15 15:17:47 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
SRCS			=\
	handle_format\
	main output\
	t_format_info/t_fi_check_width_precision\
	t_format_info/t_fi_create\
	t_format_info/t_fi_get_info\
	formats/f_char\
	formats/f_int\
	formats/f_string

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

AR_COMMAND		= ar rs

LIBFT_DIR		= ./libft

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Linking lib"
	@$(AR_COMMAND) $(NAME) $(OFILES)
	@echo "Done"

%.o: %.c libft
	@echo "Compiling: $<"
	@gcc -o $@ -c $< $(FLAGS) -I $(INCLUDES) -lft -Llibft

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
	@make re -C libft

bonus: $(OFILES) $(BONUS_OFILES) $(NAME)
	@echo "Linking bonus lib"
	@$(AR_COMMAND) $(NAME) $(OFILES) $(BONUS_OFILES)
	@echo "Bonus done"

test:
	@gcc -o run_tests\
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
