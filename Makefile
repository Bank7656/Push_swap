CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -fsanitize=address

SRC = push_swap.c

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
## 	test:	Test the program with a simple case
##  
## Cleaning:
## 	clean:	Remove objects file
## 	fclean:	Remove program and objects file


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS) $(HEADER) 
	@echo "$(COLOUR_GREEN)Compile push_swap program$(END_COLOUR)"

	$(CC) $(CFLAGS) $(OBJS) -L. -lft -o $(NAME)
	
	@echo "$(COLOUR_GREEN)\n[push_swap] was created successfully >_< $(END_COLOUR)"

$(OBJ_DIR)%.o: %.c
	@echo "$(COLOUR_GREEN)Compile .c into .o$(END_COLOUR)"

	$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

	@echo "" # Newline

$(OBJ_DIR):
	@echo "$(COLOUR_GREEN)Create object directory$(END_COLOUR)"

	mkdir $(OBJ_DIR)

	@echo "" # Newline

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) ./

test: $(NAME)
# Only one number
	@echo "$(COLOUR_BLUE)[Only one number.]$(END_COLOUR)"
	./$(NAME) 123456 
	./$(NAME) "123456"
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
	./$(NAME) "2" "6" "3" "5" "1" "2"
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
	
	rm -f $(LIBFT)

	$(MAKE) clean -C $(LIBFT_DIR)

	rm -rf $(OBJ_DIR)
	
	@echo "" # Newline
	
fclean:
	@echo "$(COLOUR_GREEN)Delete push_swap program$(END_COLOUR)"

	rm -f $(LIBFT)

	$(MAKE) fclean -C $(LIBFT_DIR)

	rm -f $(NAME)

	@echo "$(COLOUR_GREEN)\nDelete objects$(END_COLOUR)"

	rm -rf $(OBJ_DIR)

	@echo "" # Newline


re: fclean all 

help:
	@sed -ne '/@sed/!s/## //p' $(MAKEFILE_LIST)

.PHONY: clean fclean test re