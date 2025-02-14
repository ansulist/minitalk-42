CLIENT = client.c
SERVER = server.c
CLIENT_NAME = client
SERVER_NAME = server

CLIENT_B = client_bonus.c
SERVER_B = server_bonus.c
CLIENT_NAME_B = client_bonus
SERVER_NAME_B = server_bonus

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all:  $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_NAME_B) $(SERVER_NAME_B)

$(SERVER_NAME) : $(SERVER)
	$(CC) $(FLAGS) utils.c $(SERVER) -o $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT)
	$(CC) $(FLAGS) utils.c $(CLIENT) -o $(CLIENT_NAME)

$(SERVER_NAME_B) : $(SERVER_B)
	$(CC) $(FLAGS) utils.c $(SERVER_B) -o $(SERVER_NAME_B)

$(CLIENT_NAME_B) : $(CLIENT_B)
	$(CC) $(FLAGS) utils.c $(CLIENT_B) -o $(CLIENT_NAME_B)

clean:
	$(RM) server.o client.o
	$(RM) server_bonus.o client_bonus.o

fclean: clean
	$(RM) server client
	$(RM) server_bonus client_bonus
	
re: fclean all

.PHONY:	all clean fclean re