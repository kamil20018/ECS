add_library(state "")

target_sources(state
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/StateManager.cpp
  PUBLIC
  
    ${CMAKE_CURRENT_LIST_DIR}/StateManager.h
    ${CMAKE_CURRENT_LIST_DIR}/State.h
  )

target_include_directories(state
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )