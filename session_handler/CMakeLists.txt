set(TARGET_TITLE session_handler)

add_library(${TARGET_TITLE}
   ${TARGET_TITLE}.cpp
   ${TARGET_TITLE}.h)

add_library(Backend::SessionHandler ALIAS ${TARGET_TITLE})

target_include_directories(${TARGET_TITLE}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${TARGET_TITLE}
    PUBLIC
        Backend::Fly
        Backend::Cell
)
