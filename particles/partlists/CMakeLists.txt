# CMakeLists.txt in particles/partlists
FILE(GLOB PRTCLS *.txt)

install(FILES ${PRTCLS}  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}/particles/partlists)

