cmake_minimum_required(VERSION 3.14)

project(idgenerator
        VERSION 1.0.0
        DESCRIPTION "Bureau 1440 test task"
        LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/idgenerator.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)