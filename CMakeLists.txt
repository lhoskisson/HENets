project(HENets)

find_package(SEAL)
set(SOURCES test1.cpp layer.cpp dense.cpp cnpy/cnpy.cpp)

add_executable(test1 ${SOURCES})
target_link_libraries(test1 SEAL::seal)
