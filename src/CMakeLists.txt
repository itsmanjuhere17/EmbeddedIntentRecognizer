set(BINARY ${CMAKE_PROJECT_NAME})

include_directories(includes includes/parsers parsers)
set(SOURCES main.cpp
    intentprovider.cpp
    intentproviderfactory.cpp
    parserfactory.cpp
    parsers/weatherparser.cpp
    parsers/calendarparser.cpp
    parsers/factparser.cpp
    includes/IfIntentProvider.h
    includes/intentprovider.h
    includes/constants.h
    includes/intentproviderfactory.h
    includes/parserfactory.h
    includes/IfParser.h
    includes/parsers/weatherparser.h
    includes/parsers/calendarparser.h
    includes/parsers/factparser.h)

add_executable(${BINARY}_bin ${SOURCES})
add_library(${BINARY}_lib SHARED ${SOURCES})
