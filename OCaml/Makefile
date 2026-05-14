COLLEEN_SRC = Colleen.ml
GRACE_SRC = Grace.ml
SULLY_SRC = Sully.ml

COLLEEN_EXE = Colleen
GRACE_EXE = Grace
SULLY_EXE = Sully

CC = ocamlopt

$(COLLEEN_EXE): $(COLLEEN_SRC)
	$(CC) -o $(COLLEEN_EXE) $(COLLEEN_SRC)

$(GRACE_EXE): $(GRACE_SRC)
	$(CC) -o $(GRACE_EXE) $(GRACE_SRC)

$(SULLY_EXE): $(SULLY_SRC)
	$(CC) -o $(SULLY_EXE) $(SULLY_SRC)

all: $(COLLEEN_EXE) $(GRACE_EXE) $(SULLY_EXE)

clean:
	rm -f *.cm* *.o Grace_kid.* Sully_*

fclean: clean
	rm -f $(COLLEEN_EXE) $(GRACE_EXE) $(SULLY_EXE)

re: fclean all

.PHONY: all clean fclean re