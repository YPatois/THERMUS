#!/bin/bash -x
# This file is not distributed, it is used to test THERMUS

TESTDIR=`dirname -- "$( readlink -f -- "$0"; )"`
BASEDIR=`dirname $TESTDIR`

EXTRA_OPTIONS="$@"

SCRIPTDIR=$BASEDIR/scripts

$SCRIPTDIR/inplace_build.sh $EXTRA_OPTIONS

# Do not run tests if build failed
if [ $? -ne 0 ]; then
    echo "Build failed, aborting test"
    exit 1
fi

# Lets get back the thermus install variable while we can
`$BASEDIR/run_thermus --getenv`
# Trying to save that file before we delete it
cp $TESTDIR/warning_destructive_dev_test.sh /tmp/warning_destructive_dev_test.sh

# delete mostly everything, but the just generated install
$BASEDIR/warning_delete_lots.sh

# Now we can run the tests
#$THERMUS/share/doc/Thermus/tests/inplace_test.sh $THERMUS/bin/run_thermus

strace -ff -o with $THERMUS/bin/run_thermus -q -b

