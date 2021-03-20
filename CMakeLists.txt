cmake_minimum_required(VERSION 3.10)
project(edith VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(edith main.c)
install(TARGETS edith DESTINATION bin)
