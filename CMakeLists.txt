cmake_minimum_required(VERSION 3.20)
project(lab1)

set(CMAKE_CXX_STANDARD 17)

execute_process(COMMAND java "-jar" "${PROJECT_SOURCE_DIR}/bin/Smc.jar" "-c++" "-d" ${PROJECT_SOURCE_DIR}/gened "${PROJECT_SOURCE_DIR}/src/CheckStr.sm"
        RESULT_VARIABLE res
        OUTPUT_VARIABLE out
        ERROR_VARIABLE  err
        )

message("${err}")

include_directories(src gened lib/C++)

add_subdirectory(gened)
add_subdirectory(src)

add_executable(lab1 main.cpp)
target_link_libraries(lab1 gen src)


