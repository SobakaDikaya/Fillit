NAME = fillit
SRCS = ./srcs/main.c ./srcs/error.c ./srcs/readfile.c ./srcs/createandresizefigure.c ./srcs/setpoint.c ./srcs/validfigure.c ./srcs/solution.c ./srcs/map.c
INCLUDES = includes/
BUILDFOLDER = ./build/

all: $(NAME)

debug: check_folder
	cd libft && make
	gcc -g -Wall -Wextra -Werror ${SRCS} ./libft/libft.a -I${INCLUDES} -o ${BUILDFOLDER}$(NAME)

$(NAME):
	cd libft && make
	gcc -Wall -Wextra -Werror ${SRCS} ./libft/libft.a -I${INCLUDES} -o $(NAME)

check_folder:
	if [ ! -d ${BUILDFOLDER} ]; then \
		mkdir ${BUILDFOLDER}; \
	fi

clean:
	cd libft && make clean
	rm -f *.o

fclean:
	cd libft && make fclean
	rm -f $(NAME)

re: fclean $(NAME)

re_d: fclean debug
