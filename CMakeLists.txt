cmake_minimum_required(VERSION 2.8.2)
project(bench)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/")

# set(CONAN_SYSTEM_INCLUDES ON)
# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

set (SANITIZER_FLAGS "\
    -fno-omit-frame-pointer\
    -fsanitize=address\
    -fsanitize=undefined\
    ")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}\
    ${SANITIZER_FLAGS}")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG}
    ${SANITIZER_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}\
    -march=native\
    ")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings
      -Weverything
      -Wno-signed-enum-bitfield
      -Wno-padded
      -Wno-c++98-compat
      -Wno-c++98-compat-pedantic
      -Wno-missing-prototypes
      -Wno-c++17-extensions
      )
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(warnings
      -Wall
      -Wextra
      -Wpedantic
      -Wshadow
      -Wnon-virtual-dtor
      -Wold-style-cast
      -Wcast-align
      -Wunused
      -Woverloaded-virtual
      -Wconversion
      -Wsign-conversion
      -Wduplicated-cond
      -Wduplicated-branches
      -Wlogical-op
      -Wnull-dereference
      -Wuseless-cast
      -Wdouble-promotion
      )
endif()

include_directories(include)

add_executable(col_major test/col_major.cpp)
# target_link_libraries(col_major ${CONAN_LIBS})
target_compile_options(col_major PRIVATE ${warnings})

add_executable(row_major test/row_major.cpp)
# target_link_libraries(row_major ${CONAN_LIBS})
target_compile_options(row_major PRIVATE ${warnings})
