###############################################################################
# Minimal CMake version that is needed to process current project
cmake_minimum_required(VERSION 3.6)
###############################################################################
# Languages that are used in the project
enable_language(C)
###############################################################################
# Main project name
project(cred_storage)
###############################################################################
add_library(${PROJECT_NAME} EXCLUDE_FROM_ALL)
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/cred_storage.c)
target_link_libraries(${PROJECT_NAME} PRIVATE fs)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
###############################################################################
