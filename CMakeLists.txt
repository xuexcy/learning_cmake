cmake_minimum_required (VERSION 3.18)

project(learning_cmake)
set(learning_cmake_VERSION_MAJOR 1)
set(learning_cmake_VERSION_MINOR 0)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow HAVE_POW)

set(PROJECT_CONFIG_FILE_IN "${PROJECT_SOURCE_DIR}/config.h.in")
set(PROJECT_CONFIG_FILE_H "${PROJECT_BINARY_DIR}/config.h")
configure_file(
    ${PROJECT_CONFIG_FILE_IN}
    ${PROJECT_CONFIG_FILE_H}
)
# option (USE_MYMATH "Use provided math implementation" ON)

if (NOT HAVE_POW)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    set (EXTRA_LIBS ${EXTRA_LIBS} math_functions)
endif (NOT HAVE_POW)

aux_source_directory(. DIR_SRCS)


add_executable(learning_cmake main.cpp)
target_link_libraries(learning_cmake ${EXTRA_LIBS})


install (TARGETS learning_cmake DESTINATION bin)
install (FILES ${PROJECT_CONFIG_FILE_H} DESTINATION include)

enable_testing()
add_test(test_run learning_cmake 2 3)
add_test(test_usage learning_cmake)
set_tests_properties(test_usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")
set_tests_properties(test_run PROPERTIES PASS_REGULAR_EXPRESSION "is 8")

macro(do_test arg1 arg2 result)
    add_test(test_${arg1}_${arg2} learning_cmake ${arg1} ${arg2})
    set_tests_properties(test_${arg1}_${arg2} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

do_test(5 2 25)
do_test(5 3 125)

# CPack
include(InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${learning_cmake_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${learning_cmake_VERSION_MINOR}")
include (CPack)
