cmake_minimum_required(VERSION 2.8)
project(Novelua)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(Novelua ${SOURCE_FILES})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
set(SDL2PP_WITH_IMAGE ON)
set(SDL2PP_WITH_TTF ON)
add_subdirectory(external/SDL2pp)
add_subdirectory(external/Selene)

include_directories(
    ${SDL2_INCLUDE_DIR}
    ${SDL_IMAGE_INCLUDE_DIRS}
    ${SDL_TTF_INCLUDE_DIRS}
    ${SDL2PP_INCLUDE_DIRS}
    ${SELENE_INCLUDE_DIRS}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2_LIBRARY}
    ${SDL_IMAGE_LIBRARIES}
    ${SDL_TTF_LIBRARIES}
    ${SDL2PP_LIBRARIES}
    ${LUA53_LIBRARIES}
    -ldl
)
