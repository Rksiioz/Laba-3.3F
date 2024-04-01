cmake_minimum_required(VERSION 3.27)
project(Laba_3_3F)

set(CMAKE_CXX_STANDARD 17)

add_executable(Laba_3_3F main.cpp
        AccountPublic.h
        AccountPublic.cpp
        Money.h
        Money.cpp
        AccountPrivate.h
        AccountPrivate.cpp)
