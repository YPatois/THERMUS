# CMakeLists.txt in test/expected_results

if(${CMAKE_SYSTEM} MATCHES Darwin)
    file(RENAME current_fit_lhc5020_fit_test_arm.txt current_fit_lhc5020_fit_test.txt)
else(${CMAKE_SYSTEM} MATCHES Darwin)
    file(RENAME current_fit_lhc5020_fit_test_x86_64.txt current_fit_lhc5020_fit_test.txt)
endif(${CMAKE_SYSTEM} MATCHES Darwin)


install(FILES result_0.txt result_1.txt current_fit_lhc5020_fit_test.txt DESTINATION ${CMAKE_INSTALL_DOCDIR}/tests/expected_results)

