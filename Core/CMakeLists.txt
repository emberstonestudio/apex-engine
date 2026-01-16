file(GLOB_RECURSE CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp)
file(GLOB_RECURSE CORE_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h)

add_library(Core STATIC ${CORE_SOURCES} ${CORE_INCLUDES})
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_link_libraries(Core PUBLIC glfw glad glm::glm)

if (WIN32)
    target_link_libraries(Core PUBLIC opengl32)
endif()

if (UNIX AND NOT APPLE)
    target_link_libraries(Core PUBLIC GL)
endif()
