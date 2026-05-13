COLLEEN_SRC = Colleen.s
GRACE_SRC = Grace.s
SULLY_SRC = Sully.s

COLLEEN_OBJ = Colleen.o
GRACE_OBJ = Grace.o
SULLY_OBJ = Sully.o

COLLEEN_EXE = Colleen
GRACE_EXE = Grace
SULLY_EXE = Sully

CC = nasm
GCC = gcc
FLAGS = -f elf64

colleen: $(COLLEEN_SRC)
	$(CC) $(FLAGS) $(COLLEEN_SRC) -o $(COLLEEN_OBJ) && $(GCC) $(COLLEEN_OBJ) -o $(COLLEEN_EXE)

grace: $(GRACE_SRC)
	$(CC) $(FLAGS) -o $(GRACE_OBJ) $(GRACE_SRC) && $(GCC) $(GRACE_OBJ) -o $(GRACE_EXE)

sully: $(SULLY_SRC)
	$(CC) $(FLAGS) -o $(SULLY_OBJ) $(SULLY_SRC) && $(GCC) $(SULLY_OBJ) -o $(SULLY_EXE)

all: colleen grace sully

clean:
	rm -f *.o Grace_kid.* Sully_*

fclean: clean
	rm -f $(COLLEEN_EXE) $(GRACE_EXE) $(SULLY_EXE)

re: fclean all

.PHONY: all clean fclean re