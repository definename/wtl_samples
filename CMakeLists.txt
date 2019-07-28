cmake_minimum_required(VERSION 3.9.0)

project(wtl-samples)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_BUILD "0")
set(REVISION_COUNT "0")

find_package(Git)
if(GIT_FOUND)
	execute_process(
		COMMAND ${GIT_EXECUTABLE} rev-list HEAD --count
		OUTPUT_VARIABLE DESCRIBE_BUILD
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		OUTPUT_STRIP_TRAILING_WHITESPACE)
		string(REGEX MATCH "[0-9]+" REVISION_COUNT ${DESCRIBE_BUILD})
endif()

set(VERSION_REVISION "${REVISION_COUNT}")
set(VERSION_FILE_REVISION "${REVISION_COUNT}")
set(VERSION_COMPANY_NAME "Carrot Farm")
set(VERSION_COPYRIGHT "Copyright (C) 2017 ${VERSION_COMPANY_NAME}")

include(cotire)
include(CRTLinkage)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ${BUILD_WITH_STATIC_CRT})
find_package(Boost REQUIRED COMPONENTS
	filesystem
	serialization
	)

set(WTL_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/libs/wtl91)
find_package(WTL REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(modules/notebook)
add_subdirectory(modules/tray-agent)