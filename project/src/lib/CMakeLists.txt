file(GLOB_RECURSE SRC *.cpp *.hpp)
add_library(${PROJECT_NAME} STATIC ${SRC})

find_package(cli11 2.3.0 REQUIRED)
find_package(nlohmann_json 3.11.2 REQUIRED)

string(TIMESTAMP DATE "%Y%m%d")
string(TIMESTAMP TIME "%H%M%S")
target_compile_definitions(${PROJECT_NAME} PRIVATE
        LIB_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
        LIB_VERSION_MINOR=${PROJECT_VERSION_MINOR}
        DATESTAMP=${DATE}
        TIMESTAMP=${TIME})

target_link_libraries(${PROJECT_NAME}
        CLI11::CLI11
        nlohmann_json::nlohmann_json)