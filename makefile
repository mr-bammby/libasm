
AS		= nasm
ASFLAGS	= -felf64
AR        = ar
ARFLAGS   = src

RM		= rm -f
SRC_DIR		= src/
OBJ_DIR		= obj/
MAIN_SRC	= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
BONUS_SRC	= ft_atoi_base.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s
MAIN_OBJ	= $(MAIN_SRC:%.s=%.o)
BONUS_OBJ	= $(BONUS_SRC:%.s=%.o)
MAIN_OBJ_FILES	= $(addprefix $(OBJ_DIR),$(MAIN_OBJ))
BONUS_OBJ_FILES	= $(addprefix $(OBJ_DIR),$(BONUS_OBJ))
OBJF 		= $(SRCF:$(SRCD)%.c=$(OBJD)%.o)
NAME		= libasm.a
HEADF		= libasm.h

${OBJ_DIR}%.o: $(SRC_DIR)%.s
	@mkdir -p $(OBJ_DIR)
	${AS} ${ASFLAGS} $< -o $@

$(NAME): ${MAIN_OBJ_FILES}
	${AR} ${ARFLAGS} ${NAME} ${MAIN_OBJ_FILES}

bonus: ${BONUS_OBJ_FILES}
	${AR} ${ARFLAGS} ${NAME} ${BONUS_OBJ_FILES}

all:  ${MAIN_OBJ_FILES}  ${BONUS_OBJ_FILES}
	${AR} ${ARFLAGS} ${NAME} ${MAIN_OBJ_FILES} ${BONUS_OBJ_FILES}

clean:        
	${RM} ${MAIN_OBJ_FILES} ${BONUS_OBJ_FILES}


fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bouns