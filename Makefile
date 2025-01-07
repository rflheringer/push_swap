NAME			=	push_swap
# BONUS_NAME		=	checker
RM				=	rm -f
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

SRC_PATH		=	./mandatory
# BONUS_PATH		=	./src_bonus
INC_PATH		=	./include
LIB_PATH		=	./libs/libft

SRC				=	push_swap.c \
					big_sort_utils.c \
					big_sort.c \
					handle_errors.c \
					handle_nodes.c \
					handle_sort.c \
					handle_stacks.c \
					init_push_swap.c \
					push_swap.c \
					small_sort.c \
					validate_arguments.c 

# BONUS_SRC		=	checker.c \
# 					get_args_bonus.c \
# 					init_stack_bonus.c \
# 					operations_bonus.c \
# 					checker_utils.c

OBJ				=	$(addprefix $(SRC_PATH)/, $(SRC:.c=.o))
BONUS_OBJ		=	$(addprefix $(BONUS_PATH)/, $(BONUS_SRC:.c=.o))

INC				=	-I$(INC_PATH)

LIBFT			=	$(LIB_PATH)/libft.a

all:				$(NAME)

$(LIBFT):
					make -C $(LIB_PATH) -s

$(NAME):			$(LIBFT) $(OBJ)
						$(CC) $(CFLAGS) $(OBJ) -L$(LIB_PATH) -lft -o $(NAME)

$(SRC_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

bonus:				$(BONUS_NAME)

$(BONUS_NAME):		$(LIBFT) $(BONUS_OBJ)
						$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIB_PATH) -lft -o $(BONUS_NAME)

$(BONUS_PATH)%.o: $(BONUS_PATH)%.c $(INC_PATH)/checker.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

val: all
	@valgrind --quiet --leak-check=full --show-leak-kinds=all ./$(NAME)
	
clean:
					$(RM) $(OBJ) $(BONUS_OBJ)
					make clean -C $(LIB_PATH) -s

fclean:				clean
					$(RM) $(NAME) $(BONUS_NAME)
					make fclean -C $(LIB_PATH) -s

re:					fclean all

.PHONY:		all bonus clean fclean re