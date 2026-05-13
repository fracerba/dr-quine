COLLEEN = Colleen.py
GRACE = Grace.py
SULLY = Sully.py

CC = python3

colleen: $(COLLEEN)
	$(CC) $(COLLEEN)

grace: $(GRACE)
	$(CC) $(GRACE)

sully: $(SULLY)
	$(CC) $(SULLY)

all: colleen grace sully

clean:
	rm -f Grace_kid.* Sully_*

re: clean all

.PHONY: all clean re