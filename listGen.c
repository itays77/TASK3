/**************/
/*   list.c   */
/**************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "listGen.h"
#include "Airport.h"
#include "AirportManager.h"

//////////////////////////////////////////
// Init
// Aim:		create new list
// Input:	pointer to the list structure
// Output:	TRUE if succeeded
//////////////////////////////////////////
BOOL L_init(LIST* pList)
{
	if (pList == NULL) return False;	// no list to initialize

	pList->head.next = NULL;
	return True;
}


/////////////////////////////////////////////////////////////////
// Insert
// Aim:		add new node
// Input:	pointer to the node BEFORE the place for the new one
//			a value to be stored in the new node
// Output:	pointer to the new node
/////////////////////////////////////////////////////////////////
NODE* L_insert(NODE* pNode, DATA Value)
{
	NODE* tmp;

	if (!pNode) return NULL;

	tmp = (NODE*)malloc(sizeof(NODE));	// new node

	if (tmp != NULL) {
		tmp->key = Value;
		tmp->next = pNode->next;
		pNode->next = tmp;
	}
	return tmp;
}


//////////////////////////////////////////////////////////////
// Delete
// Aim:		erase node
// Input:	pointer to the node BEFORE the node to be deleted 
// Output:	TRUE if succeeded
//////////////////////////////////////////////////////////////
BOOL L_delete(NODE* pNode, void(*freekey)(void* data))
{
	NODE* tmp;

	if (!pNode || !(tmp = pNode->next)) return False;

	pNode->next = tmp->next;
	if (freekey != NULL)
		freekey(tmp->key);
	free(tmp);
	return True;
}


/////////////////////////////////////////////////////////
// Find
// Aim:		search for a value
// Input:	pointer to the node to start with 
//			a value to be found
// Output:	pointer to the node containing the Value
/////////////////////////////////////////////////////////
const NODE* L_find(const NODE* pNode, DATA Value, int(*equals)(const void* data, const void* data2)) // compare returns 0 if equals
{
	const NODE* temp = NULL;
	while (pNode != NULL)
	{
		if (equals(pNode->key, Value))
		{
			temp = pNode;
			break;
		}
		pNode = pNode->next;
	}

	return temp;


}


////////////////////////////////////////////////
// Free (additional function)
// Aim:		free the list memory
// Input:	pointer to the list structure
// Output:	TRUE if succeeded
////////////////////////////////////////////////
BOOL L_free(LIST* pList, void(*freekey)(void* data))
{
	NODE* tmp;

	if (!pList) return False;


	for (tmp = &(pList->head); L_delete(tmp, freekey););
	return True;
}


////////////////////////////////////////////////
// Print (additional function)
// Aim:		print the list content (assume the DATA is int)
// Input:	pointer to the list structure
// Output:	a number of the printed elements
////////////////////////////////////////////////
int L_print(const LIST* pList, void(*printData)(const void* data))
{
	NODE* tmp;
	int		c = 0;

	if (!pList) return 0;

	printf("\n");
	for (tmp = pList->head.next; tmp; tmp = tmp->next, c++)
		printData(tmp->key);
	printf("\n");
	return c;
}









////////////////////////////////////////////////
// length (additional function)
// Aim:		return the list length (assume the DATA is int)
// Input:	pointer to the list structure
// Output:	the length of the list 
////////////////////////////////////////////////
// Function to calculate the length of the linked list
int L_length(const LIST* pList) {
	if (!pList || !pList->head.next)
		return 0;

	int length = 0;
	const NODE* current = &(pList->head);

	while (current != NULL) {
		length++;
		current = current->next;
	}

	return length;// -1 ?
}






/////////////////////////////////////////////////////////////////
// Insert in order of the the airport code 
// Aim:		add new node in order
// Input:	pointer to the list
//			a port to be stored in the list
// Output:	pointer to the added node
/////////////////////////////////////////////////////////////////
void L_insertInCodeOrder(LIST* pList, Airport* pPort)
{
	
	NODE* tmp = &pList->head;

	while (tmp->next != NULL)
	{
		if (strcmp(pPort->code, ((Airport*)(tmp->next->key))->code) < 0) // strcmp insted of compare becuase code is lexicograf 
			break; 
		tmp = tmp->next;
	}

	L_insert(tmp, pPort);

}


