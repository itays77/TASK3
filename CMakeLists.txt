cmake_minimum_required(VERSION 3.27)
project(caca C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(caca
        Airline.c
        Airline.h
        Airport.c
        Airport.h
        AirportManager.c
        AirportManager.h
        Date.c
        Date.h
        def.h
        fileFunctions.c
        fileFunctions.h
        Flight.c
        Flight.h
        General.c
        General.h
        listGen.h
        listGen.c
        main.c
        Plane.c
        Plane.h)
