#ifndef _GENSTACK_
#define _GENSTACK_

#include "GenericStackUserImp.h"

/*
Library Usage:
1. Implement/modify the methods and fields in the - USER DEFINED FIELDS - section
2. For static stacks, create a BulkStack via getBulkStack(int) followed by a call to initializeStaticStack
3. Multiple static stacks are permitted as long as bulkStack has the space for them
4. For a dynamic stack just create the stack struct followed by a call to initializeDynamicStack

This code is not optimized
*/

typedef enum { FIFO = 0u, LIFO = 1u } StackType;
typedef enum { Static_Stack = 0u, Dynamic_Stack = 1u } StackMemoryType;

typedef struct Stack {
	StackNode* top;
	StackNode* bottom;
	int staticHead;
	int staticTail;
	int numItems;
	int maxNodes;
	StackType type;
	StackMemoryType memtype;
}Stack;

// only used for static stack memory
typedef struct BulkStack {
	StackNode* bulk;
	int spaceHolder;
	int maxNodes;
	unsigned int bulkSet;
}BulkStack;

BulkStack* getBulkStack( int );
int initializeStack( Stack* , BulkStack* , StackType , StackMemoryType , int );

const StackNode* peekStack( Stack );
int pushStack( Stack*, StackNode );
const StackNode* popStack( Stack* );

#endif
