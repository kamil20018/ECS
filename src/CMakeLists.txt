add_executable(game Source.cpp)
  
add_subdirectory(imgui)

target_link_libraries(game
  PRIVATE
    imgui
    sfml-graphics
    sfml-window
    sfml-system
  )
target_sources(game
PRIVATE
  Component.cpp
  System.cpp
  Scene.cpp
  Game.cpp
  StateManager.cpp
  Simulation.cpp
PUBLIC
  Component.hpp
  System.hpp
  Scene.hpp
  Registry.hpp
  Game.h
  StateManager.h
  State.h
  Simulation.h
  Constants.hpp
  )
