set(BINARY ${CMAKE_PROJECT_NAME})

include_directories(parsers)
set(SOURCES main.cpp
    intentprovider.cpp
    intentproviderfactory.cpp
    parserfactory.cpp
    parsers/weatherparser.cpp
    parsers/calendarparser.cpp
    parsers/factparser.cpp
    )

add_executable(${BINARY}_bin ${SOURCES})
add_library(${BINARY}_lib SHARED ${SOURCES})
