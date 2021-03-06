cmake_minimum_required(VERSION 3.16)

# Project
SET(PROJECT_NAME action_game)
project("${PROJECT_NAME}")

# Settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Version
SET (VERSION_MAJOR 0)
SET (VERSION_MINOR 0)
SET (VERSION_FEATURE 1)
SET (VERSION_PATCH 0)
SET (VERSION "${VERSION_MAJOR}.${VERSION_MINOR}")
SET (VERSION "${VERSION}.${VERSION_FEATURE}.${VERSION_PATCH}")
MESSAGE ("Version: ${VERSION}")

# Set SDL 2
SET (FIND_PACKAGE_DEPENDENCIES
        SDL2 REQUIRED
        SDL2_IMAGE REQUIRED
        )

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

#Source and Binaries
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
SET (PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
SET (PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}/bin")
SET (PROJECT_RES_DIR "${PROJECT_SOURCE_DIR}/res")
MESSAGE ("Source path: ${PROJECT_SOURCE_DIR}")
MESSAGE ("Binary path: ${PROJECT_BINARY_DIR}")

# Configure Dependencies Directories
SET (PROJECT_CORE_DIR "${PROJECT_SOURCE_DIR}/core")

# Directories
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_BINARY_DIR}
    ${PROJECT_ROOT}
    ${PROJECT_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIR}
)

# Files
FILE(GLOB SOURCE_CORE_FILES ${PROJECT_CORE_DIR}/*.cpp)

# Add files
add_executable(
        ${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${SOURCE_CORE_FILES}
        src/core/graphic/FrameRate.cpp src/core/graphic/FrameRate.h)

#Link dependencies
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
