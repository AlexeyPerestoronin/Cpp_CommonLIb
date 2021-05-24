cmake_minimum_required(VERSION 3.1.0)

include_directories(./)
include_directories(./advanced_algorithms)

file(GLOB HPP_FILES "./*.hpp")
file(GLOB CPP_FILES "./*.cpp")

add_library(${LIB_NAME} STATIC ${CPP_FILES} ${HPP_FILES})
target_compile_features(${LIB_NAME} PRIVATE ${PROJECT_CPP_STANDART})

# declare below all sub-library

# [1] errors.lib
set(ERRORS_LIB_NAME "errors")
add_subdirectory(./errors)
target_link_libraries(${LIB_NAME} ${ERRORS_LIB_NAME})
