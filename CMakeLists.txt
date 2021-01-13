cmake_minimum_required(VERSION 3.16)
project(nagyhf2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(nagyhf2
        sportegyesulet.cpp
        sportegyesulet.h
        csapatok.h
        main.cpp
        memtrace.cpp
        memtrace.h stringek.h stringek.cpp tesztek.cpp tesztek.h)
