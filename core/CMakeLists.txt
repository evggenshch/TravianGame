project(CORE_GAME_LIBRARY LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) # стандарт с++ 2017
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -Wextra -Wzero-as-null-pointer-constant -Winit-self -Wswitch-default -Wfloat-equal -Wno-unused-parameter -fPIC -march=native")
set(CMAKE_CXX_FLAGS_RELEASE "-O3") # включаем оптимизаци компилятора

SET(PROJECT_HEADERS_DIR include)
SET(PROJECT_SOURCES_DIR src)

FILE(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
FILE(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

add_library(core_lib ${SOURCES} ${HEADERS})
target_include_directories(core_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})