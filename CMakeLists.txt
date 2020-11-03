cmake_minimum_required(VERSION 3.16)

project(kEasyWebGui)
enable_language(ASM C CXX)

option(target_test "Signalizes if test cases shall be built." ON)

add_subdirectory(libkmbd)
