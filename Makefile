##
## Makefile for Makefile in /home/paglia_f//WorkOffline/printf
##
## Made by floran pagliai
## Login   <paglia_f@epitech.net>
##
## Started on  Mon Nov 14 10:39:32 2011 floran pagliai
## Last update Thu Feb 16 15:44:03 2012 floran pagliai
##

NAME= 	Abstract_VM

SRC=	src/main.cpp

OBJ=	$(SRC:.cpp=.o)

CC=	clang

FLAG=	-g -Wall

all:	$(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ)
	make clean
	clean

clean:
	rm -f $(OBJ)
	rm -rf *~
	rm -rf *#


fclean:	clean
	rm -f $(NAME)

re: fclean all