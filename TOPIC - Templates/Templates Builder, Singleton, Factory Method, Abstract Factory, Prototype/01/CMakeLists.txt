cmake_minimum_required(VERSION 3.5)

project(01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(01 main.cpp sql_query_builder.h)

include(GNUInstallDirs)
install(TARGETS 01
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
