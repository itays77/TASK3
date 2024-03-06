//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//#include "Airline.h"
//#include "Airport.h"
//#include "General.h"
//#include "listGen.h"
//#include "fileFunctions.h"
//#include "Flight.h"
//
//
//
//static const char* sortOptStr[eNofSortOpt] = {
//        "None","Airport source code", "Airport destination code" , "Date" };
//
//void	initAirline(Airline* pComp)
//{
//    //printf("-----------  Init Airline\n");
//    pComp->name = getStrExactName("Enter Airline name");
//    pComp->flightArr = NULL;
//    pComp->flightCount = 0;
//    pComp->planeArr = NULL;
//    pComp->planeCount = 0;
//}
//
//int initAirlineFromFile(Airline* pComp, AirportManager* pManager, const char* fileName)
//{
//    pComp->flightArr = NULL; // check if needed
//    pComp->flightCount = 0; // check if needed
//    pComp->planeArr = NULL; // check if needed
//    pComp->planeCount = 0; // check if needed
//    pComp->sortOpt = eNone;
//
//    if (!readAirlineFromFile(pComp, pManager, fileName)) return 0;
//    return 1;
//}
//
//int	addFlight(Airline* pComp, const AirportManager* pManager)
//{
//    if (L_length(&(pManager->airportList)) < 2)
//    {
//        printf("There are not enough airport to set a flight\n");
//        return 0;
//    }
//    if (pComp->planeCount == 0)
//    {
//        printf("There is no plane in company\n");
//        return 0;
//    }
//
//    Flight* pFlight = (Flight*)calloc(1, sizeof(Flight));
//    if (!pFlight)
//        return 0;
//
//    Plane* thePlane = FindAPlane(pComp);
//    printAirports(pManager);
//    initFlight(pFlight, thePlane, pManager);
//
//    //pComp->flightArr = (Flight**)realloc(pComp->flightArr, (pComp->flightCount + 1) * sizeof(Flight));//**
//    //if (!pComp->flightArr)
//    //{
//    //    free(pFlight);
//    //    return 0;
//    //}
//    //pComp->flightArr[pComp->flightCount] = pFlight;
//    //pComp->flightCount++;
//    //return 1;
//
//
//    Flight** temp = (Flight**)realloc(pComp->flightArr, (pComp->flightCount + 1) * sizeof(Flight)); // Use a temporary pointer
//    if (!temp)
//    {
//        free(pFlight);
//        return 0;
//    }
//
//    pComp->flightArr = temp; // Assign the result to pComp->flightArr
//    pComp->flightArr[pComp->flightCount] = pFlight;
//    pComp->flightCount++;
//    return 1;
//
//
//
//}
//
////int		addPlane(Airline* pComp)
////{
////    pComp->planeArr = (Plane*)realloc(pComp->planeArr, (pComp->planeCount + 1) * sizeof(Plane));
////    if (!pComp->planeArr)
////        return 0;
////    initPlane(&pComp->planeArr[pComp->planeCount], pComp->planeArr, pComp->planeCount);
////    pComp->planeCount++;
////    return 1;
////}
//
//
//
//
//
//int addPlane(Airline* pComp)
//{
//    Plane* temp = (Plane*)realloc(pComp->planeArr, (pComp->planeCount + 1) * sizeof(Plane)); // Use a temporary pointer
//    if (!temp)
//        return 0;
//
//    pComp->planeArr = temp; // Assign the result to pComp->planeArr
//    initPlane(&pComp->planeArr[pComp->planeCount], pComp->planeArr, pComp->planeCount);
//    pComp->planeCount++;
//    return 1;
//}
//
//
//
//
//
//Plane* FindAPlane(Airline* pComp)
//{
//    printf("Choose a plane from list, type its serial Number\n");
//    printPlanesArr(pComp->planeArr, pComp->planeCount);
//    int sn;
//    Plane* temp = NULL;
//    do {
//        scanf("%d", &sn);
//        temp = findPlaneBySN(pComp->planeArr, pComp->planeCount, sn);
//        if (!temp)
//            printf("No plane with that serial number! Try again!\n");
//    } while (temp == NULL);
//
//    return temp;
//}
//
//
//void printCompany(const Airline* pComp)
//{
//    printf("\nAirline %s\n", pComp->name);
//    printf("\n -------- Has %d planes\n", pComp->planeCount);
//    printPlanesArr(pComp->planeArr, pComp->planeCount);
//    printf("\n\n -------- Has %d flights\n", pComp->flightCount);
//    printFlightArr(pComp->flightArr, pComp->flightCount);
//}
//
//void	printFlightArr(Flight** arr, int size)
//{
//    for (int i = 0; i < size; i++)
//        printFlight(arr[i]);
//}
//
//void	printPlanesArr(Plane* arr, int size)
//{
//    for (int i = 0; i < size; i++)
//        printPlane(&arr[i]);
//}
//
//void	doPrintFlightsWithPlaneType(const Airline* pComp)
//{
//    ePlaneType type = getPlaneType();
//    int count = 0;
//    printf("Flights with plane type %s:\n", GetPlaneTypeStr(type));
//    for (int i = 0; i < pComp->flightCount; i++)
//    {
//        if (isPlaneTypeInFlight(pComp->flightArr[i], type))
//        {
//            printFlight(pComp->flightArr[i]);
//            count++;
//        }
//    }
//    if (count == 0)
//        printf("Sorry - could not find a flight with plane type %s:\n", GetPlaneTypeStr(type));
//    printf("\n");
//}
//
//void	freeFlightArr(Flight** arr, int size)
//{
//    for (int i = 0; i < size; i++)
//        free(arr[i]);
//}
//
//void freePlanes(Plane* arr, int size)
//{
//    for (int i = 0; i < size; i++)
//        freePlane(&arr[i]);
//}
//
//
//
//
//void sortFlight(Airline* pComp)
//{
//    pComp->sortOpt = showSortMenu();
//    int(*compare)(const void* air1, const void* air2) = NULL;
//
//    switch (pComp->sortOpt)
//    {
//    case eSrcCode:
//        compare = compareBySrcCode;
//        break;
//    case eDstCode:
//        compare = compareByDstCode;
//        break;
//    case eDate:
//        compare = compareByDate;
//        break;
//
//    }
//
//    if (compare != NULL)
//        qsort(pComp->flightArr, pComp->flightCount, sizeof(Flight*), compare);
//
//}
//
//
//
//
//void findFlight(const Airline* pComp)
//{
//    int(*compare)(const void* air1, const void* air2) = NULL;
//    Flight f = { 0 };
//    Flight* pFlight = &f;
//
//
//    switch (pComp->sortOpt)
//    {
//
//    case eSrcCode:
//        getchar();
//        getAirportCode(f.sourceCode);
//        compare = compareByDstCode;
//        break;
//    case eDstCode:
//        getchar();
//        getAirportCode(f.destCode);
//        compare = compareByDstCode;
//        break;
//
//    case eDate:
//        getchar();
//        getCorrectDate(&f.date);
//        compare = compareByDate;
//        break;
//    }
//
//    if (compare != NULL)
//    {
//        Flight** pF = bsearch(&pFlight, pComp->flightArr, pComp->flightCount, sizeof(Flight*), compare);
//        if (pF == NULL)
//            printf("Flight was not found\n");
//        else {
//            printf("Flight found, ");
//            printFlight(*pF);
//        }
//    }
//    else {
//        printf("The search cannot be performed, array not sorted\n");
//    }
//
//}
//
//
//
//eSortOptions showSortMenu()
//{
//    int opt;
//    printf("\nBase on what field do you want to sort?\n");
//    do {
//        for (int i = 1; i < eNofSortOpt; i++)
//            printf("Enter %d for %s\n", i, sortOptStr[i]);
//        printf("\n");
//        scanf("%d", &opt);
//    } while (opt < 1 || opt >= eNofSortOpt);//changed
//
//    return (eSortOptions)opt;
//}
//
//
//
//
//
//int saveAirlineToFile(const Airline* pComp, const char* fileName)
//{
//    FILE* fp;
//    fp = fopen(fileName, "wb");
//    if (!fp) {
//        printf("Error open airline file to write\n");
//        return 0;
//    }
//
//    if (!writeStringToFile(pComp->name, fp, "Error write airline name\n"))
//        return 0;
//
//    if (!writeIntToFile(pComp->flightCount, fp, "Error write flight count\n"))
//        return 0;
//
//    if (!writeIntToFile((int)pComp->sortOpt, fp, "Error write sort option\n"))
//        return 0;
//
//    for (int i = 0; i < pComp->flightCount; i++)
//    {
//        if (!saveFlightToFile(pComp->flightArr[i], fp))
//            return 0;
//    }
//
//    fclose(fp);
//    return 1;
//}
//
//
//
//int loadAirlineFromFile(Airline* pComp, const AirportManager* pManager, const char* fileName)
//{
//    FILE* fp = fopen(fileName, "rb");
//    if (!fp) {
//        printf("Error opening airline file\n");
//        return 0;
//    }
//
//    // Read airline name
//    int nameLen;
//    fread(&nameLen, sizeof(int), 1, fp);
//    pComp->name = (char*)malloc(nameLen * sizeof(char));
//    if (fread(pComp->name, sizeof(char), nameLen, fp) != nameLen) {
//        printf("Error reading company name\n");
//        free(pComp->name);
//        fclose(fp);
//        return 0;
//    }
//
//
//    ////changed --- from/////
//
//    // Read amount of planes and each plane
//    fread(&pComp->planeCount, sizeof(int), 1, fp);
//    pComp->planeArr = (Plane*)malloc(pComp->planeCount * sizeof(Plane));
//
//    if (!pComp->planeArr) {
//        // Handle allocation failure (print error, return, etc.)
//        fclose(fp);
//        return 0;
//    }
//
//    for (int i = 0; i < pComp->planeCount; i++) {
//        fread(&pComp->planeArr[i].serialNum, sizeof(int), 1, fp);
//        fread(&pComp->planeArr[i].type, sizeof(ePlaneType), 1, fp);
//    }
//
//    pComp->flightArr = NULL;
//
//    if (!readIntFromFile(&pComp->flightCount, fp, "Error reading flight count name\n")) {
//        free(pComp->planeArr); // Free allocated memory in case of error
//        fclose(fp);
//        return 0;
//    }
//
//
//    //// Read amount of planes and each plane
//    //fread(&pComp->planeCount, sizeof(int), 1, fp);
//    //pComp->planeArr = (Plane*)malloc(pComp->planeCount * sizeof(Plane));
//    //for (int i = 0; i < pComp->planeCount; i++) {
//    //    fread(&pComp->planeArr[i].serialNum, sizeof(int), 1, fp);
//    //    fread(&pComp->planeArr[i].type, sizeof(ePlaneType), 1, fp);
//    //}
//    //pComp->flightArr = NULL;
//    //
//    //if (!readIntFromFile(&pComp->flightCount, fp, "Error reading flight count name\n"))
//    //    return 0;
//    //
//    //int fCount;
//    //// Read number of flights
//    //fread(&fCount, sizeof(int), 1, fp);
//    //pComp->flightArr = (Flight**)malloc(pComp->flightCount * sizeof(Flight));//**
//    //for (int i = 0; i < fCount; i++) {
//    //    pComp->flightArr[i] = (Flight*)malloc(sizeof(Flight));   //excetion fcount not good number
//    //    fread(pComp->flightArr[i]->sourceCode, sizeof(char), IATA_LENGTH + 1, fp);
//    //    fread(pComp->flightArr[i]->destCode, sizeof(char), IATA_LENGTH + 1, fp);
//    //    fread(&pComp->flightArr[i]->flightPlane.serialNum, sizeof(int), 1, fp);
//    //    fread(&pComp->flightArr[i]->flightPlane.type, sizeof(ePlaneType), 1, fp);
//    //    fread(&pComp->flightArr[i]->date, sizeof(Date), 1, fp);
//    //    // Here, we assume the use of AirportManager might be needed to validate or fetch additional details for the flight's airports
//    //}
//    //
//    //fclose(fp);
//    //return 1;
//
//
//
//    int fCount;
//    // Read number of flights
//    fread(&fCount, sizeof(int), 1, fp);
//    pComp->flightArr = (Flight**)malloc(fCount * sizeof(Flight)); // Allocate based on fCount
//    if (!pComp->flightArr) {
//        // Handle allocation failure (print error, return, etc.)
//        fclose(fp);
//        return 0;
//    }
//
//    for (int i = 0; i < fCount; i++) {
//        pComp->flightArr[i] = (Flight*)malloc(sizeof(Flight));
//        if (!pComp->flightArr[i]) {
//            // Handle allocation failure for pComp->flightArr[i] (print error, free previous allocations, return, etc.)
//            fclose(fp);
//            return 0;
//        }
//        // Read flight data
//        fread(pComp->flightArr[i]->sourceCode, sizeof(char), IATA_LENGTH + 1, fp);
//        fread(pComp->flightArr[i]->destCode, sizeof(char), IATA_LENGTH + 1, fp);
//        fread(&pComp->flightArr[i]->flightPlane.serialNum, sizeof(int), 1, fp);
//        fread(&pComp->flightArr[i]->flightPlane.type, sizeof(ePlaneType), 1, fp);
//        fread(&pComp->flightArr[i]->date, sizeof(Date), 1, fp);
//        // Additional reading if needed
//    }
//
//    fclose(fp);
//    return 1;
//
//
//    //////to//////
//}
//
//
//
//
//
//
//void freeCompany(Airline* pComp)
//{
//    freeFlightArr(pComp->flightArr, pComp->flightCount);
//    free(pComp->flightArr);
//    free(pComp->planeArr);  //exciption
//    free(pComp->name);
//}
//
//
//
//
//
//
//int readAirlineFromFile(Airline* pComp, AirportManager* pManager, const char* fileName)
//{
//    FILE* pFile = fopen(fileName, "rb");
//    if (!pFile) return 0;
//    if (!readAirlineFromBFile(pFile, pComp, pManager)) return 0;
//    fclose(pFile);
//    return 1;
//}




























