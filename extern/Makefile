CC = gcc
CFLAGS = -Wextra -Wall

all : main1 main2

main1 : main1.c shared.c
	$(CC) $(CFLAGS) -o main1 main1.c shared.c

	
main2 : main2.c shared.c
	$(CC) $(CFLAGS) -o main2 main2.c shared.c

clean :
	rm -rf main1 main2