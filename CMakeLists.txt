cmake_minimum_required(VERSION 2.8)

project(scrutil)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 14)

find_package(X11 REQUIRED)
find_package(PNG REQUIRED)
link_libraries(${X11_LIBRARIES} ${PNG_LIBRARY})

include_directories("${PROJECT_SOURCE_DIR}/src" ${X11_INCLUDE_DIR} ${PNG_INCLUDE_DIR})

file(GLOB scrutil
  ${PROJECT_SOURCE_DIR}/src/*.cpp
  )

add_executable(scrutil ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/screenshot.cpp ${PROJECT_SOURCE_DIR}/src/png_handler.cpp)
