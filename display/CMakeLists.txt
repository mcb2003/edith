set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)

add_library(display display.c)
target_link_libraries(display ${CURSES_LIBRARIES})
target_include_directories(display
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CURSES_INCLUDE_DIR})
