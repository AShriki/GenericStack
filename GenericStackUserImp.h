#ifndef _GENSTACKUSR_
#define _GENSTACKUSR_

/* - - - USER DEFINED FIELDS - - - */

// only applicable to static stack

#define BULKSTACKSIZE0 8
#define BULKSTACKSIZE1 16
#define BULKSTACKSIZE2 32
#define BULKSTACKSIZE3 64
#define BULKSTACKSIZE4 128
#define BULKSTACKSIZE5 256

// If using static stack, then this must be implemented
typedef struct StackNode {
	int a;
	struct StackNode* next;
}StackNode;

/* - - - END USER DEFINED FIELDS - - - */

#endif // !_GENSTACKUSR_
