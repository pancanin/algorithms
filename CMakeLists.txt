cmake_minimum_required(VERSION 3.5.1)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

project(algorithms LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
	${DIR}/main.cpp
	${DIR}/softuni-algo/recursion/Recursion.h
	${DIR}/softuni-algo/recursion/Recursion.cpp
	${DIR}/softuni-algo/sorting/Sorting.h
	${DIR}/softuni-algo/sorting/Sorting.cpp
	${DIR}/softuni-algo/graphs/ConnectedComponents.h
	${DIR}/softuni-algo/graphs/ConnectedComponents.cpp
	${DIR}/softuni-algo/graphs/Graph.h
	${DIR}/softuni-algo/graphs/Graph.cpp
	${DIR}/softuni-algo/graphs/Node.h
	${DIR}/helpers/Helpers.h
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_include_directories(${PROJECT_NAME} PRIVATE ${DIR})