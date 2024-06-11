add_executable(game Source.cpp)

add_subdirectory(state)
add_subdirectory(ecs)

target_link_libraries(game
  PRIVATE
    ImGui-SFML::ImGui-SFML
    state
    ecs
  )
target_sources(game
PRIVATE
  System.cpp
  Game.cpp
  Simulation.cpp
PUBLIC
  System.hpp
  Game.h
  Simulation.h
  Constants.hpp
  )
