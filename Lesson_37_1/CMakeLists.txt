cmake_minimum_required(VERSION 3.16)
project(Lesson37_1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Lesson37_1
        main.cpp design_37_1.ui CalcMainWindow.h)

target_link_libraries(Lesson37_1 PRIVATE Qt5::Widgets)

