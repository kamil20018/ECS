add_library(imgui)

target_sources(imgui
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/imconfig-SFML.h
    ${CMAKE_CURRENT_LIST_DIR}/imconfig.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui-SFML.h
    ${CMAKE_CURRENT_LIST_DIR}/imstb_truetype.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui_internal.h
    ${CMAKE_CURRENT_LIST_DIR}/imstb_textedit.h
    ${CMAKE_CURRENT_LIST_DIR}/imgui-SFML_export.h
    ${CMAKE_CURRENT_LIST_DIR}/imstb_rectpack.h
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/imgui.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_demo.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_draw.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_tables.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui-SFML.cpp
    ${CMAKE_CURRENT_LIST_DIR}/imgui_widgets.cpp
)

target_include_directories(imgui
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)