cmake_minimum_required(VERSION 3.0)
project(jihocg CXX)
set(CMAKE_CXX_STANDARD 11)

# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/")

# Declaring our executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
# target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

set(ENABLE_EXAMPLES NO)
set(PIXELTOASTER_TINY  YES)
add_subdirectory(vendor/pixeltoaster)
target_link_libraries(${PROJECT_NAME} PRIVATE PixelToaster d3d9)
target_include_directories(${PROJECT_NAME} PRIVATE vendor/pixeltoaster)

# Setting ASSETS_PATH
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable
