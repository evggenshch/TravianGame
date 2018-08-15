cmake_minimum_required(VERSION 3.10)

project(evgenij-scherbakov-game LANGUAGES CXX) # имя проекта и язык используемый в проекте (c++)

set(CMAKE_CXX_STANDARD 17) # стандарт с++ 2017
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wswitch-default -Wfloat-equal -lncursesw -D_XOPEN_SOURCE_EXTENDED -Wno-unused-parameter -fPIC -march=native -pthread -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3") # включаем оптимизаци компилятора

# -Wdangling-else

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  # добавляем дебажные символы в бинарный файл для дебага

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake") # добавляем дополнительные модули CMake

# Подключаем библиотеку ncurses
find_package(Ncursesw REQUIRED)
include_directories(${CURSES_INCLUDE_PATH})

SET(PROJECT_HEADERS_DIR travian-game/include)
SET(PROJECT_SOURCES_DIR travian-game/src)

FILE(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
FILE(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

# add_executable(${PROJECT_NAME} travian-game/src/main.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

#add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

# линкуем библиотеки к проекту
add_subdirectory(core)
set_target_properties(core_lib PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(evgenij-scherbakov-game core_lib  stdc++fs)

target_link_libraries(${PROJECT_NAME} ${CURSES_NCURSESW_LIBRARY} stdc++fs)

#

include(CppLint)
ADD_STYLE_CHECK_TARGET(lint ${PROJECT_HEADERS_DIR} ${PROJECT_SOURCES_DIR})

# -lc++experimental -lstdc++fs