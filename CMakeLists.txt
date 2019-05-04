cmake_minimum_required(VERSION 3.10)
project(GameGUI)


option(CONFIG_BUILD_TEST "Compile Unit Tests" OFF)
if (CONFIG_BUILD_TEST)
	option(CONFIG_BUILD_TEST_GUI "Compile the manual testing window" OFF)
else()
	set(CONFIG_BUILD_TEST_GUI OFF)
endif()


option(CONFIG_STATIC "Compile in static mode" OFF)

set(BUILD_TYPE SHARED)
if (CONFIG_STATIC)
	set(BUILD_TYPE STATIC)
endif()
mark_as_advanced(BUILD_TYPE)

set(CONFIG_THIRDPARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CONFIG_BUILD_TEST)
	enable_testing()
endif()

include(documentation)
add_doc_target()

set(CONFIG_DIR "configFiles")
add_subdirectory(configFiles)
add_subdirectory(${SOURCE_DIR} bin)

