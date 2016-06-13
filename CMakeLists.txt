#for debug : cmake -DCMAKE_BUILD_TYPE=Debug /path/to/source
cmake_minimum_required(VERSION 2.6)
project(editdistance)

add_definitions(-std=c++11)

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
    
###


find_package( Boost REQUIRED )
include_directories("${PROJECT_BINARY_DIR}" ${CMAKE_CURRENT_BINARY_DIR} include)

add_executable(test_levenshtein Test/test_levenshtein.cpp)
target_link_libraries(test_levenshtein -lboost_unit_test_framework)

add_executable(test_normalized Test/test_normalized.cpp)
target_link_libraries(test_normalized -lboost_unit_test_framework)


## Installing the files

FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
INSTALL(FILES ${files} DESTINATION include/editDistance)
INSTALL(FILES editdistance-config.cmake DESTINATION lib/editdistance)


## If rpm wanted

SET(CPACK_GENERATOR "RPM")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Malcolm Mielle") #required
 
INCLUDE(CPack)

# get_cmake_property(_variableNames VARIABLES)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()
# install(TARGETS editdistance RUNTIME DESTINATION bin)
