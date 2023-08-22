cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(TestTechnicalIndicator)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(test TestTechnicalIndicator)
target_link_libraries(test "${TORCH_LIBRARIES}")
target_link_libraries(test "${home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator}")
set_property(TARGET test PROPERTY CXX_STANDARD 17)
include_directories("/home/jepetolee/GoCppLinkingLibrary")
if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET test
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:test>)
endif (MSVC)