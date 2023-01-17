file(GLOB_RECURSE SRC *.cpp *.hpp)
add_library(${PROJECT_NAME} STATIC ${SRC})
add_compile_definitions(
    LIB_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
    LIB_VERSION_MINOR=${PROJECT_VERSION_MINOR})
string(TIMESTAMP DATE "%Y%m%d")
string(TIMESTAMP TIME "%H%M%S")
target_compile_definitions(${PROJECT_NAME} PRIVATE DATESTAMP=${DATE} TIMESTAMP=${TIME})
target_precompile_headers(${PROJECT_NAME} PRIVATE <vector> <string> <memory>)