#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Airline.h"
#include "Airport.h"
#include "General.h"
#include "listGen.h"
#include "fileFunctions.h"



static const char* sortOptStr[eNofSortOpt] = {
        "None","Source code", "Dest code", "Date" };

void	initAirline(Airline* pComp)
{
    //printf("-----------  Init Airline\n");
    pComp->name = getStrExactName("Enter Airline name");
    pComp->flightArr = NULL;
    pComp->flightCount = 0;
    pComp->planeArr = NULL;
    pComp->planeCount = 0;
}

int initAirlineFromFile(Airline* pComp, AirportManager* pManager, const char* fileName)
{
    pComp->flightArr = NULL; // check if needed
    pComp->flightCount = 0; // check if needed
    pComp->planeArr = NULL; // check if needed
    pComp->planeCount = 0; // check if needed
    pComp->sortOpt = eNone;

    if (!readAirlineFromFile(pComp, pManager, fileName)) return 0;
    return 1;
}



//
//int	addFlight(Airline* pComp, const AirportManager* pManager)
//{
//    if (L_length(&(pManager->airportList)) < 2)
//    {
//        printf("There are not enough airport to set a flight\n");
//        return 0;
//    }
//    if (pComp->planeCount == 0)
//    {
//        printf("There is no plane in company\n");
//        return 0;
//    }
//
//    Flight* pFlight = (Flight*)calloc(1, sizeof(Flight));
//    if (!pFlight)
//        return 0;
//
//    Plane* thePlane = FindAPlane(pComp);
//    printAirports(pManager);
//    initFlight(pFlight, thePlane, pManager);
//
//    pComp->flightArr = (Flight**)realloc(pComp->flightArr, (pComp->flightCount + 1) * sizeof(Flight*));
//    if (!pComp->flightArr)
//    {
//        free(pFlight);
//        return 0;
//    }
//    pComp->flightArr[pComp->flightCount] = pFlight;
//    pComp->flightCount++;
//    return 1;
//}

