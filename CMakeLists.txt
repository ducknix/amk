cmake_minimum_required(VERSION 3.28)
project(amk)

set(SRC src/main.cxx)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost COMPONENTS program_options REQUIRED)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} Boost::program_options)