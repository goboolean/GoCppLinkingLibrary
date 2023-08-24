cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(testcode1)
project(testcode2)

find_package(Torch REQUIRED)
find_path( TORCH_INCLUDE_DIR torch/torch.h
           PATHS 
           /home/jepetolee/libtorch/include/torch/csrc/api/include/
           NO_DEFAULT_PATH )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")   

            

add_library(techindicator SHARED  
            /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/TechnicalIndicator.h
              /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/TechnicalIndicator.cpp
              /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.h
              /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp)


add_library(BaseFunctionz SHARED  
              /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.h
              /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp)

target_link_libraries( techindicator "${TORCH_LIBRARIES}")

target_link_libraries( BaseFunctionz "${TORCH_LIBRARIES}")

add_executable(testcode1 TestTechnicalIndicator.cpp )
add_executable(testcode2 TestLogisticRegression.cpp /home/jepetolee/GoCppLinkingLibrary/ML/LogisticRegression.h /home/jepetolee/GoCppLinkingLibrary/ML/LogisticRegression.cpp )
target_link_libraries(techindicator BaseFunctionz)

target_link_libraries(testcode1 "${TORCH_LIBRARIES}" techindicator BaseFunctionz)
target_link_libraries(testcode2 "${TORCH_LIBRARIES}" )


set_property(TARGET testcode1 PROPERTY CXX_STANDARD 17)
set_property(TARGET testcode2 PROPERTY CXX_STANDARD 17)

