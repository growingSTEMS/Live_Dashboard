project(Live_Dashboard_Logic)

set(src
  src/LiveDashboard.cpp
)
set(inc
  inc/LiveDashboard.h
)

add_library(${PROJECT_NAME} STATIC ${src} ${inc})

target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE OutputManager
)
