include_directories("${PROJECT_SOURCE_DIR}/include")

#file(GLOB List.cpp 
#"${PROJECT_SOURCE_DIR}/lib/data/List.cpp")

add_subdirectory(core)

link_libraries(PApplet)
add_executable(p5cpp test.cpp)