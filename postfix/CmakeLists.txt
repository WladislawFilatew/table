#CmakeLists для проекта postfix
cmake_minimum_required(VERSION 2.8)

project(postfix)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB CPP "*.CPP")

set(postfixlib postfixlib)
include_directories(${CMAKE_SOURCE_DIR}/postfixlib)


set(test postfixtest)
include_directories(${CMAKE_SOURCE_DIR}/test)
include_directories(${CMAKE_SOURCE_DIR}/stack/stacklib)





add_subdirectory(postfixlib)	
add_subdirectory(test)
add_subdirectory(stack)

add_executable(${PROJECT_NAME} ${CPP})

target_link_libraries(${PROJECT_NAME} ${postfixlib})	