cmake_minimum_required(VERSION 3.10)  # Минимальная версия CMake
project(Laba_17)  # Имя проекта

set(CMAKE_CXX_STANDARD 17)  # Использование стандарта C++17
set(CMAKE_CXX_STANDARD_REQUIRED True)  # Обязательное использование стандарта

# Добавление исполняемого файла
add_executable(Laba_17 main.cpp)