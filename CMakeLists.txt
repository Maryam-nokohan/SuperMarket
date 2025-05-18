cmake_minimum_required(VERSION 3.10)
project(superamrket)
include_directories(include)
set(SOURCES 
src/Bank.cpp 
src/Currency.cpp
src/EUR.cpp
src/IRR.cpp
src/USD.cpp
src/Fruit.cpp
src/Item.cpp
src/Seasoning.cpp
src/Snack.cpp
src/Shop.cpp
main.cpp
)
add_executable(app ${SOURCES})
