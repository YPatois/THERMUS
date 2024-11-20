#!/bin/bash -x
# This file is not distributed, it is used to test THERMUS

TESTDIR=`dirname -- "$( readlink -f -- "$0"; )"`
BASEDIR=`dirname $TESTDIR`

EXTRA_OPTIONS="$@"

SCRIPTDIR=$BASEDIR/scripts
# delete mostly everything, but the just generated install
rm -rf $BASEDIR/build
rm -rf $BASEDIR/cmake
rm -rf $BASEDIR/doc
rm -rf $BASEDIR/functions
rm -rf $BASEDIR/include
rm -rf $BASEDIR/main
rm -rf $BASEDIR/particles 
rm -rf $BASEDIR/scripts
rm -rf $BASEDIR/tests
rm -f $BASEDIR/run_thermus

