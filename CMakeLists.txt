cmake_minimum_required(VERSION 3.16)
project(pragma-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release"
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

include(GNUInstallDirs)

set(SOURCES
  main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

target_compile_options(${PROJECT_NAME}
                       PRIVATE $<$<PLATFORM_ID:Windows>:
                               /W4
                               >
                               $<$<PLATFORM_ID:Darwin, Linux>:
                               -Werror
                               -Wall
                               -Wextra
                               -Wpedantic
                              >
 )
