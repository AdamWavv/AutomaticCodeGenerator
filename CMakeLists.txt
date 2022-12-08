cmake_minimum_required(VERSION 3.5)

project(AutomaticCodeGenerator
        VERSION 0.0.1
        DESCRIPTION "The project for college purposes program creating source code based on prepared UML diagram"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/rapidxml-1.13)

FILE(GLOB_RECURSE SRC_FILES src/*.c*)
FILE(GLOB_RECURSE HDR_FILES include/*.h*)
FILE(GLOB_RECURSE LIB_FILES lib/rapidxml-1.13/*.h*)

add_executable(${PROJECT_NAME} ${HDR_FILES} ${SRC_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

#target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
