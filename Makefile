CC = g++

all: NIM.exe

%.exe: %.o
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -c $<

clean:
	rm -f *.o

