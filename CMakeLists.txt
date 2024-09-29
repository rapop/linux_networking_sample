project(networking)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME}_server src/server.cpp)
add_executable(${PROJECT_NAME}_client src/client.cpp)