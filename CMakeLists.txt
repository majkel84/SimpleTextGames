cmake_minimum_required(VERSION 3.2)
project(SimpleTextGames)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
add_compile_options(-Wall -Wextra -Werror -Wpedantic)
add_executable(${PROJECT_NAME} src/main.cpp)
