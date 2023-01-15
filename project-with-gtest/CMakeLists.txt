cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 20)
project(stub VERSION 0.0.1)

set(CONAN_FILE ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
message(CONAN_FILE=${CONAN_FILE})

if (EXISTS ${CONAN_FILE})
    include(${CONAN_FILE})
    conan_basic_setup()
else ()
    message(WARNING "The file ${CONAN_FILE} doesn't exist, you have to run conan install first")
endif ()

include_directories(src/lib)
add_subdirectory(src)
