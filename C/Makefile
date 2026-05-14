COLLEEN_SRC = Colleen.c
GRACE_SRC = Grace.c
SULLY_SRC = Sully.c

COLLEEN_EXE = Colleen
GRACE_EXE = Grace
SULLY_EXE = Sully

CC = clang
FLAGS = -Wall -Wextra -Werror

$(COLLEEN_EXE): $(COLLEEN_SRC)
	$(CC) $(FLAGS) -o $(COLLEEN_EXE) $(COLLEEN_SRC)

$(GRACE_EXE): $(GRACE_SRC)
	$(CC) $(FLAGS) -o $(GRACE_EXE) $(GRACE_SRC)

$(SULLY_EXE): $(SULLY_SRC)
	$(CC) $(FLAGS) -o $(SULLY_EXE) $(SULLY_SRC)

all: $(COLLEEN_EXE) $(GRACE_EXE) $(SULLY_EXE)

clean:
	rm -f *.o Grace_kid.* Sully_*

fclean: clean
	rm -f $(COLLEEN_EXE) $(GRACE_EXE) $(SULLY_EXE)

re: fclean all

.PHONY: all clean fclean re