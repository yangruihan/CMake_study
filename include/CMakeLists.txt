add_executable (MakeTable MakeTable.cpp)

add_custom_command (
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(MMath mmath.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

install (TARGETS MMath DESTINATION bin)
install (FILES mmath.h DESTINATION include)

