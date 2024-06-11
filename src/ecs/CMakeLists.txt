add_library(ecs "")

target_sources(ecs
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Component.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Scene.cpp
  PUBLIC
  
    ${CMAKE_CURRENT_LIST_DIR}/Component.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Registry.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Scene.hpp
  )

target_include_directories(ecs
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )