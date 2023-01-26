NAME = push_swap

SRC = main.c list_utils.c check.c start_sorting.c sorting_move.c sorting_move2.c minisort.c bigsort.c

SRC_DIR = ./Src/

SRCP = $(addprefix $(SRC_DIR),$(SRC))

OBJ = $(SRCP:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIB = ./Src/MyLib/mylib.a

all: lib $(NAME)

lib:
	make -s -C Src/MyLib

$(NAME): $(OBJ)
	@echo "\033[32mCompiling $(NAME) 🚀"
	@gcc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "Compiled ✅\033[0;37m"

clean:
	@echo "\033[0;31mCleaning objects 🧹"
	@rm -rf $(OBJ)
	@make clean -s -C Src/MyLib

fclean: clean
	@echo "\033[0;31mRemoving $(NAME) 🗑\033[0;37m"
	@rm -rf $(NAME)
	@make fclean -s -C Src/MyLib

re: fclean all

.SILENT: $(OBJ) lib
