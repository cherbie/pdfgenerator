cmake_minimum_required(VERSION 3.2)
project(test)

set(CMAKE_CXX_FLAGS "")
set(GTEST_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest")

# GoogleTest has cmake build system configured
add_subdirectory(lib/googletest)

add_executable(test)

target_sources(test
	PRIVATE
		main.cpp
		src/test_name.cpp
    src/test_integer.cpp
    src/test_string.cpp
    src/test_bool.cpp
)

target_include_directories(test
	PUBLIC
    "${PDFGEN_PROJECT_DIR}/include"
		"${GTEST_MODULE_PATH}/googletest/include"
		"${GTEST_MODULE_PATH}/googlemock/include"
)

target_link_libraries(test
  PUBLIC
		gtest
		gmock
  PRIVATE
		pdfgen
)
