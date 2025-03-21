CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g

SRC	= push_swap.c input_handle.c node.c stack.c exit.c swap.c \
		push.c rotate.c reverse_rotate.c sort.c divide_and_conquer.c \
		divide.c conquer_utils.c conquer_utils2.c

OBJECTS = $(SRC:.c=.o)
OBJ_DIR = ./objects/
OBJS = $(addprefix $(OBJ_DIR), $(OBJECTS))

HEADER = push_swap.h
HEADER_DIR = ./

# Libft
LIBFT_NAME = libft.a
LIBFT_DIR := ./libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

NAME = push_swap

# Text color setup 
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
END_COLOUR=\033[0m

## ---------------------------------------------------------------------------
## Push_swap:
## This project will make you sort data on a stack, with a 
## limited set of instructions, using the lowest possible number of actions. 
## To succeed you’ll have to manipulate various types of algorithms and choose
## the most appropriate solution (out of many) for an optimized data sorting.
## ---------------------------------------------------------------------------
## Usage: make [target] ...
## 
## Miscellaneous:
## 	help:	Show this help
##  
## Build:
## 	all:	Create Push_swap program
## 	bonus:  Create Checker program
## 	test:	Test the program with a simple case
##  
## Cleaning:
## 	clean:	Remove objects file
## 	fclean:	Remove program and objects file

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS) $(HEADER) 
	@echo "$(COLOUR_GREEN)Compile push_swap program$(END_COLOUR)"

	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	
	@echo "$(COLOUR_GREEN)\n[push_swap] was created successfully >_< $(END_COLOUR)"

$(OBJ_DIR)%.o: %.c
	@echo "$(COLOUR_GREEN)Compile .c into .o$(END_COLOUR)"

	$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

	@echo "" # Newline

$(OBJ_DIR):
	@echo "$(COLOUR_GREEN)Create object directory$(END_COLOUR)"

	mkdir $(OBJ_DIR)

	@echo "" # Newline

$(LIBFT) : $(LIBFT_OBJS)
	@echo "$(COLOUR_GREEN)Create libft.a$(END_COLOUR)"
	$(MAKE) -C $(LIBFT_DIR)
	@echo "$(COLOUR_GREEN)[libft.a was created successfully] >_<\n$(END_COLOUR)"

$(LIBFT_OBJS):
	$(MAKE) -C $(LIBFT_DIR)


BONUS_SRC = checker_bonus.c checker_utils_bonus.c exit_bonus.c stack_bonus.c node_bonus.c \
			input_handle_bonus.c swap_bonus.c push_bonus.c rotate_bonus.c reverse_rotate_bonus.c
BONUS_OBJECTS = $(BONUS_SRC:.c=.o)
BONUS_OBJ_DIR = ./objects_bonus/
BONUS_HEADER_DIR = ./
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_OBJECTS))
BONUS_HEADER = checker_bonus.h
BONUS_NAME = checker


bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(HEADER) $(BONUS_OBJ_DIR) $(BONUS_HEADER) $(BONUS_OBJS) 
	@echo "$(COLOUR_GREEN)Compile checker program$(END_COLOUR)"
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L./libft -lft -o $(BONUS_NAME)
	@echo "$(COLOUR_GREEN)\n[checker] was created successfully >_< $(END_COLOUR)"

$(BONUS_OBJ_DIR)%.o: %.c
	@echo "$(COLOUR_GREEN)Compile .c into .o$(END_COLOUR)"

	$(CC) $(CFLAGS) -I $(BONUS_HEADER_DIR) -c $< -o $@

$(BONUS_OBJ_DIR):
	@echo "$(COLOUR_GREEN)Create object directory$(END_COLOUR)"

	mkdir $(BONUS_OBJ_DIR)

	@echo "" # Newline

test: $(NAME)
	@echo "\n$(COLOUR_BLUE)[Test input arguments]$(END_COLOUR)\n"
# Only one number
	@echo "$(COLOUR_BLUE)[Only one number.]$(END_COLOUR)"
	./$(NAME) 123456 | ./checker_Mac 123456
	./$(NAME) "123456" | ./checker_Mac "123456"
# Correct number list
	@echo "$(COLOUR_BLUE)[Number list.]$(END_COLOUR)"
	./$(NAME) 2 6 3 5 1 4 -2 -6 -3 -5 -1 -4
	./$(NAME) "2 6 3 5 1 4 -2 -6 -3 -5 -1 -4"
	./$(NAME) "2" "6" "3" "5" "1" "4" "-2" "-6" "-3" "-5" "-1" "-4"
# Space
	@echo "$(COLOUR_BLUE)[Spaces]$(END_COLOUR)"
	./$(NAME) 2  1 6 7  8 5 -4 
	./$(NAME) "2  1 6 7  8 5 -4"
	./$(NAME) "2 1  6  7" 8 5 -4
# Duplicate
	@echo "$(COLOUR_BLUE)[Duplicate Number in the list]$(END_COLOUR)"
	./$(NAME) 2 6 3 5 1 2
	./$(NAME) "2 6 3 5 1 2"
	./$(NAME) "2" "6" "3" "5" "1" ""
# Not a digit
	@echo "$(COLOUR_BLUE)[Not a digit]$(END_COLOUR)"
	./$(NAME) a 3 2 1
	./$(NAME) "a 3 2 1"
	./$(NAME) "a" "3" "2" "1"
# Mix
	@echo "$(COLOUR_BLUE)[Mix]$(END_COLOUR)"
	./$(NAME) "4 7 8  9" -1 -5 7 20
	./$(NAME) "fsjfsadf" 1 2 3 " 3" "04"

clean:
	@echo "$(COLOUR_GREEN)Delete objects$(END_COLOUR)"

	rm -rf $(OBJ_DIR)

	@echo "$(COLOUR_GREEN)Delete bonus objects$(END_COLOUR)"

	rm -rf $(BONUS_OBJ_DIR)
	
	@echo "$(COLOUR_GREEN)Remove libft objects$(END_COLOUR)"

	$(MAKE) clean -C $(LIBFT_DIR)
	
	@echo "" # Newline
	
fclean:
	@echo "$(COLOUR_GREEN)Delete push_swap program$(END_COLOUR)"

	rm -f $(NAME)

	@echo "$(COLOUR_GREEN)Delete checker program$(END_COLOUR)"
	
	rm -f $(BONUS_NAME)

	@echo "$(COLOUR_GREEN)Remove libft objects and libft.a$(END_COLOUR)"
	$(MAKE) fclean -C $(LIBFT_DIR)

	@echo "$(COLOUR_GREEN)\nDelete objects$(END_COLOUR)"

	rm -rf $(OBJ_DIR)

	@echo "$(COLOUR_GREEN)Delete bonus objects$(END_COLOUR)"

	rm -rf $(BONUS_OBJ_DIR)

	@echo "" # Newline

	


re: fclean all 

help:
	@sed -ne '/@sed/!s/## //p' $(MAKEFILE_LIST)

.PHONY: clean fclean test help re
