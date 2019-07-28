project(tray-agent)

set(VERSION_FILE_DESC "${PROJECT_NAME}")
set(VERSION_PRODUCT_NAME "${PROJECT_NAME}")
set(VERSION_INTERNAL_NAME "${VERSION_PRODUCT_NAME}")
set(VERSION_ORIGINAL_FILENAME "${VERSION_PRODUCT_NAME}.exe")

if (CMAKE_CL_64)
	set(VERSION_FILE_DESC "${VERSION_FILE_DESC} 64-bit")
else()
	set(VERSION_FILE_DESC "${VERSION_FILE_DESC} 32-bit")
endif()

configure_file(src/res/Version.h.cmake Version.h @ONLY)
configure_file(src/res/Version.rc.cmake Version.rc @ONLY)
configure_file(src/res/tray_agent.rc.cmake tray_agent.rc @ONLY)

set(PROJECT_HEADERS
	${CMAKE_CURRENT_BINARY_DIR}/Version.h
	include/App.h
	include/Resource.h
	include/targetver.h
	include/TrayIcon.h
	include/Utils.h
	)
set(PROJECT_RESOURCES
	${CMAKE_CURRENT_BINARY_DIR}/Version.rc
	${CMAKE_CURRENT_BINARY_DIR}/tray_agent.rc
	src/res/Connected.ico
	src/res/Disconnected.ico
	)
set(PROJECT_SOURCES
	src/App.cpp
	src/main.cpp
	src/TrayIcon.cpp
	)
set(MISC
	src/pch.h
	src/pch.cpp
	)

add_executable(${PROJECT_NAME} WIN32
	${PROJECT_HEADERS}
	${PROJECT_RESOURCES}
	${PROJECT_SOURCES}
	${MISC}
	)

set_source_files_properties(
	${CMAKE_CURRENT_BINARY_DIR}/Version.h PROPERTIES GENERATED 1)
set_source_files_properties(
	${CMAKE_CURRENT_BINARY_DIR}/Version.rc PROPERTIES GENERATED 1)
set_source_files_properties(
	${CMAKE_CURRENT_BINARY_DIR}/tray_agent.rc PROPERTIES GENERATED 1)

source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Resource Files" FILES ${PROJECT_RESOURCES})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

include_directories(
	include
	${Boost_INCLUDE_DIRS}
	${WTL_INCLUDE_DIRS}
	)
target_link_libraries(${PROJECT_NAME}
	${CONAN_LIBS}
	${Boost_LIBRARIES}
	)
add_definitions(
	-DWIN32_LEAN_AND_MEAN
	-DUNICODE
	-D_UNICODE
	)

set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/pch.h")
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_UNITY_LINK_LIBRARIES_INIT "COPY")
cotire(${PROJECT_NAME})