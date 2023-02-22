cmake_minimum_required (VERSION 3.24.2)
project (Futures)

find_package (Threads)

set(PROJECT_CFLAGS "-Wall -std=c++20")

add_executable (futures futures.cpp test_utils.hpp)
set_target_properties(futures PROPERTIES COMPILE_FLAGS "${PROJECT_CFLAGS}")
target_link_libraries (futures ${CMAKE_THREAD_LIBS_INIT})

