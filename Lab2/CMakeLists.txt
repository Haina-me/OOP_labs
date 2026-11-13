cmake_minimum_required(VERSION 3.16) # Версія 4.2 ще не існує (актуальна зараз 3.x), краще лишити базову сумісність
project(Lab2 LANGUAGES CXX)


set(CMAKE_PREFIX_PATH "D:/Qt/6.12.0/msvc2022_64")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(Lab2
        main.cpp
        mainWindow.cpp
        mainWindow.h
        shape.h)

target_link_libraries(Lab2 PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
