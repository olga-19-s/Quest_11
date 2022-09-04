FLAGS = -Wall -Werror -Wextra

all: door_struct list_test stack_test

door_struct:
	gcc $(FLAGS) -o ../build/Quest_1 dmanager_module.c

list_test:
	gcc $(FLAGS) -o ../build/Quest_2 list_test.c list.c

stack_test:
	gcc $(FLAGS) -o ../build/Quest_3 stack_test.c stack.c

clean:
	rm -rf ../build/*

rebuild: clean all