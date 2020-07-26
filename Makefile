#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loram <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/22 03:38:06 by loram             #+#    #+#              #
#    Updated: 2020/07/22 03:38:08 by loram            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CHECKER = checker
PUSH_SWAP = push_swap
COMPLEXITY = complexity

SRC_DIR = src/
UTIL_DIR = util/
CMD_DIR = cmd/
LFT_DIR = libft/
OBJ_DIR = obj/
HEADERS = inc/

UTIL =  ft_lstpush.c \
        ft_atoi_ps.c \
		ft_del_mstack.c \
		ft_lstswp.c \
		ft_lst_rr.c \
		ft_lst_rrr.c \
		ft_exit.c \
		ft_lstfree.c \
		ft_lstprint.c \
		ft_lstsize.c \
		ft_lstsorted.c \
		ft_mini_sort_four_a_two.c \
		ft_mini_sort_four_a_one.c \
		ft_mini_sort_four_b_one.c \
		ft_mini_sort_four_b_two.c \
		ft_mini_sort_three_ab.c \
		ft_mstack_pop.c \
		ft_mstack_push.c \
		ft_print_complexity.c
SRC =  command_in.c \
		div_parts_a.c \
		div_parts_b.c \
		div_sort_parts.c \
		init_ps.c \
		mini_sorting.c \
		move_up_part.c \
		parse_in.c \
		print_status.c \
		ps_hint.c
CMD =  ps.c \
		rr.c \
		rrr.c
CSRC = checker.c
PSRC = push_swap.c
CMSRC = complexity.c
SRC_DIRS = $(UTIL_DIR) $(SRC_DIR) $(CMD_DIR)

OBJ_CMD = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(CMD)))
OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))
OBJ_UTIL = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(UTIL)))
OBJS = $(OBJ) $(OBJ_UTIL) $(OBJ_CMD)
OBJ_CSRC = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(CSRC)))
OBJ_PSRC = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(PSRC)))
OBJ_CMSRC = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(CMSRC)))

INCLUDES = -I $(HEADERS) -I $(LFT_DIR)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L$(LFT_DIR)
LFT = $(addprefix $(LFT_DIR), libft.a)

.PHONY: all clean fclean re

all: $(PUSH_SWAP) $(CHECKER) $(COMPLEXITY)

$(CHECKER): $(LFT) $(OBJ_DIR) $(OBJS) $(OBJ_CSRC)
	@echo "\033[32mmaking checker...\033[0m"
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(OBJ_CSRC) $(INCLUDES) $(LFT) -o $(CHECKER)

$(PUSH_SWAP): $(LFT) $(OBJ_DIR) $(OBJS) $(OBJ_PSRC)
	@echo "\033[32mmaking push_swap...\033[0m"
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(OBJ_PSRC) $(INCLUDES) $(LFT) -o $(PUSH_SWAP)

$(COMPLEXITY): $(LFT) $(OBJ_DIR) $(OBJS) $(OBJ_CMSRC)
	@echo "\033[32mmaking complexity...\033[0m"
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(OBJ_CMSRC) $(INCLUDES) $(LFT) -o $(COMPLEXITY)

$(OBJ_DIR):
	@echo "Create OBJ dir"
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o: $(UTIL_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o: $(CMD_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LFT):
	@echo "\033[32mcreatiing LIB...\033[0m"
	make -C $(LFT_DIR)

clean:
	make -C $(LFT_DIR) clean
	@echo "\033[33mcleaning repository...\033[0m"
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LFT_DIR) fclean
	@echo "\033[33mremoving executables...\033[0m"
	rm -f $(CHECKER) $(PUSH_SWAP) $(COMPLEXITY)

re: fclean all
