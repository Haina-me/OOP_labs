cmake_minimum_required(VERSION 3.16)
project(Lab1) # Назва вашого проєкту

# Вказуємо стандарт C++ (Qt6 вимагає мінімум C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Вмикаємо автоматичну обробку Qt-файлів (це обов'язково для роботи вікон)
set(CMAKE_AUTOMOC ON) # Для макросів Q_OBJECT
set(CMAKE_AUTORCC ON) # Для файлів ресурсів (картинок, іконок)
set(CMAKE_AUTOUIC ON) # Для файлів інтерфейсу .ui (якщо є)

# Шукаємо бібліотеку Qt6 (модуль Widgets, бо ми використовуємо вікна)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# ДОДАЄМО ВСІ ФАЙЛИ НАШОГО ПРОЄКТУ (саме тут була ваша помилка)
add_executable(Lab1
        main.cpp
        mainwindow.cpp
        mainwindow.h
        firstWindow.h
        firstWindow.cpp
        secondWindow.cpp
        secondWindow.h
        # Якщо ви використовуєте графічний дизайнер для вікна, розкоментуйте рядок нижче:
        # mainwindow.ui
)

# Підключаємо бібліотеку Qt до нашої програми
target_link_libraries(Lab1 PRIVATE Qt6::Widgets)