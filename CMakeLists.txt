cmake_minimum_required(VERSION 3.27)
project(Programacion_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programacion_3 Test.cpp)
add_executable(Template Templates/template.cpp)
add_executable(TemplateEj1 Templates/ejercicio1.cpp)
add_executable(TemplateEj2 Templates/ejercicio2.cpp)
add_executable(Algoritmos "Libreria Estandar/Algoritmos.cpp")
add_executable(Hilos Hilos/Ejercicios.cpp)
add_executable(Hilos-binary-search Hilos/busqueda_binaria_paralela.cpp)
