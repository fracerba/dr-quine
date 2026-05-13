COLLEEN_SRC = Colleen.cpp
GRACE_SRC = Grace.cpp
SULLY_SRC = Sully.cpp

COLLEEN_EXE = Colleen
GRACE_EXE = Grace
SULLY_EXE = Sully

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++17

colleen: $(COLLEEN_SRC)
	$(CC) $(FLAGS) -o $(COLLEEN_EXE) $(COLLEEN_SRC)

grace: $(GRACE_SRC)
	$(CC) $(FLAGS) -o $(GRACE_EXE) $(GRACE_SRC)

sully: $(SULLY_SRC)
	$(CC) $(FLAGS) -o $(SULLY_EXE) $(SULLY_SRC)

all: colleen grace sully

clean:
	rm -f *.o Grace_kid.* Sully_*

fclean: clean
	rm -f $(COLLEEN_EXE) $(GRACE_EXE) $(SULLY_EXE)

re: fclean all

.PHONY: all clean fclean re