project(seal_tests)

find_package(SEAL)
find_package(MNIST PATHS .)
set(SOURCES basic_MNIST_CNN.cpp cnpy/cnpy.cpp)

#add_executable(test1 test1.cpp)
#target_link_libraries(test1 SEAL::seal)

#add_executable(test2 test2.cpp)
#target_link_libraries(test2 SEAL::seal)

#add_executable(test3 test3.cpp)
#target_link_libraries(test3 SEAL::seal)

#add_executable(test4 test4.cpp)
#target_link_libraries(test4 SEAL::seal)

#add_executable(test5 test5.cpp)
#target_link_libraries(test5 SEAL::seal)

#add_executable(test6 test6.cpp)
#target_link_libraries(test6 SEAL::seal)

#add_executable(test7 test7.cpp cnpy/cnpy.cpp)

add_executable(test8 test8.cpp cnpy/cnpy.cpp)
target_link_libraries(test8 SEAL::seal)

#include_directories(${MNIST_INCLUDE_DIR})
#add_executable(HE_MNIST_CNN ${SOURCES})
#target_link_libraries(HE_MNIST_CNN SEAL::seal)
#target_compile_definitions(HE_MNIST_CNN PRIVATE MNIST_DATA_LOCATION="${MNIST_DATA_DIR}")
