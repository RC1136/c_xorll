#include <stdio.h>
#include <stdlib.h>
#include "xorll.h"


int main()
{
	XorLL* example = malloc(sizeof(XorLL));
	if (example == NULL) return 0;
	XorLL* begin = example;
	*example = (XorLL){ 0, 0 };
	/*
	push(&example, 1);
	push(&example, 2);
	push(&example, 3);
	printf("%d\n", pop(&example));
	printf("%d\n", example->data);

	printf("%d\n", pop(&example));
	*/
	
	
	
	for (int i = 1; i < 10; i++) {
		push(&example, i);
		printf("%d\n", example->data);
	}

	printf("\n%d\n", getel(begin, 5)->data);

	insert(&begin, 420, 5);
	
	//insert(example, ~0, 0);

	

	printf("\n%d\n", getel(begin, 5)->data);

	
	for (int i = 0; i < 10; i++) {
		printf("%d\n", pop(&example));
	}
	




	while (getchar() != '\n');
	return 0;
}