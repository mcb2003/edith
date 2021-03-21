add_library(editor editor.c buffer.c)
target_include_directories(editor
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )
