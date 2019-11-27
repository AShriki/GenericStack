#include <stdio.h>
#include "GenericStack.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char** argv) {

	srand((unsigned int)time(NULL));

	// test static stack

	int i;


	printf("test 1: over fill random static stack LIFO - - - - - - - \n");
	BulkStack* b = getBulkStack(4);
	Stack ss[5];

	if (!initializeStack(&ss[0], b, LIFO, Static_Stack, 13)) { printf("Stack 0 failed to initialize"); }
	if (!initializeStack(&ss[1], b, LIFO, Static_Stack, 28)){ printf("Stack 1 failed to initialize"); }
	if (!initializeStack(&ss[2], b, LIFO, Static_Stack, 6)){ printf("Stack 2 failed to initialize"); }
	if (!initializeStack(&ss[3], b, LIFO, Static_Stack, 19)){ printf("Stack 3 failed to initialize"); }
	if (!initializeStack(&ss[4], b, LIFO, Static_Stack, 1)){ printf("Stack 4 failed to initialize"); }
	
	int r;
	for (r = 0; r < 5; r++) {
		printf("\nStack ss%d in: ", r);
		for (i = 0; i < 40; i++) {

			StackNode tmp = { rand() % 666 , NULL };
			if (!pushStack(&ss[r], tmp)) {
				printf("\nStack Max elements reached");
				break;
			}
			else {
				printf("%d ",tmp.a);
			}
		}
		printf("\n");
	}
	
	
	printf("test 2: pop static LIFO stack - - - - - - - \n");
	StackNode* tmp;
	for (r = 0; r < 5; r++) {
		printf("\nStack ss%d out: ", r);
		for (i = 0; i < 40; i++) {
			if (!peekStack(ss[r])) {
				printf("\nEnd of stack reached");
				break;
			}
			else {
				printf("%d ", peekStack(ss[r])->a);
			}
			popStack(&ss[r]);
		}
		printf("\n");
	}


	printf("test 3: over fill random static stack FIFO - - - - - - - \n");
	BulkStack* b1 = getBulkStack(3);
	Stack ss1[5];

	if (!initializeStack(&ss1[0], b, FIFO, Static_Stack, 13)) { printf("Stack 0 failed to initialize"); }
	if (!initializeStack(&ss1[1], b, FIFO, Static_Stack, 5)) { printf("Stack 1 failed to initialize"); }
	if (!initializeStack(&ss1[2], b, FIFO, Static_Stack, 10)) { printf("Stack 2 failed to initialize"); }
	if (!initializeStack(&ss1[3], b, FIFO, Static_Stack, 19)) { printf("Stack 3 failed to initialize"); }
	if (!initializeStack(&ss1[4], b, FIFO, Static_Stack, 1)) { printf("Stack 4 failed to initialize"); }

	for (r = 0; r < 5; r++) {
		printf("Stack ss1%d in: ", r);
		for (i = 0; i < 40; i++) {

			StackNode tmp = { rand() % 666 , NULL };
			if (!pushStack(&ss1[r], tmp)) {
				printf("\nStack Max elements reached");
				break;
			}
			else {
				printf("%d ", tmp.a);
			}
		}
		printf("\n");
	}


	printf("test 4: pop static FIFO stack - - - - - - - \n");
	for (r = 0; r < 5; r++) {
		printf("Stack ss1%d out: ", r);
		for (i = 0; i < 40; i++) {
			if (!peekStack(ss1[r])) {
				printf("\nEnd of stack reached");
				break;
			}
			else {
				printf("%d ", peekStack(ss1[r])->a);
			}
			popStack(&ss1[r]);
		}
		printf("\n");
	}


	printf("test 5: over fill random Dynamic Stack LIFO - - - - - - - \n");
	Stack ss2[5];

	if (!initializeStack(&ss2[0], NULL, LIFO, Dynamic_Stack, 13)) { printf("Stack 0 failed to initialize"); }
	if (!initializeStack(&ss2[1], NULL, LIFO, Dynamic_Stack, 5)) { printf("Stack 1 failed to initialize"); }
	if (!initializeStack(&ss2[2], NULL, LIFO, Dynamic_Stack, 10)) { printf("Stack 2 failed to initialize"); }
	if (!initializeStack(&ss2[3], NULL, LIFO, Dynamic_Stack, 19)) { printf("Stack 3 failed to initialize"); }
	if (!initializeStack(&ss2[4], NULL, LIFO, Dynamic_Stack, 1)) { printf("Stack 4 failed to initialize"); }

	for (r = 0; r < 5; r++) {
		printf("Stack ss2%d in: ", r);
		for (i = 0; i < 40; i++) {

			StackNode tmp = { rand() % 666 , NULL };
			if (!pushStack(&ss2[r], tmp)) {
				printf("\nStack Max elements reached");
				break;
			}
			else {
				printf("%d ", tmp.a);
			}
		}
		printf("\n");
	}


	printf("test 6: pop static LIFO stack - - - - - - - \n");
	for (r = 0; r < 5; r++) {
		printf("Stack ss2%d out: ", r);
		for (i = 0; i < 40; i++) {
			if (!peekStack(ss2[r])) {
				printf("\nEnd of stack reached");
				break;
			}
			else {
				printf("%d ", peekStack(ss2[r])->a);
			}
			popStack(&ss2[r]);
		}
		printf("\n");
	}


	printf("test 7: over fill random Dynamic Stack FIFO - - - - - - - \n");
	Stack ss3[5];

	if (!initializeStack(&ss3[0], NULL, FIFO, Dynamic_Stack, 13)) { printf("Stack 0 failed to initialize"); }
	if (!initializeStack(&ss3[1], NULL, FIFO, Dynamic_Stack, 5)) { printf("Stack 1 failed to initialize"); }
	if (!initializeStack(&ss3[2], NULL, FIFO, Dynamic_Stack, 10)) { printf("Stack 2 failed to initialize"); }
	if (!initializeStack(&ss3[3], NULL, FIFO, Dynamic_Stack, 19)) { printf("Stack 3 failed to initialize"); }
	if (!initializeStack(&ss3[4], NULL, FIFO, Dynamic_Stack, 1)) { printf("Stack 4 failed to initialize"); }

	for (r = 0; r < 5; r++) {
		printf("Stack ss3%d in: ", r);
		for (i = 0; i < 40; i++) {

			StackNode tmp = { rand() % 666 , NULL };
			if (!pushStack(&ss3[r], tmp)) {
				printf("\nStack Max elements reached");
				break;
			}
			else {
				printf("%d ", tmp.a);
			}
		}
		printf("\n");
	}


	printf("test 8: pop static FIFO stack - - - - - - - \n");
	for (r = 0; r < 5; r++) {
		printf("Stack ss3%d out: ", r);
		for (i = 0; i < 40; i++) {
			if (!peekStack(ss3[r])) {
				printf("\nEnd of stack reached");
				break;
			}
			else {
				printf("%d ", peekStack(ss3[r])->a);
			}
			popStack(&ss3[r]);
		}
		printf("\n");
	}
}