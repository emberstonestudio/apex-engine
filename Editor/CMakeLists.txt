file(GLOB_RECURSE EDITOR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp)
file(GLOB_RECURSE EDITOR_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h)

add_executable(Editor ${EDITOR_SOURCES} ${EDITOR_INCLUDES})
target_include_directories(Editor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_link_libraries(Editor PRIVATE Core imgui)