#!/bin/bash -e
# checked on 24/07/2023 with root-v6-28-04 (B.H.)
echo $THERMUS
export BASEDIR=$(pwd)
#
if [[ (`export | egrep "THERMUS\=" | wc -l` == 0 ) || ( ! $THERMUS ) ]]
then echo 'first make sure the shell variable ${THERMUS} is set to the THERMUS code directory and properly exported'
else
#
cd $THERMUS
rm -rf build
mkdir build
cd build
#cmake -Wdev -debug-output -DCMAKE_VERBOSE_MAKEFILE=ON ..
cmake -Wdev --debug-output -DCMAKE_VERBOSE_MAKEFILE=ON ..
#
cmake --build . -- -j10
cd $BASEDIR
#
fi
