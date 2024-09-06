cmake_minimum_required(VERSION 3.5)

project(03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(03 main.cpp
    figure.cpp
    figure.h
    triangles/triangle.cpp
    triangles/triangle.h
    triangles/RightTriangle.cpp
    triangles/RightTriangle.h
    triangles/IsoTriangle.cpp
    triangles/IsoTriangle.h
    triangles/EquilateralTriangle.cpp
    triangles/EquilateralTriangle.h
    quadrilaterals/Quadrilaterals.cpp
    quadrilaterals/Square.cpp
    quadrilaterals/Square.h
    quadrilaterals/Rhombus.cpp
    quadrilaterals/Rhombus.h
    quadrilaterals/Rectangle.cpp
    quadrilaterals/Rectangle.h
    quadrilaterals/Parallelogram.cpp
    quadrilaterals/Parallelogram.h
    quadrilaterals/Quadrilateral.h
)

include(GNUInstallDirs)
install(TARGETS 03
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
