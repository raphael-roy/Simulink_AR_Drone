CC = C:\Sourcery_CodeBench\bin\arm-none-linux-gnueabi-g++
CFLAGS = -march=armv7-a
CXXFLAGS = -W -Wall
LDFLAGS =
EXEC = clean toto.elf

SRCS = toto.cpp led.cpp Actuators.cpp GPIO.cpp
OBJS = toto.o led.o Actuators.o GPIO.o

all : $(EXEC)
	
toto.elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o toto.elf

toto.o: toto.cpp
	$(CC) -o toto.o -c toto.cpp $(CXXFLAGS)

led.o: led.cpp
	$(CC) -o led.o -c led.cpp $(CXXFLAGS)

Actuators.o: Actuators.cpp
	$(CC) -o Actuators.o -c Actuators.cpp $(CXXFLAGS)

GPIO.o: GPIO.cpp
	$(CC) -o GPIO.o -c GPIO.cpp $(CXXFLAGS)

clean:
	rm -rf *.o
	rm -rf ~.o
	rm -rf *.elf
	rm -rf ~.elf