END			=	\033[0m
RED			=	\033[31m
GREEN		=	\033[0;32m
PURPLE		=	\033[35m
BLUE		= 	\033[0;34m

SRCS		=	main.c											\
				srcs/draw/draw_grid.c							\
				srcs/draw/draw_utils.c							\
																\
				srcs/help/help.c								\
																\
				srcs/hooks/keys/exit_cube.c 					\
				srcs/hooks/keys/keys_mouvements.c 				\
				srcs/hooks/keys/keys_pressed.c 					\
				srcs/hooks/keys/keys_released.c 				\
																\
				srcs/hooks/mouse/mouse_pressed.c 				\
				srcs/hooks/mouse/mouse_released.c 				\
				srcs/hooks/mouse/update_mouse_pos.c 			\
				srcs/hooks/mouse/mouse_mouvements.c 			\
																\
				srcs/hooks/hooks_management.c 					\
				srcs/hooks/refresh.c 							\
																\
				srcs/maps/edition_map/edition_map_utils.c		\
				srcs/maps/edition_map/edition_map.c				\
																\
				srcs/maps/main_map/main_map_utils.c				\
				srcs/maps/main_map/main_map.c					\
																\
				srcs/maps/mini_map/mini_map.c					\
																\
				srcs/maps/maps_utils.c							\
																\
				srcs/parsing/file/file.c 						\
				srcs/parsing/file/background_file_utils.c		\
				srcs/parsing/file/texture_file_utils.c 			\
				srcs/parsing/file/help_textures.c	 			\
																\
				srcs/parsing/init/init_mlx.c 					\
				srcs/parsing/init/init_main_map.c				\
				srcs/parsing/init/init_edition_map.c			\
				srcs/parsing/init/init_mini_map.c				\
																\
				srcs/parsing/parsing_map.c 						\
																\
				srcs/raycasting/dda.c 							\
				srcs/raycasting/init_draw.c 					\
																\
				srcs/utils/utils.c								\

OBJS		=	$(addprefix ${OBJS_DIR}/, ${SRCS:.c=.o})
OBJS_DIR	=	objects
MKDIR		=	mkdir -p

INCLUDES	=	includes/cube3d.h								\
				includes/alias.h								\
				libft/includes/libft.h							\
				includes/draw.h									\
				includes/hooks.h								\
				includes/init.h									\
				includes/maps.h									\
				includes/parsing.h								\
				includes/raycasting.h							\
				includes/utils.h								\
				includes/structure.h							\


CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror #-O3 #-g #-fsanitize=address

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
	norminette -R CheckForbiddenSourceHeader srcs main.c includes/cube3d.h libft

parsing:	all
	@printf "${BLUE}[ Testing extension ]${END}\n"
	@printf "${BLUE}maps/.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/.cub
	@printf "${BLUE}maps/.cube => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/.cube
	@printf "${BLUE}maps/wext.cube => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/wext.cube
	@printf "${BLUE}maps/wext.map => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/wext1.map

	@printf "\n${BLUE}[ Testing file ]${END}\n"
	@printf "${BLUE}maps/file.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/file.cub
	@printf "${BLUE}maps/file1.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/file1.cub
	@printf "${BLUE}maps/file2.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/file2.cub
	@printf "${BLUE}maps/file3.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/file3.cub
	@printf "${BLUE}maps/file4.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/file4.cub
	@printf "${BLUE}maps/file5.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/file5.cub
	@printf "${BLUE}maps/file6.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/file6.cub
	@printf "${BLUE}maps/file7.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/file7.cub
	@printf "${BLUE}maps/file8.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/file8.cub
	@printf "${BLUE}maps/file9.cub => ${END}"
	@leaks -atExit -q -- ./${EXEC} maps/file9.cub

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
