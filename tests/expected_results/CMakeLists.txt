# CMakeLists.txt in test/expected_results

if(${CMAKE_SYSTEM} MATCHES Darwin)
    SET(FLIST result_0.txt result_1.txt current_fit_lhc5020_fit_test_arm.txt)
else(${CMAKE_SYSTEM} MATCHES Darwin)
    SET(FLIST result_0.txt result_1.txt current_fit_lhc5020_fit_test.txt)
endif(${CMAKE_SYSTEM} MATCHES Darwin)


install(FILES result_0.txt result_1.txt current_fit_lhc5020_fit_test.txt DESTINATION ${CMAKE_INSTALL_DOCDIR}/tests/expected_results)

