cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.5.1/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Qml
        REQUIRED)

add_executable(untitled sources.qrc main.cpp windows/mainwindow.h windows/mainwindow.cpp Entity/Entity.cpp Entity/Entity.h
        Entity/NPC.cpp Entity/NPC.h Entity/Person.cpp Entity/Person.h workDirrectory/Controller.cpp
        workDirrectory/Controller.h "LocationsAndObjects/Location.cpp" "LocationsAndObjects/Location.h"
        "LocationsAndObjects/Block.cpp" "LocationsAndObjects/Block.h" "LocationsAndObjects/Object.cpp"
        "LocationsAndObjects/Object.h" workDirrectory/Dialog.cpp workDirrectory/Dialog.h "LocationsAndObjects/Item.cpp" "LocationsAndObjects/Item.h"
        workDirrectory/Inventory.cpp workDirrectory/Inventory.h windows/AnotherWindow.cpp windows/AnotherWindow.h level/Level.cpp level/Level.h
        LocationsAndObjects/Portal.cpp LocationsAndObjects/Portal.h windows/SettingsWindow.cpp windows/SettingsWindow.h
        music/Music.cpp music/Music.h Event.cpp Event.h)

find_package(Qt6 REQUIRED COMPONENTS Gui)

target_link_libraries(untitled
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Qml
        )

set(RESOURCE_FILES
        images/tmp.jpg)

set_target_properties(untitled PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_FRAMEWORK_IDENTIFIER org.cmake.ExecutableTarget
        RESOURCE "${RESOURCE_FILES}")

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
