Project(lab1_sources)

include_directories(../lib/C++ ../gened)

add_library(src STATIC Hash.cpp CheckStr.cpp)

target_link_libraries(src gen)