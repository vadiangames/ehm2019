cmake_minimum_required( VERSION 3.2 )

project( EHM2019 )

include_directories("${PROJECT_SOURCE_DIR}/include")
link_directories("${PROJECT_SOURCE_DIR}/lib")

add_subdirectory(src)
add_subdirectory(tests)