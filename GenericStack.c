#include "GenericStack.h"

#include <stdlib.h>
/*
	Created by Avshalom Shriki
	E-mail: Av.shriki@gmail.com

	This file implements a stack
	
	See the .h file on how to use this project.
*/

/*
	@description		: Generates the bulk memory from which which we "allocate" pointers to smaller stacks for statically allocated stacks.
						  As a note, this method can only be called once, all subsequent calls will be ignored

	@var bulkstacksize   : A number choosing from the number of elements displayed by #define BULKSTACKSIZE(0-5) in GenericStackUsrImp.h 
	@return				: A pointer to the first free space in array if allocation was successful and NULL if not
*/
struct BulkStack* getBulkStack(int bulkstacksize) {
	static struct BulkStack bulkStack = { .spaceHolder = 0,.bulkSet = 0 };
	 
	if (!bulkStack.bulkSet) {
		switch (bulkstacksize) {
			case 0: {	
				int i;
				static StackNode bulkSpace[BULKSTACKSIZE0];
				for (i = 0; i < BULKSTACKSIZE0; i++)
					bulkSpace[i].next = NULL;
				bulkStack.bulk = &bulkSpace;
				bulkStack.maxNodes = BULKSTACKSIZE0;
				bulkStack.spaceHolder = 0;
				break; 
			}
			case 1: {
				int i;
				static StackNode bulkSpace[BULKSTACKSIZE1];
				for (i = 0; i < BULKSTACKSIZE1; i++)
					bulkSpace[i].next = NULL;
				bulkStack.bulk = &bulkSpace;
				bulkStack.maxNodes = BULKSTACKSIZE1;
				bulkStack.spaceHolder = 0;
				break;
			}
			case 2: {
				int i;
				static StackNode bulkSpace[BULKSTACKSIZE2];
				for (i = 0; i < BULKSTACKSIZE2; i++)
					bulkSpace[i].next = NULL;
				bulkStack.bulk = &bulkSpace;
				bulkStack.maxNodes = BULKSTACKSIZE2;
				bulkStack.spaceHolder = 0;
				break;
			}
			case 3: {
				int i;
				static StackNode bulkSpace[BULKSTACKSIZE3];
				for (i = 0; i < BULKSTACKSIZE3; i++)
					bulkSpace[i].next = NULL;
				bulkStack.bulk = &bulkSpace;
				bulkStack.maxNodes = BULKSTACKSIZE3;
				bulkStack.spaceHolder = 0;
				break;
			}
			case 4: {
				int i;
				static StackNode bulkSpace[BULKSTACKSIZE4];
				for (i = 0; i < BULKSTACKSIZE4; i++)
					bulkSpace[i].next = NULL;
				bulkStack.bulk = &bulkSpace;
				bulkStack.maxNodes = BULKSTACKSIZE4;
				bulkStack.spaceHolder = 0;
				break;
			}
			case 5: {
				int i;
				static StackNode bulkSpace[BULKSTACKSIZE5];
				for (i = 0; i < BULKSTACKSIZE5; i++)
					bulkSpace[i].next = NULL;
				bulkStack.bulk = &bulkSpace;
				bulkStack.maxNodes = BULKSTACKSIZE5;
				bulkStack.spaceHolder = 0;
				break;
			}
			default: {
				int i;
				static StackNode bulkSpace[BULKSTACKSIZE5];
				for (i = 0; i < BULKSTACKSIZE5; i++)
					bulkSpace[i].next = NULL;
				bulkStack.bulk = &bulkSpace;
				bulkStack.maxNodes = BULKSTACKSIZE5;
				bulkStack.spaceHolder = 0;
				break;
			}
		}
		bulkStack.bulkSet = 1;
		return &bulkStack;
	}
	else {
		bulkStack.spaceHolder = 0;
		return &bulkStack;
	}
	return NULL;
}

/*
	@description : Generates the stack using a statically declared array. Must be called before using a static stack

	@var h       : a pointer to an unallocated, uninitialized stack
	@var b		 : The BulkStack to use for array elements
	@var n       : For static stack, n is the number of elements to "allocate" to this stack
	@return      : 1 if allocation was successful, 0 if not
*/

int initializeStack(struct Stack* s, struct BulkStack* b, StackType t, StackMemoryType m ,int n) {
	
	if (n < 1 && n != -1)
		return 0;

	if (m == Static_Stack) {
		if (b->maxNodes < b->spaceHolder + n || !b->bulkSet)
			return 0;

		s->top = &b->bulk[b->spaceHolder];
		s->bottom = NULL;
		b->spaceHolder += n;

		s->staticHead = 0;
		s->staticTail = 0;
	}
	
	s->maxNodes = n;
	s->numItems = 0;
	s->type = t;
	s->memtype = m;

	return 1;
}

/*
	@description : Returns the top node

	@var s       : a pointer to a stack
	@return      : top or NULL if there are no items in the stack
*/

const StackNode* peekStack(struct Stack s) {
	if(!&s || !s.top || !s.numItems)
		return NULL;

	if (s.memtype) {
		//dynamic
		return s.top;
	}
	else {
		//static
		return &s.top[s.staticHead];
	}
}
/*
	@description : adds a Node to the stack

	@var s       : a pointer to a stack
	@var n       : node to be inserted
	@return      : 0 on failure to add or allocate memory 1 on success
*/
int pushStack(struct Stack* s, StackNode n) {
	// -1 idicates unlimited stack size
	if (s->maxNodes != -1 && s->numItems == s->maxNodes)
		return 0;
	if (s->memtype) {
	// dynamic stack
		if (!s->numItems) {
			s->top = (StackNode*)malloc(sizeof(StackNode));
			if (s->top == NULL)
				return 0;
			*s->top = n;
			s->bottom = s->top;
		}
		else {
			if (s->type) {
				//LIFO
				StackNode* tmp = (StackNode*)malloc(sizeof(StackNode));
				if (tmp == NULL)
					return 0;
				*tmp = n;
				tmp->next = s->top;
				s->top = tmp;
			}
			else {
				//FIFO
				s->bottom->next = (StackNode*)malloc(sizeof(StackNode));
				if (s->bottom->next == NULL)
					return 0;
				*s->bottom->next = n;
				s->bottom = s->bottom->next;
			}

		}
	}
	else {
	// static stack
	// s->*top holds the reference to the start of the array
		if (s->type) {
			//LIFO
			s->top[(++s->staticHead)] = n;
		}
		else {
			// FIFO
			if (s->staticTail == s->maxNodes - 1){
				int i;
				// once in a while re-allign the head of the fifo stack to the front of the array
				for (i = s->staticHead; i < s->numItems + s->staticHead; i++) {
					s->top[i - s->staticHead] = s->top[i];
				}
			}
			s->top[(s->staticTail)++] = n;
		}
	}
	s->numItems++;
	return 1;
}
/*
	@description : Removes the highest/lowest element of the stack

	@var h       : a pointer to a stack
	@return      : the pointer to the last retured node or NULL if stack is empty
*/
const StackNode* popStack(struct Stack* s) {
	if (!s->numItems || s->numItems <= 0) {
		return NULL;
	}
	static StackNode lastPopped = {.next = NULL};
	if (s->memtype) {
		// dynamic stack
		StackNode* tmp = s->top;
		lastPopped = *s->top;
		s->top = s->top->next;
		free(tmp);

	}
	else {
		// static stack
		lastPopped = s->top[s->staticHead];

		if (s->type) {
			//LIFO
			s->staticHead--;
		}
		else {
			//FIFO
			s->staticHead++;
		}
	}
	s->numItems--;
	return &lastPopped;
}
