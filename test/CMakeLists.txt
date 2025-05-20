add_subdirectory(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runTests integradora_test.cpp ../src/integradora.cpp)
target_link_libraries(runTests gtest gtest_main)

add_test(NAME runTests COMMAND runTests)
