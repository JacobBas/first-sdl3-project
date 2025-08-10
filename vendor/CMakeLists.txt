add_subdirectory(SDL)
add_subdirectory(SDL_image)

add_library(vendor INTERFACE)

target_link_libraries(vendor INTERFACE SDL3::SDL3 SDL3_image::SDL3_image)
target_include_directories(
  vendor INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/SDL/include"
                   "${CMAKE_CURRENT_SOURCE_DIR}/SDL_image/include")
