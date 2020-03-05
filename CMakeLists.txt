cmake_minimum_required(VERSION 3.15)
project(raycasting)

set(CMAKE_CXX_STANDARD 17)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
add_executable(raycasting main.cpp MainWindow.cpp MainWindow.h Utils.h Utils.cpp Ray.cpp Ray.h operators.h Line.cpp Line.h Light.cpp Light.h Scene.cpp Scene.h Obstacle.cpp Obstacle.h)
target_link_libraries(raycasting ${CONAN_LIBS})