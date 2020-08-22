CC = g++ -std=c++11

all: main.o decrypt.o encrypt.o gcd.o generate_key.o key_struct.o large_pow_modulo.o
	$(CC) main.o decrypt.o encrypt.o gcd.o generate_key.o key_struct.o large_pow_modulo.o
main.o: main.cpp key_struct.h generate_key.h encrypt.h decrypt.h
	$(CC) -c main.cpp
decrypt.o: decrypt.cpp decrypt.h key_struct.h large_pow_modulo.h
	$(CC) -c decrypt.cpp
encrypt.o: encrypt.cpp encrypt.h key_struct.h large_pow_modulo.h generate_key.h
	$(CC) -c encrypt.cpp
gcd.o: gcd.cpp gcd.h
	$(CC) -c gcd.cpp
generate_key.o: generate_key.cpp generate_key.h key_struct.h gcd.h
	$(CC) -c generate_key.cpp
key_struct.o: key_struct.cpp key_struct.h	
	$(CC) -c key_struct.cpp
large_pow_modulo.o: large_pow_modulo.cpp large_pow_modulo.h
	$(CC) -c large_pow_modulo.cpp			
clean:
	rm *.o
	rm a.out