


////_CRTDBG_MAP_ALLOC
////#include<crtdbg.h>
//
//#include <stdio.h>
//#include <stdlib.h>
//#include "Airline.h"
//#include "listGen.h"
//#include "AirportManager.h"
//#include "General.h"
//
//#define MANAGER_FILE_NAME_SRC "airport_authority.txt"
//#define AIRLINE_FILE_NAME_SRC "airline.bin"
//
//#define MANAGER_FILE_NAME_DST "airport_authority_out.txt"
//#define AIRLINE_FILE_NAME_DST "airline_out.bin"
//
//typedef enum
//{
//	eAddAirport, eAddPlane, eAddFlight, ePrintCompany, ePrintAirports,
//	ePrintFlightsPlaneType, eSortFlights, eSearchFlight, eNofOptions
//} eMenuOptions;
//
//const char* str[eNofOptions] = { "Add Airport","Add Plane","Add Flight",
//								"Print Airline", "Print all Airports",
//								"Print all flights with plane type",
//								"Sort flights", "Find flight" };
//
//#define EXIT		-1
//int menu();
//
//int main()
//{
//	AirportManager	manager;
//	Airline			company;
//
//	initManager(&manager,MANAGER_FILE_NAME_SRC);
//	//	  initAirline(&company);
//	   initAirlineFromFile(&company, &manager, AIRLINE_FILE_NAME_SRC);
//	   // loadAirlineFromFile(&company, &manager, AIRLINE_FILE_NAME_SRC);
//
//	int option;
//	int stop = 0;
//
//
//	do
//	{
//		option = menu();
//		switch (option)
//		{
//		case eAddPlane:
//			if (!addPlane(&company))
//				printf("Error adding plane\n");
//			break;
//
//		case eAddAirport:
//			if (!addAirport(&manager))
//				printf("Error adding airport\n");
//			break;
//
//		case eAddFlight:
//			if (!addFlight(&company, &manager))
//				printf("Error adding flight\n");
//			break;
//
//		case ePrintCompany:
//			printCompany(&company);
//			break;
//
//		case ePrintAirports:
//			printAirports(&manager);
//			break;
//
//		case ePrintFlightsPlaneType:
//			doPrintFlightsWithPlaneType(&company);
//			break;
//
//		case eSortFlights:
//			sortFlight(&company);
//			break;
//
//		case eSearchFlight:
//			findFlight(&company);
//			break;
//
//		case EXIT:
//			//if(!saveManagerToFile(&manager,MANAGER_FILE_NAME_DST));//save on exit
//			//{
//			//	printf("cant save to file \n");
//			//}
//			saveManagerToFile(&manager, MANAGER_FILE_NAME_DST);//save on exit
//
//			printf("Bye bye\n");
//			stop = 1;
//			break;
//
//		default:
//			printf("Wrong option\n");
//			break;
//		}
//	} while (!stop);
//
//	//saves here?
//
//	freeManager(&manager);
//	freeCompany(&company);
//
//	return 1;
//}
//
//int menu()
//{
//	int option;
//	printf("\n\n");
//	printf("Please choose one of the following options\n");
//	for (int i = 0; i < eNofOptions; i++)
//		printf("%d - %s\n", i, str[i]);
//	printf("%d - Quit\n", EXIT);
//	scanf("%d", &option);
//	//clean buffer
//	char tav;
//	scanf("%c", &tav);
//	return option;
//}
//
//
//
//
//
//int initManagerAndAirline(AirportManager* pManager, Airline* pCompany)
//{
//
//
//	if (!initManager(pManager, MANAGER_FILE_NAME_SRC))
//			return 0;
//
//	if (!initAirlineFromFile(pCompany, pManager, AIRLINE_FILE_NAME_SRC))
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
//
//
//
////int initManagerAndAirline(AirportManager* pManager ,Airline* pCompany)
////{
////    int res = initManager(pManager, MANAGER_FILE_NAME);
////    if (!res)
////    {
////        printf("error init manager\n");
////        return 0;
////    }
////
////    if (res == FROM_FILE)
////        return initAirlineFromFile(pCompany,pManager, COMPANY_FILE_NAME);
////    else
////        initCompany(pCompany, pManager);
////    return 1;
////}
//
//
//
//
//
////_CrtDumpMemoryLeaks();



#include <stdio.h>
#include <stdlib.h>
#include "Airline.h"
#include "listGen.h"
#include "AirportManager.h"
#include "General.h"

#define MANAGER_FILE_NAME_SRC "airport_authority.txt"
#define AIRLINE_FILE_NAME_SRC "airline.bin"

#define MANAGER_FILE_NAME_DST "airport_authority_out.txt"
#define AIRLINE_FILE_NAME_DST "airline_out.bin"

typedef enum
{
	eAddAirport, eAddPlane, eAddFlight, ePrintCompany, ePrintAirports,
	ePrintFlightsPlaneType, eSortFlights, eSearchFlight, eNofOptions
} eMenuOptions;

const char* str[eNofOptions] = { "Add Airport","Add Plane","Add Flight",
								"Print Airline", "Print all Airports",
								"Print all flights with plane type",
								"Sort flights", "Find flight" };

#define EXIT		-1
int menu();

int main()
{
	AirportManager	manager;
	Airline			company;

	initManager(&manager, MANAGER_FILE_NAME_SRC);
	//	  initAirline(&company);
	initAirlineFromFile(&company, &manager, AIRLINE_FILE_NAME_SRC);


	int option;
	int stop = 0;


	do
	{
		option = menu();
		switch (option)
		{
		case eAddPlane:
			if (!addPlane(&company))
				printf("Error adding plane\n");
			break;

		case eAddAirport:
			if (!addAirport(&manager))
				printf("Error adding airport\n");
			break;

		case eAddFlight:
			if (!addFlight(&company, &manager))
				printf("Error adding flight\n");
			break;

		case ePrintCompany:
			printCompany(&company);
			break;

		case ePrintAirports:
			printAirports(&manager);
			break;

		case ePrintFlightsPlaneType:
			doPrintFlightsWithPlaneType(&company);
			break;

		case eSortFlights:
			sortFlight(&company);
			break;

		case eSearchFlight:
			findFlight(&company);
			break;

		case EXIT:
			//if(!saveManagerToFile(&manager,MANAGER_FILE_NAME_DST));//save on exit
			//{
			//	printf("cant save to file \n");
			//}
			saveManagerToFile(&manager, MANAGER_FILE_NAME_DST);//save on exit
			saveAirlineToFile(&company, AIRLINE_FILE_NAME_DST);

			printf("Bye bye\n");
			stop = 1;
			break;

		default:
			printf("Wrong option\n");
			break;
		}
	} while (!stop);

	//saves here?



	freeManager(&manager);
	freeCompany(&company);

	return 1;
}

int menu()
{
	int option;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for (int i = 0; i < eNofOptions; i++)
		printf("%d - %s\n", i, str[i]);
	printf("%d - Quit\n", EXIT);
	scanf("%d", &option);
	//clean buffer
	char tav;
	scanf("%c", &tav);
	return option;
}


int initManagerAndAirline(AirportManager* pManager ,Airline* pCompany)
{
    int res = initManager(pManager, MANAGER_FILE_NAME_SRC);
    if (!res)
    {
        printf("error init manager\n");
        return 0;
    }

    if(!initAirlineFromFile(pCompany, pManager, AIRLINE_FILE_NAME_SRC))
        initAirline(pCompany);

    return 1;
}





//_CrtDumpMemoryLeaks();