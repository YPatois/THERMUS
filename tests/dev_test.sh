#!/bin/bash -x
# This file is not distributed, it is used to test THERMUS
# before committing changes
TESTDIR=`dirname -- "$( readlink -f -- "$0"; )"`
BASEDIR=`dirname $TESTDIR`

EXTRA_OPTIONS="$@"

SCRIPTDIR=$BASEDIR/scripts

# To run (maybe) faster for tests
#export CXXFLAGS="-O2 -march=native"
#export CXXFLAGS="-ffp-contract=off"

$SCRIPTDIR/inplace_build.sh $EXTRA_OPTIONS

# Do not run tests if build failed
if [ $? -ne 0 ]; then
    echo "Build failed, aborting test"
    exit 1
fi

$TESTDIR/inplace_test.sh $BASEDIR/run_thermus