int	addFlight(Airline* pComp, const AirportManager* pManager)
{
    if (L_length(&(pManager->airportList)) < 2)
    {
        printf("There are not enough airport to set a flight\n");
        return 0;
    }
    if (pComp->planeCount == 0)
    {
        printf("There is no plane in company\n");
        return 0;
    }

    Flight* pFlight = (Flight*)calloc(1, sizeof(Flight));
    if (!pFlight)
        return 0;

    Plane* thePlane = FindAPlane(pComp);
    printAirports(pManager);
    initFlight(pFlight, thePlane, pManager);

    Flight** temp = (Flight**)realloc(pComp->flightArr, (pComp->flightCount + 1) * sizeof(Flight)); // Use a temporary pointer
    if (!temp)
    {
        free(pFlight);
        return 0;
    }

    pComp->flightArr = temp; // Assign the result to pComp->flightArr
    pComp->flightArr[pComp->flightCount] = pFlight;
    pComp->flightCount++;
    return 1;



}




int addPlane(Airline* pComp)
{
    Plane* temp = (Plane*)realloc(pComp->planeArr, (pComp->planeCount + 1) * sizeof(Plane)); // Use a temporary pointer
    if (!temp)
        return 0;

    pComp->planeArr = temp; // Assign the result to pComp->planeArr
    initPlane(&pComp->planeArr[pComp->planeCount], pComp->planeArr, pComp->planeCount);
    pComp->planeCount++;
    return 1;
}





