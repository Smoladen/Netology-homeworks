cmake_minimum_required(VERSION 3.2)

project(03 LANGUAGES CXX)


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

