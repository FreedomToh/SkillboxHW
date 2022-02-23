cmake_minimum_required(VERSION 3.16)
project(Lesson37_1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(Qt5_DIR D:/Programs/QT/5.12.12/mingw73_32/lib/cmake/Qt5)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Lesson37_1
        main.cpp design_37_1.ui cmake-build-debug/CalcMainWindow.h)

target_link_libraries(Lesson37_1 PRIVATE Qt5::Widgets)

