cmake_minimum_required(VERSION 3.23)

# # # # # # # # # # # # # # # # # # # # # # #
#     Project name and version              #
# # # # # # # # # # # # # # # # # # # # # # #
project(WinShit LANGUAGES C)

set(WINSHIT_MAJOR_VERSION 0)
set(WINSHIT_MINOR_VERSION 1)
set(WINSHIT_PATCH_VERSION 0)
set(WINSHIT_VERSION
    ${WINSHIT_MAJOR_VERSION}.${WINSHIT_MINOR_VERSION}.${WINSHIT_PATCH_VERSION})
set(WINSHIT_VERSION_STRING "${WINSHIT_VERSION}")

# # # # # # # # # # # # # # # # # # # # # # #
#     Clangd setups                         #
# # # # # # # # # # # # # # # # # # # # # # #
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(CREATE_LINK
  "${CMAKE_BINARY_DIR}/compile_commands.json"
  "${CMAKE_SOURCE_DIR}/compile_commands.json"
  SYMBOLIC
)

# # # # # # # # # # # # # # # # # # # # # # #
#     Exec, libraries and properties        #
# # # # # # # # # # # # # # # # # # # # # # #
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.c)
add_executable(bundler ${PROJECT_SOURCE_DIR}/bundler.c)

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  VERSION ${STONE_VERSION} SOVERSION ${STONE_MAJOR_VERSION}
)

target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Debug>:DEBUG>)
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Release>:RELEASE>)

add_subdirectory(third-party)
