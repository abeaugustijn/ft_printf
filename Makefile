# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: abe <abe@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/04 19:52:15 by abe            #+#    #+#                 #
#    Updated: 2019/11/12 10:53:56 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
SRCS			=	printf parse_format var_new next_format_char\
	char_to_var_type
BONUS_SRCS		=	
CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)
BONUS_CFILES	=	$(BONUS_SRCS:%=src/%_bonus.c)
BONUS_OFILES	=	$(BONUS_SRCS:%=src/%_bonus.o)
INCLUDES		=	include -I libft
FLAGS			=	-Wall -Werror -Wextra
# FLAGS			=	

AR_COMMAND		= ar rs

LIBFT_DIR		= ./libft
LIBFT_LIB		= ./libft/libft.a

test:
	@make -C libft
	clang -g test.c src/*.c src/**/*.c -L./libft -lft -Ilibft -Iinclude

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Linking lib"
	@$(AR_COMMAND) $(NAME) $(OFILES)
	@echo "Done"

%.o: %.c libft
	@echo "Compiling: $<"
	@gcc -o $@ -c $< $(FLAGS) -I $(INCLUDES)

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
