set(BINARY ${CMAKE_PROJECT_NAME})

include_directories(includes)
set(SOURCES main.cpp intentprovider.cpp includes/IfIntentProvider.h includes/intentprovider.h includes/constants.h)
add_executable(${BINARY}_bin ${SOURCES})
