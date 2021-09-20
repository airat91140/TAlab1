cmake_minimum_required(VERSION 3.16)
project(lab1)

set(CMAKE_CXX_STANDARD 20)
set(smc_flags "-graph" "-glevel 2" "dot" "-T" "png" "-table")

execute_process(COMMAND java "-jar" "${PROJECT_SOURCE_DIR}/bin/Smc.jar" "-c++" "-d" ${PROJECT_SOURCE_DIR}/smc_gened "${PROJECT_SOURCE_DIR}/src/CheckStr.sm"
        RESULT_VARIABLE res
        OUTPUT_VARIABLE out
        ERROR_VARIABLE  err
        )

message("${err}")

include_directories(src smc_gened lib/C++)

add_subdirectory(smc_gened)
add_subdirectory(src)

add_executable(lab1 main.cpp)
target_link_libraries(lab1 gen src)


