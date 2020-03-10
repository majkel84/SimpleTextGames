cmake_minimum_required(VERSION 3.2)
project(SimpleTextGames)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_LIST
    src/BattleShip.hpp
    src/BattleShip.cpp
    )

include_directories(src)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
add_compile_options(-Wall -Wextra -Werror -Wpedantic)
add_executable(${PROJECT_NAME} src/main.cpp)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib pthread)
else (UNIX)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
endif (UNIX)
