cmake_minimum_required(VERSION 3.2)
project(test)

set(GTEST_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest")

# GoogleTest has cmake build system configured
add_subdirectory(lib/googletest)

add_executable(test)

target_sources(test
	PRIVATE
		main.cpp
		src/test.cpp
)

target_include_directories(test
	PUBLIC
		"${CMAKE_SOURCE_DIR}/include"
		"${GTEST_MODULE_PATH}/googletest/include"
		"${GTEST_MODULE_PATH}/googlemock/include"
)

target_link_libraries(test
	PRIVATE
		gtest
		gmock
		pdfgen
)
