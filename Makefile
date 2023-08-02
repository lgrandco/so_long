NAME = so_long

MY_SOURCES    = srcs/main.c srcs/all_verifs.c srcs/parsing.c srcs/moves.c srcs/get_file.c srcs/minilibx_events.c

MY_OBJECTS    = $(MY_SOURCES:.c=.o)

INCLUDES = -I minilibx-linux/ -I includes/

CC = cc

FLAGS = -Wall -Wextra -Werror -g3

LBS = -L minilibx-linux/ -lmlx -lX11 -lXext

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${LBS} ${INCLUDES}

all:        ${NAME}

${NAME}:    ${MY_OBJECTS}
			${CC} ${FLAGS} -o ${NAME} ${MY_OBJECTS} ${LBS}

install:
			sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

clean:
			rm -f ${MY_OBJECTS}

fclean:     clean
			rm -f ${NAME}

re:         fclean all
