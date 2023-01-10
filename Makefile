NAME = push_swap

SRC = main.c num_list.c

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
