file(GLOB_RECURSE SRC *.cpp *.hpp)
set(TEST_APP ${PROJECT_NAME}-test)

find_package(catch2 3.1.0 REQUIRED)
find_package(fakeit 2.3.2 REQUIRED)

add_executable(${TEST_APP} ${SRC})

target_link_libraries(${TEST_APP}
        ${PROJECT_NAME}
        Catch2::Catch2WithMain
        fakeit::fakeit)
