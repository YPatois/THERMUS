# CMakeLists.txt in functions

FILE(GLOB SRCFILES *.cxx)

add_library(Functions SHARED ${SRCFILES})
target_link_libraries(Functions ROOT::Minuit GSL::gsl GSL::gslcblas)
target_compile_options(Functions PUBLIC -Wall -Wextra)

install(TARGETS Functions)
