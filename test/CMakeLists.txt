cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(testcode1)
find_package(Torch REQUIRED)
find_path( TORCH_INCLUDE_DIR torch/torch.h
           PATHS 
           /home/jepetolee/libtorch/include/torch/csrc/api/include/
           NO_DEFAULT_PATH )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")   

add_library(techindicator STATIC  /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/TechnicalIndicator.hpp
               /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/TechnicalIndicator.cc )
      
target_link_libraries( techindicator "${TORCH_LIBRARIES}")

add_executable(testcode1 TestTechnicalIndicator.cc
               /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/TechnicalIndicator.hpp
               /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/TechnicalIndicator.cc )

target_link_libraries(testcode1 "${TORCH_LIBRARIES}")

set_property(TARGET testcode1 PROPERTY CXX_STANDARD 17)

if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET testcode1
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:testcode1>)
endif (MSVC)