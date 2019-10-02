CC=gcc 
FLAGS=-ggdb -O0 -m64

release:
	mkdir -p ./bin/
	$(CC) $(FLAGS) ./src/main.c -o ./bin/dungeons_and_hackers-lvl-1

clean:
	rm ./bin/dungeons_and_hackers-lvl-1
