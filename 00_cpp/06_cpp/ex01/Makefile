NAME = ex00
MODE ?= normal
CC = c++
CFLAGS = -Wall -Wextra  -Werror -std=c++98 -g3

ifeq ($(MODE), hard)
CFLAGS += \
	-Werror=unused-variable -Werror=unused-function -Werror=pointer-arith \
	-Werror=uninitialized -Werror=return-type  
else ifeq ($(MODE), math)
CFLAGS += \
	-Werror=unused-variable -Werror=unused-function -Werror=pointer-arith \
	-Werror=uninitialized -Werror=return-type  \
	-Wno-error=sign-conversion  -Wno-error=conversion -Wno-error=float-conversion -Wconversion
else ifeq ($(MODE), debug)
CFLAGS += -g3 -O0 #-DDEBUG
else ifeq ($(MODE), release)
CFLAGS += -g3 -flto -march=native 
else ifeq ($(MODE), noflags)
CFLAGS = -std=c++98
endif

SRC_DIR = src
SRCS = $(SRC_DIR)/main.cpp \
	   $(SRC_DIR)/ScalarConverter.cpp


OBJ_DIR = obj
OBJ = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
ifeq ($(MODE), valgrind)
	valgrind ./$(NAME)
else ifeq ($(MODE), normal)
	./$(NAME)
else ifeq ($(MODE), gdb)
	gdb ./$(NAME)
endif 
test: all
	./$(NAME) 1
	@echo ""
	./$(NAME) 100
	@echo ""
	./$(NAME) -1000
	@echo ""
	./$(NAME) 127
	@echo ""
	./$(NAME) 0
	@echo ""
	./$(NAME) -inf
	@echo ""
	./$(NAME) 102
	@echo ""
	./$(NAME) Abcd!
	@echo ""
	./$(NAME) 1ab
	@echo ""
	./$(NAME) -1ab
	@echo ""
	./$(NAME) c
	@echo ""
	./$(NAME) x
	@echo ""
	./$(NAME) "*"
	@echo ""
	./$(NAME) -
	@echo ""
	./$(NAME) ....
	@echo ""
	./$(NAME) 120...20
	@echo ""
	./$(NAME) 100.1024
	@echo ""
	./$(NAME) -100.1024
	@echo ""
	./$(NAME) 42.0f
	@echo ""
	./$(NAME) 42.0a
	@echo ""
	./$(NAME) .
	@echo ""
	./$(NAME) ffff
	@echo ""
	./$(NAME) abcf
	@echo ""
	./$(NAME) 120ffff
	@echo ""
	./$(NAME) 90.f
	@echo ""
	./$(NAME) 90.



.PHONY: all clean fclean re
