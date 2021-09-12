Project(lab1_sources)

include_directories(../lib/C++ ../smc_gened)

add_library(src STATIC Hash.cpp CheckStr.cpp)

target_link_libraries(src gen)