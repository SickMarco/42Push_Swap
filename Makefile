NAME = push_swap

SRC = main.c check.c sorting_move.c sorting_move2.c sorting_utils.c minisort.c bigsort.c \
      lis.c bigsort_utils.c selector.c mover.c

SRC_B = checker.c checker_utils.c check.c sorting_move_b.c sorting_move2_b.c

SRC_DIR = ./Src/

SRC_DIR_B = ./Src_Bonus/

SRCP = $(addprefix $(SRC_DIR),$(SRC))

SRCPB = $(addprefix $(SRC_DIR_B),$(SRC_B))

OBJ = $(SRCP:.c=.o)

OBJ_B = $(SRCPB:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fPIE -g

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
	@rm -rf $(OBJ) $(OBJ_B)
	@make clean -s -C Src/MyLib

fclean: clean
	@echo "\033[0;31mRemoving $(NAME) 🗑\033[0;37m"
	@rm -rf $(NAME)
	@rm -rf checker
	@make fclean -s -C Src/MyLib

re: fclean all

bonus: lib $(OBJ_B)
	@echo "\033[32mCompiling checker 🚀"
	@gcc $(CFLAGS) $(OBJ_B) ./Src/MyLib/mylib.a -o checker
	@echo "Compiled ✅\033[0;37m"

.SILENT: $(OBJ) lib $(OBJ_B)
