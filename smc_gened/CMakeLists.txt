project(lab1_generated)

include_directories(../lib/C++ ../src)

add_library(gen STATIC CheckStr_sm.h CheckStr_sm.cpp)

target_link_libraries(gen src)