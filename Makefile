NAME = so_long

MY_SOURCES    = srcs/main.c srcs/verif_map.c srcs/parsing.c srcs/moves.c srcs/get_file.c srcs/minilibx_events.c srcs/verif_path.c

MY_OBJECTS    = $(MY_SOURCES:.c=.o)

INCLUDES = -I minilibx-linux/ -I includes/

CC = cc

FLAGS = -Wall -Wextra -Werror -g

FSAN = ${FLAGS} -fsanitize=address

LBS = -L ./minilibx-linux/ -lmlx -lX11 -lXext

MAKEFLAGS += --no-print-directory

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${LBS} ${INCLUDES}

all:        ${NAME}

${NAME}:    ${MY_OBJECTS}
			${CC} ${FLAGS} -o ${NAME} ${MY_OBJECTS} ${LBS}

map:		
			./map.sh 50 50 10 5	

fsan:		${MY_OBJECTS}
			${CC} ${FSAN} -o ${NAME} ${MY_OBJECTS} ${LBS}

install:
			sudo apt update && sudo apt install gcc && sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

clean:
			rm -f ${MY_OBJECTS}

fclean:     clean
			rm -f ${NAME}

re:         fclean all
