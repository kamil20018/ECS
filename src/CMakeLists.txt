add_executable(game Source.cpp)

add_subdirectory(state)

target_link_libraries(game
  PRIVATE
    ImGui-SFML::ImGui-SFML
    state
  )
target_sources(game
PRIVATE
  Component.cpp
  System.cpp
  Scene.cpp
  Game.cpp
  Simulation.cpp
PUBLIC
  Component.hpp
  System.hpp
  Scene.hpp
  Registry.hpp
  Game.h
  Simulation.h
  Constants.hpp
  )
