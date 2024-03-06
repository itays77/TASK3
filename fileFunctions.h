#pragma once
#include "Airline.h"
//change funcs

int	 writeStringToFile(char* str, FILE* fp, const char* msg);
int	 writeCharsToFile(char* arr, int size, FILE* fp, const char* msg);
int	 writeIntToFile(int val, FILE* fp, const char* msg);

char* readStringFromFile(FILE* fp, const char* msg);
int	  readCharsFromFile(char* arr, int size, FILE* fp, const char* msg);
int	  readIntFromFile(int* val, FILE* fp, const char* msg);
int readAirlineFromBinaryFile(FILE* pFile, Airline* pComp, AirportManager* pManager);
int readFlightFromBinaryFile(FILE* pFile, Flight* pFlight, Plane* planeArr, const int planeCount);
int readPlaneArrFromBinaryFile(FILE* pFile, Plane* planeArr, const int planeCount);
int readFlightArrFromBinaryFile(FILE* pFile, Flight** pFlightArr, const int flightCount, Plane* planeArr, const int planeCount);
int readPlaneFromBinaryFile(FILE* pFile, Plane* pPlane);

int writeAirlineToBFile(FILE* pFile, const Airline* pComp);
int writePlaneArrToBFile(FILE* pFile, const Plane* pPlaneArr, const int count);
int writePlaneToBFile(FILE* pFile, const Plane* pPlane);
int writeFlightArrToBFile(FILE* pFile, Flight** const flightArr, const int count);
int writeFlightToBFile(FILE* pFile, const Flight* pFlight);
int readAirlineFromBFile(FILE* pFile, Airline* pComp, AirportManager* pManager);
int readPlaneArrFromBFile(FILE* pFile, Plane* pPlaneArr, const int planeCount);
int readPlaneFromBFile(FILE* pFile, Plane* pPlane);
int readFlightArrFromBFile(FILE* pFile, Flight** pFlightArr, const int flightCount, Plane* pPlaneArr, const int planeCount);
int readFlightFromBFile(FILE* pFile, Flight* pFlight, Plane* pPlaneArr, const int planeCount);


