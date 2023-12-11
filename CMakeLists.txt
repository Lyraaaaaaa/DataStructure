
cmake_minimum_required(VERSION 3.26)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(Static_Array_Implementation Static_Array_Implementation_of_Sequential_List.c)
add_executable(Dynamic_Array_Implementation Dynamic_Array_Implementation_of_Sequential_List.c
        SIngly_Linked_List.c)
