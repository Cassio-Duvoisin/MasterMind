cmake_minimum_required(VERSION 3.0.0)
project(TrabFinal VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(./dirh)
add_executable(main dircpp/main.cpp dircpp/sequencia.cpp dircpp/resposta.cpp dircpp/tabuleiro.cpp dircpp/jogo.cpp)
set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17 -Wall -Wextra -Werror -Wshadow -Wconversion -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wnull-dereference")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)