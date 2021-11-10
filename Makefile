LIBFT = ./libft/libft.a
NAME = client

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

ifndef MAKEBONUS
SRC_CLIENT_FINAL = client.c
SRC_SERVER_FINAL = server.c
OBJ_CLIENT_FINAL = client.o
OBJ_SERVER_FINAL = server.o
else
SRC_CLIENT_FINAL = client_bonus.c
SRC_SERVER_FINAL = server_bonus.c
OBJ_CLIENT_FINAL = client_bonus.o
OBJ_SERVER_FINAL = server_bonus.o
endif

$(NAME): $(OBJ_CLIENT_FINAL) $(OBJ_SERVER_FINAL)
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(OBJ_CLIENT_FINAL) ${LIBFT} -o client
	$(CC) $(FLAGS) $(OBJ_SERVER_FINAL) ${LIBFT} -o server

all : $(NAME)

bonus : 
	$(MAKE) MAKEBONUS=1

clean :
	$(MAKE) clean -C ./libft
	rm -rf client_bonus.o server_bonus.o client.o server.o
	@printf "\e[38;5;206m.o files deleted🚽\e[0m\n"

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf client server
	@printf "\e[38;5;200mBinaries deleted🗑\e[0m\n"

re : fclean all