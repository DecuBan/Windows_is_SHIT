target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib-5.5/include
    m
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib-5.5/lib/libraylib.a
    m
)

target_include_directories(
    bundler
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib-5.5/include
)

target_link_libraries(
    bundler
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib-5.5/lib/libraylib.a
    m
)
