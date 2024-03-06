#ifndef __AIR_MANAGER__
#define __AIR_MANAGER__

#include "Airport.h"
#include "listGen.h"

typedef struct
{
	//Airport**	airportsArray;//changed to LIST
	//int			airportsCount;//need to change


	LIST		airportList;

}AirportManager;

//int		 initManager(AirportManager* pManager);

int			 addAirport(AirportManager* pManager);
Airport*	 initAirport( AirportManager* pManager);
Airport*	 findAirportByCode(const AirportManager* pManager, const char* code);
int			 checkUniqeCode(const char* code, const AirportManager* pManager);
void		 printAirports(const AirportManager* pManager);
void		 freeManager(AirportManager* pManager);
//void		 freeAirportArr(AirportManager* pManager);


int		 initAirportFromFile(Airport* pAir, FILE* fp);//put in atiport.c?

int		 initManager(AirportManager* pManager, const char* fileName);

int		 initManagerFromFile(AirportManager* pManager, const char* fileName);//init from text file

int		 saveManagerToFile(const AirportManager* pManager, const char* fileName);//in order to file so can be read from file

int		 saveAirportToFile(const Airport* pPort, FILE* file);

int		 compareAirport(const void* data1, const void* data2);//comperator

//int		 initManagerAndAirline(AirportManager* pManager, Airline* pCompany);//airline* ?

#endif