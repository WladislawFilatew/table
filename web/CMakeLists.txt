cmake_minimum_required(VERSION 2.8)
set(target WebProject)
set(nameMain "Main")

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
file(GLOB resx "*.resx")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:${nameMain}")
add_executable(${target} WIN32 ${srcs} ${hdrs} ${resx})
target_link_libraries(${target})
set_target_properties(${target} PROPERTIES
    FOLDER ${target}
    VS_DOTNET_REFERENCES "System;System.Data;System.Drawing;System.Windows.Forms;System.Xml"
    VS_GLOBAL_ROOTNAMESPACE ${target}
    COMMON_LANGUAGE_RUNTIME ""
    CMAKE_VS_TARGET_FRAMEWORK_VERSION "v4.7.2"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../gtest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../polinom/listlib ${CMAKE_CURRENT_SOURCE_DIR}/../polinom/polinomlib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../postfix/lib)
include_directories(../table)
include_directories(../table/Tree/lib)
include_directories(../table/HashChain/lib)
include_directories(../table/HashList/lib)
include_directories(../table/LinearOnArray/lib)
include_directories(../table/LinearOnList/lib)
include_directories(../table/OrderedOnArray/lib)