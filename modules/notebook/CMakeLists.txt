project(notebook)

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
configure_file(src/res/Notebook.rc.cmake Notebook.rc @ONLY)

set(PROJECT_HEADERS
	${CMAKE_CURRENT_BINARY_DIR}/Version.h
	include/CAdd.h
	include/CMain.h
	include/FriendManager.h
	include/Friend.h
	include/resource.h
	include/targetver.h
	)
set(PROJECT_RESOURCES
	src/res/carrot.ico
	${CMAKE_CURRENT_BINARY_DIR}/Notebook.rc
	${CMAKE_CURRENT_BINARY_DIR}/Version.rc
	)
set(PROJECT_SOURCES
	src/main.cpp
	src/CAdd.cpp
	src/FriendManager.cpp
	src/CMain.cpp
	src/Friend.cpp
	)
set(MISC
	src/pch.h
	src/pch.cpp
	)

set_source_files_properties(
	${CMAKE_CURRENT_BINARY_DIR}/Version.h PROPERTIES GENERATED 1)
set_source_files_properties(
	${CMAKE_CURRENT_BINARY_DIR}/Version.rc PROPERTIES GENERATED 1)
set_source_files_properties(
	${CMAKE_CURRENT_BINARY_DIR}/Notebook.rc PROPERTIES GENERATED 1)

source_group("Header Files" FILES ${PROJECT_HEADERS})
source_group("Resource Files" FILES ${PROJECT_RESOURCES})
source_group("Source Files" FILES ${PROJECT_SOURCES})
source_group("" FILES ${MISC})

add_executable(${PROJECT_NAME} WIN32
	${PROJECT_HEADERS}
	${PROJECT_RESOURCES}
	${PROJECT_SOURCES}
	${MISC}
	)

include_directories(
	include
	${Boost_INCLUDE_DIRS}
	${WTL_INCLUDE_DIRS}
	)
target_link_libraries(${PROJECT_NAME}
	${Boost_LIBRARIES}
	)
add_definitions(
	-DUNICODE
	-D_UNICODE
	)

set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/pch.h")
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_UNITY_LINK_LIBRARIES_INIT "COPY")
cotire(${PROJECT_NAME})