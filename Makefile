CC = gcc
FLAGS = -g
LINKS = -lhttp -lhash-table -lssl -lcrypto -lm

server: server.c
	$(CC) $(FLAGS) -o $@ $^ $(LINKS)
