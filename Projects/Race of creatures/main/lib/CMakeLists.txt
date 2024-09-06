cmake_minimum_required(VERSION 3.5)

project(classes_dll LANGUAGES CXX)
set (CMAKELIBRARYOUTPUTDIRECTORY ${CMAKEBINARYDIR})
set (CMAKERUNTIMEOUTPUTDIRECTORY ${CMAKEBINARYDIR})
set(SOURCES
air_vehicle.cpp
broom.cpp
cammel_speedboat.cpp
cammel.cpp
centaur.cpp
eagle.cpp
flying_carpet.cpp
ground_vehicle.cpp

vehicle.cpp
walking_boots.cpp
)
set(HEADERS
air_vehicle.h
broom.h
cammel_speedboat.h
cammel.h
centaur.h
eagle.h
flying_carpet.h
ground_vehicle.h

vehicle.h
walking_boots.h
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(dll_lib SHARED ${SOURCES} ${HEADERS})

