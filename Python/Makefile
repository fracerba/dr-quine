COLLEEN = Colleen.py
GRACE = Grace.py
SULLY = Sully.py

CC = python3

Colleen: $(COLLEEN)
	$(CC) $(COLLEEN)

Grace: $(GRACE)
	$(CC) $(GRACE)

Sully: $(SULLY)
	$(CC) $(SULLY)

all: Colleen Grace Sully

clean:
	rm -f Grace_kid.* Sully_*

re: clean all

.PHONY: all clean re