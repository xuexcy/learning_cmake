aux_source_directory(. DIR_LIB_SRCS)
#add_library(math_functions math_functions.h match_functions.cpp)
add_library(math_functions ${DIR_LIB_SRCS})

install (TARGETS math_functions DESTINATION lib)
install (FILES math_functions.h DESTINATION include)
