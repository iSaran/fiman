cmake_minimum_required(VERSION 2.8.3)
project(fiman)

# Use C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
  include
)

add_executable( main
  src/main.cpp
  src/fiman.cpp
  src/tools.cpp
)

target_include_directories( main
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries( main
  yaml-cpp
)

add_executable( fiman
  src/fiman_terminal.cpp
  src/fiman.cpp
  src/tools.cpp
)

target_include_directories( fiman
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries( fiman
  yaml-cpp
)