Plane* FindAPlane(Airline* pComp)
{
    printf("Choose a plane from list, type its serial Number\n");
    printPlanesArr(pComp->planeArr, pComp->planeCount);
    int sn;
    Plane* temp = NULL;
    do {
        scanf("%d", &sn);
        temp = findPlaneBySN(pComp->planeArr, pComp->planeCount, sn);
        if (!temp)
            printf("No plane with that serial number! Try again!\n");
    } while (temp == NULL);

    return temp;
}


void printCompany(const Airline* pComp)
{
    printf("Airline %s\n", pComp->name);
    printf("\n -------- Has %d planes\n", pComp->planeCount);
    printPlanesArr(pComp->planeArr, pComp->planeCount);
    printf("\n\n -------- Has %d flights\n", pComp->flightCount);
    printFlightArr(pComp->flightArr, pComp->flightCount);
}

void	printFlightArr(Flight** arr, int size)
{
    for (int i = 0; i < size; i++)
        printFlight(arr[i]);
}

void	printPlanesArr(Plane* arr, int size)
{
    for (int i = 0; i < size; i++)
        printPlane(&arr[i]);
}

void	doPrintFlightsWithPlaneType(const Airline* pComp)
{
    ePlaneType type = getPlaneType();
    int count = 0;
    printf("Flights with plane type %s:\n", GetPlaneTypeStr(type));
    for (int i = 0; i < pComp->flightCount; i++)
    {
        if (isPlaneTypeInFlight(pComp->flightArr[i], type))
        {
            printFlight(pComp->flightArr[i]);
            count++;
        }
    }
    if (count == 0)
        printf("Sorry - could not find a flight with plane type %s:\n", GetPlaneTypeStr(type));
    printf("\n");
}

