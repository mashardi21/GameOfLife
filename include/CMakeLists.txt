add_library(
    board
    board.hpp
    board.cpp
)

target_include_directories(
    board
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)