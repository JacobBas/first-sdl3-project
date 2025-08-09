add_subdirectory(SDL)

add_library(vendor INTERFACE)

target_link_libraries(vendor INTERFACE SDL3::SDL3)
target_include_directories(vendor INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/SDL/include")
