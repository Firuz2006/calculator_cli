cmake_minimum_required(VERSION 4.0)
project(calculator_cli)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        cli11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG v2.4.1
)

FetchContent_MakeAvailable(cli11)


add_executable(calculator_cli main.cpp)


target_link_libraries(calculator_cli CLI11::CLI11)