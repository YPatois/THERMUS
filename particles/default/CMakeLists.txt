# CMakeLists.txt in particles/default
FILE(GLOB PRTCLS *.txt)

install(FILES ${PRTCLS}  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}/particles/default)

