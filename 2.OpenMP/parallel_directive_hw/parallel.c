#include <stdlib.h>     /* Standard Library: EXIT_SUCCESS */
#include <stdio.h>      /* Standard I/O Library: printf */

void add();

int main(void){

    add();

    return EXIT_SUCCESS;
};

void add(){
	int x = 50;
	int y = 60;
	int sum = x + y;
	printf("Result %d + %d = %d\n",x,y,sum);
}