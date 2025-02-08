NAME		:= ScavTrap
CFLAGS		:= -Wextra -Wall -Werror -std=c++98
SRCS_PATH	:= ./src/
.SILENT:

HEADERS		:= -I ./includes

SRCS		:= $(addprefix $(SRCS_PATH), \
				main.cpp \
				ClapTrap.cpp\
				ScavTrap.cpp\
			)

OBJS		:= $(SRCS:$(SRCS_PATH)%.cpp=obj/%.o)

all: ${NAME}

${NAME}: ${OBJS}
	@c++ ${CFLAGS} ${HEADERS} ${OBJS} -o ${NAME}

obj/%.o: ${SRCS_PATH}%.cpp | obj_dirs
	@c++ ${CFLAGS} -c ${HEADERS} $< -o $@
	@printf "Compiling: ${notdir $<}\n"

obj_dirs:
	@mkdir -p $(dir ${OBJS})

clean:
	@rm -rf obj

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
