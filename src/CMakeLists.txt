cmake_minimum_required(VERSION 3.2)
project(pdfgen)

add_library(pdfgen SHARED)

target_sources(pdfgen
	PRIVATE
		name.cpp)

target_include_directories(pdfgen
	PUBLIC
		"${CMAKE_SOURCE_DIR}/include"
)

