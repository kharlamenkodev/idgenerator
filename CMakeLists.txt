cmake_minimum_required(VERSION 3.14)

project(idgenerator
        VERSION 1.0.0
        DESCRIPTION "Bureau 1440 test task"
        LANGUAGES CXX
)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

option(ID_GENERATOR_TESTING "Enable module testing" ON)

add_library(${PROJECT_NAME} SHARED src/idgenerator.cpp
                                   include/idgenerator.h)

add_library(idgenerator::idgenerator ALIAS ${PROJECT_NAME})

#---> Testing
if(NOT ID_GENERATOR_TESTING)
    message(STATUS "IdGenerator --> testing DISABLED")
elseif(IS_SUBPROJECT)
    message(STATUS "IdGenerator --> testing DISABLED due the lib is a submodule")
else()
    add_subdirectory(tests)
    message(STATUS "IdGenerator --> testing ENABLED")
endif()
#<---

#---> Documentation
if(IS_SUBPROJECT)
    message(STATUS "IdGenerator --> documentation DISABLED due the lib is a submodule")
else()
    add_subdirectory(doc)
    message(STATUS "IdGenerator --> documentation ENABLED")
endif()
#<---

target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PRIVATE src
)
