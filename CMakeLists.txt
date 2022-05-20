cmake_minimum_required(VERSION 3.0)
project(alter_tank C)
set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE SOURCE "src/*.c", "src/*.h")
add_executable(alter_tank "${SOURCE}")

INCLUDE_DIRECTORIES(/usr/local/include/SDL2)
LINK_DIRECTORIES(/usr/local/lib)
TARGET_LINK_LIBRARIES(alter_tank m SDL2 SDL2_gfx)
