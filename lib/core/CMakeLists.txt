include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(Math Math.cpp)
add_library(PVector PVector.cpp)
add_library(PApplet PApplet.cpp)

target_link_libraries(PApplet Math PVector)

link_directories(.)