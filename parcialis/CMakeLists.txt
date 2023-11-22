cmake_minimum_required(VERSION 3.24)
project(parcialis)

set(CMAKE_CXX_STANDARD 17)

add_executable(parcialis main.cpp Book.h Library.h Library.cpp Book.cpp ../parcialis-szamtech/Video.h ../parcialis-szamtech/PlayList.h ../parcialis-szamtech/Video.cpp ../parcialis-szamtech/PlayList.cpp)
