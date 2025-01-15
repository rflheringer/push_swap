NAME			=	push_swap
BONUS_NAME		=	checker
RM				=	rm -f
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3

SRC_PATH		=	./mandatory
BONUS_PATH		=	./bonus
INC_PATH		=	./include
LIB_PATH		=	./libs/libft
CMD_PATH 		= 	movments/
CMD_PATH_BONUS 	= 	./movments_bonus/

SRC				=	$(CMD_PATH)push.c \
                    $(CMD_PATH)reverse_rotate.c \
                    $(CMD_PATH)rotate.c \
                    $(CMD_PATH)swap.c \
                    push_swap.c \
                    big_sort_utils.c \
                    big_sort.c \
                    handle_errors.c \
                    handle_nodes.c \
                    handle_sort.c \
                    handle_stacks.c \
                    init_push_swap.c \
                    small_sort.c \
                    validate_arguments.c 

BONUS_SRC		=	$(CMD_PATH_BONUS)push_bonus.c \
                    $(CMD_PATH_BONUS)reverse_rotate_bonus.c \
                    $(CMD_PATH_BONUS)rotate_bonus.c \
                    $(CMD_PATH_BONUS)swap_bonus.c \
					checker.c \
					handle_errors_bonus.c \
					handle_nodes_bonus.c \
					handle_stacks_bonus.c \
					init_push_swap_bonus.c \
					read_commands_bonus.c \
					validate_arguments_bonus.c

OBJ				=	$(addprefix $(SRC_PATH)/, $(SRC:.c=.o))
BONUS_OBJ		=	$(addprefix $(BONUS_PATH)/, $(BONUS_SRC:.c=.o))

LIBFT			=	$(LIB_PATH)/libft.a

all:			libft	$(NAME) 

libft:
	make -C $(LIB_PATH) -s

# $(PRINTF):
# 	make -C $(PRINTF_PATH) -s

$(NAME):			$(LIBFT)  $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIB_PATH) -lft -o $(NAME)

# $(NAME):			$(LIBFT) $(PRINTF) $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -L$(LIB_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(NAME)

$(SRC_PATH)/movments/%.o: $(SRC_PATH)/movments/%.c $(INC_PATH)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus:				$(BONUS_NAME)

$(BONUS_NAME):		$(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIB_PATH) -lft -o $(BONUS_NAME)

# $(BONUS_NAME):		$(LIBFT) $(PRINTF) $(BONUS_OBJ)
# 	$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIB_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(BONUS_NAME)

$(BONUS_PATH)/%.o: $(BONUS_PATH)/%.c $(INC_PATH)/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

# val: all
# 	@valgrind --quiet --leak-check=full --show-leak-kinds=all ./$(NAME)
	
clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	make clean -C $(LIB_PATH) -s
	make clean -C $(PRINTF_PATH) -s

fclean:				clean
	$(RM) $(NAME) $(BONUS_NAME)
	make fclean -C $(LIB_PATH) -s
	make fclean -C $(PRINTF_PATH) -s

re:					fclean all

.PHONY:		all bonus clean fclean re