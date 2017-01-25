#Name of the project and supporte language
project(Pomodoro C)
cmake_minimum_required(VERSION 2.6)
# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})
# Add an executable compiled from pomodoro
add_executable(pomodoro main.c)
# Link the target to the GTK+ libraries
target_link_libraries(pomodoro ${GTK3_LIBRARIES})
