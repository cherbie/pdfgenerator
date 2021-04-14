cmake_minimum_required(VERSION 3.14)
project(PDFGenerator)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")

set(PDFGEN_PROJECT_DIR "${CMAKE_SOURCE_DIR}/pdfgen/include")

add_subdirectory(pdfgen)
add_subdirectory(test)
