# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Bonus.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 15:36:27 by mbouthai          #+#    #+#              #
#    Updated: 2022/09/02 19:49:07 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= checker

BOLD	:=\033[1m

RESET	:=\033[0m

RED	:=\033[91m

GREEN	:=\033[92m

CYAN	:=\033[96m

INC_DIR	:= inc_bonus/ 

EXTERN	:= -Ilibft/ -Ift_printf/ -Iget_next_line/

SRC_DIR	:= src_bonus/

OBJ_DIR	:= obj_bonus/

DEP_DIR	:= dep_bonus/

RM	:= rm -f

RMDIR	:= rm -rf

CC	:= gcc

CFLAGS	:= -Wall -Werror -Wextra -g -I$(INC_DIR) $(EXTERN)

LFLAGS	:= -L./libft -L./ft_printf -lft -lftprintf

INC_FS	:= push_swap_bonus.h

SRC_FS	:= ft_fill_bonus.c push_swap_utils_bonus.c ft_stack_bonus.c ft_stack_operations_bonus.c ft_stack_utils_bonus.c \
	ft_stack_sort_bonus.c ft_stack_mutate_bonus.c ft_moves_bonus.c ft_best_moves_bonus.c ft_lis_bonus.c checker_bonus.c

INCS	= $(addprefix $(INC_DIR), $(INC_FS))

SRCS	= $(addprefix $(SRC_DIR), $(SRC_FS))

OBJS	= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:%=%.o)))

DEPS	= $(addprefix $(DEP_DIR), $(notdir $(SRCS:%=%.d)))

LIBFT	:= libft.a

PRINTF	:= libftprintf.a

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@echo "\n$(CYAN)BUILDING LIBFT$(RESET)\n"
	@make bonus -C libft

$(PRINTF):
	@echo "\n$(CYAN)BUILDING FT_PRINTF$(RESET)\n"
	@make -C ft_printf

$(NAME): $(OBJS)
	@echo "\n$(GREEN)BUILDING BONUS PROJECT$(RESET)\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR):
	@echo "\n$(BOLD)CREATING BONUS OBJ DIRECTORY$(RESET)\n"
	@mkdir -p $@

$(DEP_DIR):
	@echo "\n$(BOLD)CREATING BONUS DEP DIRECTORY$(RESET)\n"
	@mkdir -p $@

$(OBJS): | $(OBJ_DIR)

$(OBJS): | $(DEP_DIR)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%
	$(CC) $(CFLAGS) -MMD -MF $(addprefix $(DEP_DIR), $(notdir $(<:%=%.d))) -c $< -o $@

cleanobj:
	@echo "\n$(RED)CLEANING BONUS OBJECT FILES$(RESET)\n"
	-$(RM) $(wildcard $(OBJS))

cleanobjdir: cleanobj
	-$(RMDIR) $(OBJ_DIR)

cleandep:
	@echo "\n$(RED)CLEANING BONUS DEPENDENCIES$(RESET)\n"
	-$(RM) $(wildcard $(DEPS))

cleandepdir: cleandep
	-$(RMDIR) $(DEP_DIR)

clean: cleanobjdir cleandepdir
	@echo "\n$(RED)CLEANING BONUS$(RESET)\n"

fclean: clean
	-$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all bonus cleanobj cleanobjdir cleandep cleandepdir clean fclean
