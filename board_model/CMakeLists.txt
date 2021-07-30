set(TARGET_TITLE board_model)

add_library(${TARGET_TITLE}
   ${TARGET_TITLE}.cpp
   ${TARGET_TITLE}.h)

add_library(UI::BoardModel ALIAS ${TARGET_TITLE})

target_include_directories(${TARGET_TITLE}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${TARGET_TITLE}
   PRIVATE
     Qt5::Core

   PUBLIC
    Backend::Cell
    UI::AbstractQmlHandler
)
