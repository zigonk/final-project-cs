cmake_minimum_required(VERSION 3.10)
project(final_project_cs)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(final_project_cs
        src/academic_roles.cpp
        src/academic_roles.h
        src/data_io.cpp
        src/data_io.h
        src/data_struct.h
        src/lecturer_roles.cpp
        src/lecturer_roles.h
        src/main.cpp
        src/menu.cpp
        src/menu.h
        src/screen.cpp
        src/screen.h
        src/student_roles.cpp
        src/student_roles.h)
