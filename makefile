CC=g++
OPTIONS= -std=c++11

main:	caesar_pk.cpp    
	$(CC) $(OPTIONS) caesar_pk.cpp -o caesar_pk

clean:
	rm caesar_pk
