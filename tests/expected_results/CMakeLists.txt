# CMakeLists.txt in test/expected_results

if(${CMAKE_SYSTEM} MATCHES Darwin)
    install(FILES current_fit_lhc5020_fit_test_arm.txt  RENAME current_fit_lhc5020_fit_test.txt
        DESTINATION ${CMAKE_INSTALL_DOCDIR}/tests/expected_results)
else()
    install(FILES current_fit_lhc5020_fit_test_x86_64.txt  RENAME current_fit_lhc5020_fit_test.txt
        DESTINATION ${CMAKE_INSTALL_DOCDIR}/tests/expected_results)
endif()

install(FILES result_0.txt result_1.txt DESTINATION ${CMAKE_INSTALL_DOCDIR}/tests/expected_results)

