set(TARGET_TITLE fly)

add_library(${TARGET_TITLE}
   ${TARGET_TITLE}.cpp
   flies_holder.cpp
   ${TARGET_TITLE}.h)

add_library(Backend::Fly ALIAS ${TARGET_TITLE})

target_include_directories(${TARGET_TITLE}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${TARGET_TITLE}
   PUBLIC
     Qt5::Core
     Backend::Support)
