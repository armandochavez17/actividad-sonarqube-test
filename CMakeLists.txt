cmake_minimum_required(VERSION 3.10)
project(ActividadIntegradora)

set(CMAKE_CXX_STANDARD 17)

# Enable testing
enable_testing()
include(CTest)

# Enable code coverage
option(ENABLE_COVERAGE "Enable coverage reporting" ON)
if(ENABLE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")
endif()

# Include and source directories
include_directories(include)
add_subdirectory(test)

# Main executable
add_executable(main main.cpp src/integradora.cpp)
