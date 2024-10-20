
AS		= nasm
ASFLAGS	= -felf64
AR        = ar
ARFLAGS        = src
LINK	= ld
RM		= rm -f
SRC		= ft_strlen.s ft_strcpy_safe.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_atoi_base.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s
OBJ			= $(SRC:%.s=%.o)
NAME		= libasm.a
HEADF		= libasm.h

.s.o:
	${AS} ${ASFLAGS} $< -o ${<:.s=.o}

$(NAME): ${OBJ}
	${AR} ${ARFLAGS} ${NAME} ${OBJ}

all:        ${NAME}

clean:        
	${RM} ${OBJ}
	${RM} a.out

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re