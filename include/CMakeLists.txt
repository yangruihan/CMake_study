add_library(MMath mmath.cpp)

install (TARGETS MMath DESTINATION bin)
install (FILES mmath.h DESTINATION include)

