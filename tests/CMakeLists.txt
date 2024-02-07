cmake_minimum_required(VERSION 3.14)

project(idgeneratortest
        VERSION 1.0.0
        DESCRIPTION "Id generator tests"
        LANGUAGES CXX
)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()
