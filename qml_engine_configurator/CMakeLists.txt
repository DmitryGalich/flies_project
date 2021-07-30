set(TARGET_TITLE qml_engine_configurator)

add_library(${TARGET_TITLE}
   ${TARGET_TITLE}.cpp
   ${TARGET_TITLE}.h)

add_library(UI::QMLEngineConfigurator ALIAS ${TARGET_TITLE})

target_include_directories(${TARGET_TITLE}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${TARGET_TITLE}
    PRIVATE
        Qt5::Core
        Qt5::Qml

    PUBLIC
        UI::FliesModel
        UI::BoardModel
        Backend::DataHolder
)
