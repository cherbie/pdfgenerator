cmake_minimum_required(VERSION 3.2)
project(pdfgen)

add_library(pdfgen SHARED)

target_sources(pdfgen
	PRIVATE
    src/Name.cpp
    src/Integer.cpp
    src/String.cpp
    src/Bool.cpp
)

target_include_directories(pdfgen
	PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

