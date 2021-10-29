CC= gcc
CFLAGS= -Wall -Werror -Wextra
SRCS= main.c can_you_place_it.c delete.c display_map.c draw_on_map.c ft_calloc.c ft_memset.c ft_putchar.c ft_putendl.c ft_putnbr.c ft_putstr.c ft_strcmp.c ft_strdup.c ft_strlen.c ft_strncpy.c listmap.c placement_recursion.c resize_tetra.c sqr_side_calc.c tetra_analyser.c tetra_parser.c
OBJS= main.o can_you_place_it.o delete.o display_map.o draw_on_map.o ft_calloc.o ft_memset.o ft_putchar.o ft_putendl.o ft_putnbr.o ft_putstr.o ft_strcmp.o ft_strdup.o ft_strlen.o ft_strncpy.o listmap.o placement_recursion.o resize_tetra.o sqr_side_calc.o tetra_analyser.o tetra_parser.o
NAME= fillit

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS):	$(SRC)
			$(CC) -c $(CFLAGS) $(SRCS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
			
