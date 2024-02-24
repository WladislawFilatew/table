#CmakeList относяшийся к проекту polinom
cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME polinom)
project(${PROJECT_NAME})

set(polinom polinom)
set(polinomlib polinomlib)
set(polinomtest polinomtest)
set(listlib listlib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/listlib)
add_subdirectory(listlib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/polinomlib)
add_subdirectory(polinomlib)

add_subdirectory(test)


file(GLOB srcs "*.cpp")

add_executable(${PROJECT_NAME} ${srcs} )

target_link_libraries(${PROJECT_NAME} ${listlib} ${polinomlib} gtest)