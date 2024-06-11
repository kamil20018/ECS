add_executable(game Source.cpp)

add_subdirectory(stateManager)
add_subdirectory(ecs)

target_link_libraries(game
  PRIVATE
    ImGui-SFML::ImGui-SFML
    stateManager
    ecs
  )
target_sources(game
PRIVATE
  Game.cpp
  Simulation.cpp
PUBLIC
  Game.h
  Simulation.h
  )
