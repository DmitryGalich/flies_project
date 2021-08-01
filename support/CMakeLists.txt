set(TARGET_TITLE support)

add_library(${TARGET_TITLE}
   ${TARGET_TITLE}.cpp
   ${TARGET_TITLE}.h)

add_library(Backend::Support ALIAS ${TARGET_TITLE})

target_include_directories(${TARGET_TITLE}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