void	freeFlightArr(Flight** arr, int size)
{
    for (int i = 0; i < size; i++)
        free(arr[i]);
}

void freePlanes(Plane* arr, int size)
{
    for (int i = 0; i < size; i++)
        freePlane(&arr[i]);
}

void sortFlight(Airline* pComp)
{
    pComp->sortOpt = showSortMenu();
    int(*compare)(const void* air1, const void* air2) = NULL;

    switch (pComp->sortOpt)
    {
    case eSrcCode:
        compare = compareBySrcCode;
        break;
    case eDstCode:
        compare = compareByDstCode;
        break;
    case eDate:
        compare = compareByDate;
        break;

    }

    if (compare != NULL)
        qsort(pComp->flightArr, pComp->flightCount, sizeof(Flight*), compare);

}

eSortOptions showSortMenu()
{
    int opt;
    printf("\nBase on what field do you want to sort?\n");
    do {
        for (int i = 1; i < eNofSortOpt; i++)
            printf("Enter %d for %s\n", i, sortOptStr[i]);
        printf("\n");
        scanf("%d", &opt);
    } while (opt < 1 || opt >= eNofSortOpt);//changed

    return (eSortOptions)opt;
}

void findFlight(const Airline* pComp)
{
    if (pComp->sortOpt == eNone)
    {
        printf("The search cannot be performed, array not sorted\n");
        return;
    }

    Flight** found = NULL;
    Flight newFlight;
    Flight* pNewFlight = &newFlight;



    switch (pComp->sortOpt)
    {

    case eSrcCode:
        printf("Source Airport Code: \n");
        getAirportCode(newFlight.sourceCode);
        found = bsearch(&pNewFlight, pComp->flightArr, pComp->flightCount, sizeof(Flight*), compareBySrcCode);
        break;

    case eDstCode:
        printf("Destination Airport Code: \n");
        getAirportCode(newFlight.destCode);
        found = bsearch(&pNewFlight, pComp->flightArr, pComp->flightCount, sizeof(Flight*), compareByDstCode);
        break;

    case eDate:
        getCorrectDate(&newFlight.date);
        found = bsearch(&pNewFlight, pComp->flightArr, pComp->flightCount, sizeof(Flight*), compareByDate);
        break;
    }

    if(found)
    {
        printf("Flight found, ");
        printFlight(*found);
        printf("\n");
    }
    else printf("Flight was not found\n");

}

