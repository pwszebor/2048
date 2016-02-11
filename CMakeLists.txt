    cmake_minimum_required(VERSION 2.8)
    project(2048)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -std=c++11")

    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)

    find_package(Qt5Widgets REQUIRED)

    set(SOURCE_FILES
            src/main.cc
            src/mainWindow.cc
            src/game.cc
            src/gameLogic.cc
            src/tile.cc)

    set(HEADERS
            src/mainWindow.h
            src/game.h
            src/gameLogic.h
            src/subject.h
            src/observer.h
            src/tile.h)

    set(UIS
            ui/mainWindow.ui)

    set(RESOURCES
            resources/images.qrc)

    qt5_wrap_ui(GENERATED_SOURCES ${UIS})

    add_executable(2048 ${SOURCE_FILES} ${GENERATED_SOURCES} ${RESOURCES})
    target_link_libraries(2048 Qt5::Widgets)