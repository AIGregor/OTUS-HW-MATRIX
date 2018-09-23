cmake_minimum_required(VERSION 3.2)

project(matrix_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(GTEST_LIBRARY C:/GTest/googletest-master/googletest/msvc/2010/gtest-md/Win32-Debug/gtestd.lib) 
	set(GTEST_MAIN_LIBRARY C:/GTest/googletest-master/googletest/msvc/2010/gtest-md/Win32-Debug/gtest_maind.lib)
	set(GTEST_ROOT C:/GTest/googletest-master/googletest)
endif()

find_package(GTest REQUIRED)

add_executable(matrix_test testMatrix.cpp)

set_target_properties(matrix_test PROPERTIES
INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIRS};${INCLUDE_DIR}"
)

target_link_libraries(matrix_test ${GTEST_LIBRARIES} )

add_test(CheckSize matrix_test)
add_test(CheckAddValue matrix_test)
add_test(CheckRemoveValue matrix_test)
add_test(CheckFullCells matrix_test)