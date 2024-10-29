# CMakeLists.txt in test

install(FILES all_predictions.C prediction.txt lhc5020_fit_charm.C lhc5020_final_0_single_charm.txt DESTINATION ${CMAKE_INSTALL_DOCDIR}/tests)
install(PROGRAMS inplace_test.sh DESTINATION ${CMAKE_INSTALL_DOCDIR}/tests)

add_executable(lhc5020_fit_charm lhc5020_fit_charm.C)
target_link_libraries(lhc5020_fit_charm ${ROOT_LIBRARIES} THERMUS Functions)
target_compile_options(lhc5020_fit_charm PUBLIC -Wall -Wextra)

add_subdirectory(expected_results)

