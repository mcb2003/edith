add_library(editor editor.c)
target_include_directories(editor
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )
