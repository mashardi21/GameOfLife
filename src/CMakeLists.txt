find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRECTORIES})

add_executable(GameOfLife main.cpp)
target_link_libraries(GameOfLife PRIVATE board ${CURSES_LIBRARIES})