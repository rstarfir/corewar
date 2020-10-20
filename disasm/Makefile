NAME = disassembler

CC = clang
CFLAGS = -Wall -Wextra -Werror

SRC_LIST = op.c open_func.c parse_arg.c parse_instruct.c parse_m_c.c print_utils.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER_DIR = inc/
HEADER_LIST= disasm.h op.h
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

LIBFT_H = ../libft/includes/
LIBFT_SRC = ../libft
LIBFT = ../libft/libft.a

RED = "\033[0;31m"
GREEN = "\033[0;32m"
WHITE_B = "\033[1m"
WHITE = "\033[0m"

.PHONY: all clean fclean re FAKE

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) $(LIBFT_H) src/disassembler.c
		@gcc -o ../$(NAME) src/disassembler.c $(OBJECTS) -I$(HEADER_DIR) -I$(LIBFT_H) $(LIBFT)
		@echo $(GREEN) disassembly created! $(WHITE)

$(OBJECTS): %.o: %.c $(HEADER) $(LIBFT_H)
		@$(CC) $(CFLAGS) -o $@ -c $< -I$(HEADER_DIR) -I$(LIBFT_H)
		@echo disassembly file: $(GREEN) $< $(WHITE)

$(LIBFT): FAKE
		@$(MAKE) -C $(LIBFT_SRC)

clean:
		@/bin/rm -f $(OBJECTS)
		@echo $(WHITE_B) *.o files deleted!$(WHITE)

fclean: clean
		@/bin/rm -f ../$(NAME)

re: fclean all
