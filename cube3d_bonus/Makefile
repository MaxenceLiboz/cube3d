END			=	\033[0m
RED			=	\033[31m
GREEN		=	\033[0;32m
PURPLE		=	\033[35m
BLUE		= 	\033[0;34m

SRCS		=	main_bonus.c											\
				srcs/parsing/initializations_bonus.c					\
				srcs/error/error_utils_bonus.c 							\
				srcs/raycasting/dda_bonus.c 							\
				srcs/raycasting/raycasting_bonus.c 						\
				srcs/raycasting/init_draw_bonus.c 						\
				srcs/raycasting/draw_bonus.c 							\
				srcs/hooks/keys_bonus.c 								\
				srcs/hooks/mouse_bonus.c 								\
				srcs/hooks/hooks_bonus.c 								\

OBJS		=	$(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})
OBJS_DIR	=	objects
MKDIR		=	mkdir -p

INCLUDES	=	includes/cube3d_bonus.h

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror #-g -fsanitize=address

LIBINCLUDES	=	-Iincludes -Iminilibx -Ilibft/includes

LIBFLAGS	=	-framework OpenGL -framework AppKit

LIBS		=	libft/libft.a minilibx/libmlx.a # minilibx/libmlx.a

NAME		=	main

EXEC		= 	cube

RM			=	rm -rf	

all:	 	${LIBS} ${EXEC}

${OBJS_DIR}/%.o: 	%.c $(OBJDIRS) ${INCLUDES} Makefile
			@${MKDIR} $(@D) $(DMPDIR)$(@D)
			@${CC} ${CFLAGS} ${LIBINCLUDES} -c $< -o $@
			@printf "\r\033[K\tCompilation of $(GREEN)$ $< ==> $ $@\$(END)"

${EXEC}:	${NAME}.c ${OBJS}
			@printf "\r\033[K\tCompilation :.c=.o $(GREEN)done\$(END)"
			@$(CC) ${CFLAGS} ${OBJS} ${LIBS} ${LIBFLAGS} -o ${EXEC}
			@printf "\n\tCreating $(GREEN) ${EXEC} $(END)\n"
			
$(LIBS):	${INCLUDES}
			@printf "\n$(BLUE)[ MLX COMPILATION START ]$(END)\n\n"
			@printf "\tCompilation of: $(GREEN)minilibx\$(END)"
			@make -C minilibx &>/dev/null
			@printf "\r\033[K\tCompilation MLX: $(GREEN)done\$(END)\n"
			@printf "\n$(BLUE)[ MLX COMPILATION DONE ]$(END)\n"
			@printf "\n$(BLUE)[ LIBFT COMPILATION START ]$(END)\n\n"
			@make -C libft
			@printf "\n$(BLUE)[ LIBFT COMPILATION DONE ]$(END)\n\n"

norm:
	norminette -R CheckForbiddenSourceHeader srcs main_bonus.c includes/cube3d_bonus.h libft


clean:
			@${RM} ${OBJS}
			@printf "\tDeleting $(RED)$ objetcs \$(END)\n"

fclean:		clean
			@${RM} ${EXEC} ${LIBS}
			@printf "\tDeleting $(RED)$ ${EXEC} \$(END)\n"
			@make clean -C minilibx
			@make clean -C libft
			@printf "\tDeleting $(RED)$ ${LIBS} \$(END)\n"
			@${RM} objects/
			@printf "\tDeleting $(RED)$ objetcs/ \$(END)\n"

re:			fclean all

.PHONY: 	all clean fclean re norm