int saveAirlineToFile(const Airline* pComp, const char* fileName)
{
    FILE* pFile;
    pFile = fopen(fileName, "wb");
    if (!pFile) return 0;

    if (!writeAirlineToBFile(pFile, pComp)) return 0;

    fclose(pFile);
    return 1;
}






int loadAirlineFromFile(Airline* pComp, const AirportManager* pManager, const char* fileName)
{
    FILE* fp = fopen(fileName, "rb");
    if (!fp) {
        printf("Error opening airline file\n");
        return 0;
    }

    // Read airline name
    int nameLen;
    fread(&nameLen, sizeof(int), 1, fp);
    pComp->name = (char*)malloc(nameLen * sizeof(char));
    if (fread(pComp->name, sizeof(char), nameLen, fp) != nameLen) {
        printf("Error reading company name\n");
        free(pComp->name);
        fclose(fp);
        return 0;
    }


    ////changed --- from/////

    // Read amount of planes and each plane
    fread(&pComp->planeCount, sizeof(int), 1, fp);
    pComp->planeArr = (Plane*)malloc(pComp->planeCount * sizeof(Plane));

    if (!pComp->planeArr) {
        // Handle allocation failure (print error, return, etc.)
        fclose(fp);
        return 0;
    }

    for (int i = 0; i < pComp->planeCount; i++) {
        fread(&pComp->planeArr[i].serialNum, sizeof(int), 1, fp);
        fread(&pComp->planeArr[i].type, sizeof(ePlaneType), 1, fp);
    }

    pComp->flightArr = NULL;

    if (!readIntFromFile(&pComp->flightCount, fp, "Error reading flight count name\n")) {
        free(pComp->planeArr); // Free allocated memory in case of error
        fclose(fp);
        return 0;
    }


    //// Read amount of planes and each plane
    //fread(&pComp->planeCount, sizeof(int), 1, fp);
    //pComp->planeArr = (Plane*)malloc(pComp->planeCount * sizeof(Plane));
    //for (int i = 0; i < pComp->planeCount; i++) {
    //    fread(&pComp->planeArr[i].serialNum, sizeof(int), 1, fp);
    //    fread(&pComp->planeArr[i].type, sizeof(ePlaneType), 1, fp);
    //}
    //pComp->flightArr = NULL;
    //
    //if (!readIntFromFile(&pComp->flightCount, fp, "Error reading flight count name\n"))
    //    return 0;
    //
    //int fCount;
    //// Read number of flights
    //fread(&fCount, sizeof(int), 1, fp);
    //pComp->flightArr = (Flight**)malloc(pComp->flightCount * sizeof(Flight));//**
    //for (int i = 0; i < fCount; i++) {
    //    pComp->flightArr[i] = (Flight*)malloc(sizeof(Flight));   //excetion fcount not good number
    //    fread(pComp->flightArr[i]->sourceCode, sizeof(char), IATA_LENGTH + 1, fp);
    //    fread(pComp->flightArr[i]->destCode, sizeof(char), IATA_LENGTH + 1, fp);
    //    fread(&pComp->flightArr[i]->flightPlane.serialNum, sizeof(int), 1, fp);
    //    fread(&pComp->flightArr[i]->flightPlane.type, sizeof(ePlaneType), 1, fp);
    //    fread(&pComp->flightArr[i]->date, sizeof(Date), 1, fp);
    //    // Here, we assume the use of AirportManager might be needed to validate or fetch additional details for the flight's airports
    //}
    //
    //fclose(fp);
    //return 1;



    int fCount;
    // Read number of flights
    fread(&fCount, sizeof(int), 1, fp);
    pComp->flightArr = (Flight**)malloc(fCount * sizeof(Flight)); // Allocate based on fCount
    if (!pComp->flightArr) {
        // Handle allocation failure (print error, return, etc.)
        fclose(fp);
        return 0;
    }

    for (int i = 0; i < fCount; i++) {
        pComp->flightArr[i] = (Flight*)malloc(sizeof(Flight));
        if (!pComp->flightArr[i]) {
            // Handle allocation failure for pComp->flightArr[i] (print error, free previous allocations, return, etc.)
            fclose(fp);
            return 0;
        }
        // Read flight data
        fread(pComp->flightArr[i]->sourceCode, sizeof(char), IATA_LENGTH + 1, fp);
        fread(pComp->flightArr[i]->destCode, sizeof(char), IATA_LENGTH + 1, fp);
        fread(&pComp->flightArr[i]->flightPlane.serialNum, sizeof(int), 1, fp);
        fread(&pComp->flightArr[i]->flightPlane.type, sizeof(ePlaneType), 1, fp);
        fread(&pComp->flightArr[i]->date, sizeof(Date), 1, fp);
        // Additional reading if needed
    }

    fclose(fp);
    return 1;


    //////to//////
}


void freeCompany(Airline* pComp)
{
    freeFlightArr(pComp->flightArr, pComp->flightCount);
    free(pComp->flightArr);
    free(pComp->planeArr);  //exciption
    free(pComp->name);
}

int readAirlineFromFile(Airline* pComp, AirportManager* pManager, const char* fileName)
{
    FILE* pFile = fopen(fileName, "rb");
    if (!pFile) return 0;
    if (!readAirlineFromBFile(pFile, pComp, pManager)) return 0;
    fclose(pFile);
    return 1;
}


