# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(CVector VERSION 1.0.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files for your library
set(SOURCES
        CVector.cpp
)

# Header files for your library
set(HEADERS
        CVector.h
)

# Create the library as a shared (dynamic) library
add_library(CVector SHARED ${SOURCES} ${HEADERS})

# Set include directories
target_include_directories(CVector
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

# Installation
install(TARGETS CVector
        EXPORT CVectorConfig
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION .
)

install(FILES ${HEADERS} DESTINATION include)

install(EXPORT CVectorConfig DESTINATION cmake)
