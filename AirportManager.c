#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AirportManager.h"
#include "General.h"
#include "Airline.h"
#include "listGen.h"


//int initManagerAndAirline(AirportManager* pManager, Airline* pCompany, FILE* fileName)
//{
//
//	if (!initManager(pManager, fileName))
//		return 0;
//
//	if (!initAirlineFromFile)
//	{
//		printf("init airline from user\n");
//		initAirline(pCompany);
//		return 1;
//
//	}
//
//	else return 0;
//
//}










int	addAirport(AirportManager* pManager)
{
	Airport* pPort  = initAirport(pManager); //free in func that calls addAirport(main)
	if (!pPort)
		return 0;


	// if worked insert to list in order//
	L_insertInCodeOrder(&pManager->airportList, pPort);
	return 1;


	/*if (!initAirport(pPort, pManager))
	{
		freeAirport(pPort);
		free(pPort);
		return 0;
	}

	pManager->airportsArray = (Airport**)realloc(pManager->airportsArray,(pManager->airportsCount + 1) * sizeof(Airport*));

	if (!pManager->airportsArray)
	{
		freeAirport(pPort);
		free(pPort);
		return 0;
	}
	
	
	pManager->airportsArray[pManager->airportsCount] = pPort;
	pManager->airportsCount++;
	return 1;*/
}





Airport*  initAirport( AirportManager* pManager)//return pointer to pPort
{
	Airport* pPort = (Airport*)calloc(1, sizeof(Airport));
	if (!pPort)
		return NULL;

	while (1)
	{
		getAirportCode(pPort->code);
		if (checkUniqeCode(pPort->code, pManager))
			break;

		printf("This code already in use - enter a different code\n");
	}

	initAirportNoCode(pPort);
	return pPort;
}






//int compareAirport(const void* pData1, const void* pData2)
//{
//	const Airport* pPort1 = (const Airport*)pData1;
//	const Airport* pPort2 = (const Airport*)pData2;
//
//	if (!pPort1 || !pPort2)
//		return 0;
//
//	return strcmp(pPort1->code, pPort2->code) == 0;
//}

int	compareAirport(const void* data1, const void* data2) //if code is uniqe return 0 
{
	const Airport* pPort1 = (const Airport*)data1;
	const Airport* pPort2 = (const Airport*)data2;

	//return strcmp(pPort1->code, pPort2->code);
	//return strcmp(pPort1->code, pPort2->code) == 0 ? 0 : 1;

	if (!strcmp(pPort1->code, pPort2->code))
		return 1;
	return 0;

}





Airport* findAirportByCode(const AirportManager* pManager, const char* code)
{
	
	Airport temp = { 0 };
	strcpy(temp.code, code);

	
	const NODE* portNode;
	portNode = L_find(pManager->airportList.head.next, &temp, compareAirport );// isSameAirport

	if (portNode != NULL)
		return portNode->key;

	return NULL;//dosent exist


}





int checkUniqeCode(const char* code,const AirportManager* pManager)//flip returns? 
{
	Airport* port = findAirportByCode(pManager, code);

	if (port != NULL)
		return 0;

	return 1;
}







void	printAirports(const AirportManager* pManager)
{
	
	printf("there are %d airports\n", L_length(&(pManager->airportList))-1);

	L_print(&(pManager->airportList), printAirport);

	printf("\n");
	
}







//NOT NEEDED
// 
//void	freeAirportArr(AirportManager* pManager)
//
//{
//	L_free(pManager,freeAirport);
//
//	/*for (int i = 0; i < pManager->airportsCount; i++)
//	{
//		freeAirport(pManager->airportsArray[i]);
//		free(pManager->airportsArray[i]);
//	}
//	free(pManager->airportsArray);*/
//
//
//}





void	freeManager(AirportManager* pManager)//change to free list
{

	L_free(&pManager->airportList, freeAirport);//free key
}







/////////////////////////////////////////////////////////////////
// Init manager from text file
// Aim:		init airportManager from file, if could not return 0
// 
// Input:	pointer to the manager
//			file read from 
// Output:	0- for error , 1-read from file 
/////////////////////////////////////////////////////////////////
int initManagerFromFile(AirportManager* pManager, const char* fileName)//return 1 for success
{
	Airport* pPort;
	int numOfAirports = 0;
	FILE* file;
	file = fopen(fileName, "r"); // open for reading 

	if (!file) 
	{
		printf("cant init manager from file\n");//maybe print in function not here ?
		return 0;
	}

	fscanf(file,"%d",&numOfAirports);//first row of file

	for (int i = 0; i < numOfAirports; i++)//read file(3 rows per airline)
	{

		pPort = (Airport*)malloc(sizeof(Airport));
		if (!pPort)
			return 0;

		if (!initAirportFromFile(pPort, file))
		{
			printf("Error loading airport from file\n");
			fclose(file);
			return 0;
		}

		L_insertInCodeOrder(&pManager->airportList, pPort);// orders the list
	}

	fclose(file);
	return 1;

}




int		initAirportFromFile(Airport* pPort, FILE* file)
{
	char temp[MAX_STR_LEN];

	if (!pPort)
		return 0;

	do {
		myGetsFile(temp, MAX_STR_LEN, file);

	} while (strlen(temp) < 2);
	pPort->name = getDynStr(temp);

	do {
		myGetsFile(temp, MAX_STR_LEN, file);

	} while (strlen(temp) < 2);
	pPort->country = getDynStr(temp);

	fscanf(file, "%s", pPort->code);
	return 1;
}





/////////////////////////////////////////////////////////////////
// save/write manager to text file
// Aim:		save/write manager to text file, if could not return 0
// 
// Input:	pointer to the manager
//			file to write to
// Output:	0- for error , 1-success 
/////////////////////////////////////////////////////////////////
int saveManagerToFile(const AirportManager* pManager, const char* fileName)
{
	FILE* file;

	file = fopen(fileName, "w");//open to write - "airport_authority.txt"
	if (!file)
	{
		printf("cant open file to write in \n");
		return 0;
	}

	fprintf(file, "%d\n", L_length(&(pManager->airportList))-1);//  -1?// first line num of airports/length of list

	NODE* pNode = pManager->airportList.head.next; //first member of list 
	while (pNode) {
		if (!saveAirportToFile(pNode->key, file))
		{
			printf("cant write airport to file\n");
			fclose(file);
			return 0;
		}
		pNode = pNode->next;


	}
	fclose(file);
	return 1; //success

}


int saveAirportToFile(const Airport* pPort, FILE* file) 
{

	if (!pPort)
		return 0;

	fprintf(file, "%s\n", pPort->name);
	fprintf(file, "%s\n", pPort->country);
	fprintf(file, "%s\n", pPort->code);


	return 1;

}







/////////////////////////////////////////////////////////////////
// Init
// Aim:		init airportManager from file, if could not-init empty list 
// 
// Input:	pointer to the manager
//			file read from 
// Output:	0- for error , 1-read from file , 2 - init an empty list
/////////////////////////////////////////////////////////////////
int initManager(AirportManager* pManager, const char* fileName)
{
	if (!L_init(&(pManager->airportList))) 
	{
		printf("could NOT init \n");
		return 0;

	}

	else if (initManagerFromFile(pManager,fileName))
	{
		//printf("could init from file\n");
		return 1;
	}

	else
	{
		L_init(&(pManager->airportList));
		printf(" init EMPTY\n");
		return 2;

	}


}




