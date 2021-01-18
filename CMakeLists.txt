cmake_minimum_required( VERSION 3.19.0 )
project( LAB4 )

#include files
include_directories( ./include/LAB4  ./src )

#target
add_executable(main ./src/main.cpp  ./src/matrix.cpp )