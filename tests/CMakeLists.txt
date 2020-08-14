set(BINARY ${CMAKE_PROJECT_NAME}_tst)

set(SOURCES main.cpp)

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
