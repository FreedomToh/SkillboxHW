cmake_minimum_required(VERSION 3.16)
project(Lesson38_3 LANGUAGES CXX)

set(Qt5Core_DIR "C:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Core")
set(Qt5_DIR "C:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5")
set(QT_QMAKE_EXECUTABLE "C:/Qt/5.15.2/mingw81_64/bin/qmake.exe")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(Lesson38_3 main.cpp)

target_link_libraries(Lesson38_3 PRIVATE Qt5::Core Qt5::Widgets)