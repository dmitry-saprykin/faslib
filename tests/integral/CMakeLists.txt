add_executable(test_integral test_integral.cpp)
add_executable(test_comparisons test_comparisons.cpp)
add_executable(test_arithmetic test_arithmetic.cpp)
add_executable(test_logical_op test_logical_op.cpp)

add_test(integral             test_integral)
add_test(integral_comparisons test_comparisons)
add_test(integral_arithmetic  test_arithmetic)
add_test(integral_logical_op  test_logical_op)


