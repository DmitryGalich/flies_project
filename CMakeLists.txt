cmake_minimum_required(VERSION 3.14)

project(flies_project LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick QuickControls2 REQUIRED)
find_package (Threads REQUIRED)

add_subdirectory(support)
add_subdirectory(fly)
add_subdirectory(cell)
add_subdirectory(flies_model)
add_subdirectory(board_model)
add_subdirectory(session_handler)
add_subdirectory(abstract_qml_handler)
add_subdirectory(qml_engine_configurator)

add_executable(${PROJECT_NAME}
      main.cpp
      qml/qml.qrc
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE 
        Backend::SessionHandler
        UI::QMLEngineConfigurator

	Qt5::Core 
        Qt5::Quick
        Qt5::QuickControls2)
