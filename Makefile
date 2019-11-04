# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abe <abe@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/04 19:52:15 by abe            #+#    #+#                 #
#    Updated: 2019/11/04 21:26:10 by abe           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
SRCS			=	printf parse_format var_new next_format_char\
	char_to_var_type testmain
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

all: $(NAME)

$(NAME): libft $(OFILES)
	@echo "Linking lib"
	@$(AR_COMMAND) $(NAME) $(OFILES)
	@echo "Done"

%.o: %.c
	@echo "Compiling: $<"
	@gcc -o $@ -c $< $(FLAGS) -I $(INCLUDES) -L $(LIBFT_LIB)

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

libft:
	@echo "Making libft"
	@make -C $(LIBFT_DIR)

bonus: libft $(OFILES) $(BONUS_OFILES) $(NAME)
	@echo "Linking bonus lib"
	@$(AR_COMMAND) $(NAME) $(OFILES) $(BONUS_OFILES)
	@echo "Bonus done"
