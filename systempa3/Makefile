all: bankingServer bankingClient

bankingServer: bankingServer.c
	gcc -o -Wall -Werror -fsanitize=address -o bankingServer bankingServer.c

bankingClient: bankingClient.c
	gcc -o -Wall -Werror -fsanitize=address -o bankingClient bankingClient.c

clean:
	rm -f bankingServer

clean:
	rm -f bankingClient
