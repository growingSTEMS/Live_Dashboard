project(Live_Dashboard_Gui)

#setup Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5Widgets REQUIRED)


set(src src/main.cpp
        src/MainWindow.cpp
        src/GuiNetworkManager.cpp
)
set(inc inc/MainWindow.h
        inc/GuiNetworkManager.h
)
set(forms inc/MainWindow.ui
)

add_executable(${PROJECT_NAME} ${src} ${inc} ${forms})

target_include_directories(${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_LIST_DIR}/inc
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE Live_Dashboard_Logic
  PRIVATE Qt5::Widgets
)
