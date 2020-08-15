cmake_minimum_required(VERSION 3.5)

project(IntentRecognizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(src)
include_directories(includes)
include_directories(includes/parsers)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)

