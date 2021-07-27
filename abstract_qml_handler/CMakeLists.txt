set(TARGET_TITLE abstract_qml_handler)

add_library(${TARGET_TITLE}
   ${TARGET_TITLE}.cpp
   ${TARGET_TITLE}.h)

add_library(UI::AbstractQmlHandler ALIAS ${TARGET_TITLE})

target_include_directories(${TARGET_TITLE}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})


