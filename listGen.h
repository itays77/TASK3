
/********************************************/
/*   list.h                                 */
/*   a dynamic  linked list with a header   */
/********************************************/


#ifndef _LIST_
#define _LIST_

#include "def.h"
#include "Airport.h"

/*** Definitions ***/

// Node
typedef struct node
{
	DATA			key;
	struct node*    next;
}NODE;



// List
typedef struct
{
	NODE head;
}LIST;


/*** Function prototypes ***/

BOOL L_init(LIST* pList);					// create new list

NODE* L_insert(NODE* pNode, DATA Value);	// add new node after *pNode

BOOL L_delete(NODE* pNode, void(*delete)(void* data));					// erase node after *pNode

const NODE* L_find(const NODE* pNode, DATA Value, int(*compare)(const void* data, const void* data2));		// return a pointer to the node

BOOL L_free(LIST* pList, void(*freekey)(void* data));					// free list memory

int L_print(const LIST* pList, void(*printData)(const void* data));					// print the list content

int L_length(const LIST* pList);       //return list length

void L_insertInCodeOrder(LIST* pList, Airport* pPort);     // insert airport in order of code

#endif

