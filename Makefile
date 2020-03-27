SRC	=	src/display_usage.c					\
		src/parsing/get_tetriminos_list.c	\
		src/parsing/get_file_content.c		\
		src/parsing/initialize_tetrimino.c	\
		src/parsing/get_shape.c				\
		src/parsing/error_detection.c		\
		src/config/init_config.c			\
		src/config/config_controls.c		\
		src/config/config_ui.c				\
		src/config/config_options.c			\
		src/debug_mode/debug_mode.c 		\
		src/debug_mode/sort_tetriminos.c 	\
		src/game/game_loop.c				\
		src/game/launch_game.c				\
		src/game/set_move.c					\
		src/game/display_game.c     		\
		src/game/move_tetrimino.c			\
		src/game/display_score.c			\
		src/game/clock.c					\
		src/game/test_collision.c			\
		src/game/get_tetro_by_id.c			\
		src/game/display_board.c			\
		src/game/player_next_piece.c		\
		src/game/easy_spin.c				\
		src/game/calcul_rotation.c			\
		src/game/high_score.c				\

MAIN =	main.c

OBJ	=	$(SRC:.c=.o)

MAIN_OBJ = 	$(MAIN:.c=.o)

CFLAGS = -Wall -Wextra -fdiagnostics-color -Iinclude/ -Llib/fae/ -lfae -Llib/list/ -llist -lncurses -g3

NAME =	tetris

TEST =	tetris.out

DEBUG =	tetris.debug

all: $(NAME)

make_lib:
	make -C lib/fae/
	make -C lib/list/

$(NAME): make_lib $(OBJ) $(MAIN_OBJ)
	gcc -o $(NAME) $(MAIN_OBJ) $(OBJ) $(CFLAGS)

debug: make_lib $(OBJ) $(MAIN_OBJ)
	gcc -g3 -o $(DEBUG) $(MAIN_OBJ) $(OBJ) $(CFLAGS)

tests_run: make_lib
	gcc -o $(TEST) $(OBJ) $(CFLAGS)
	./$(TEST)

retest: fclean tests_run

clean:
	make clean -C lib/fae/
	make clean -C lib/list/
	rm -f $(OBJ) $(MAIN_OBJ)

fclean: clean
	make fclean -C lib/fae/
	make fclean -C lib/list/
	rm -f $(TEST) $(NAME)

re: fclean all
