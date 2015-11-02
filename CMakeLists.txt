cmake_minimum_required(VERSION 2.6)
project(editdistance)

add_executable(editdistance main.cpp)

install(TARGETS editdistance RUNTIME DESTINATION bin)
