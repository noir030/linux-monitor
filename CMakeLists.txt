cmake_minimum_required(VERSION 3.10)

project(LinuxMonitor)

set(CMAKE_CXX_STANDARD 17)

add_executable(linux-monitor src/main.cpp src/info.cpp src/cpu.cpp src/ram.cpp)

target_include_directories(linux-monitor PUBLIC ${PROJECT_SOURCE_DIR}/include)