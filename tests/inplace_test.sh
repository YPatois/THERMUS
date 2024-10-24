#!/bin/bash -x
# Inplace test for THERMUS
# As we don't know where run_thermus is located, we need to pass it as an argument
RUN_THERMUS=$1

# Location of test files
TESTDIR=`dirname -- "$( readlink -f -- "$0"; )"`

# Remove old tests resulst
rm -f tests/results/*.txt

# Run test
# $THERMUS is not yet defined
# So the argument is single-quoted to avoid expansion
$RUN_THERMUS '$THERMUS/share/doc/Thermus/tests/all_predictions.C -b -q'
$RUN_THERMUS '$THERMUS/share/doc/Thermus/tests/lhc5020_fit_charm.C -b -q'

# If there are no results files, test failed
if compgen -G "tests/results/*.txt" > /dev/null; then
    echo "Some results files were found"
else
    echo "TEST FAILED: no results files were found"
    exit 1
fi

# Number of test files should match number of tests
nbf=`compgen -G "tests/results/*.txt" | wc -l`

# Number of expected files should match number of tests
nbe=`compgen -G "tests/results/*.txt" | wc -l`

# All tests will be performed, even if some failed, this is to ensure better debugging
NBF_FAILED=0
if [ $nbf -ne $nbe ]; then
  echo "TEST FAILED: number of expected files does not match number of results files"
  NBF_FAILED=1
fi

RES_FAILED=0
# For each file in the result directory, test if it's same as in the expected directory
for ff in `ls tests/results/*.txt`; do
  f=`basename $ff`
  diff tests/results/$f $TESTDIR/expected_results/$f
  if [ $? -ne 0 ]; then
    echo "TEST FAILED for file $f"
    RES_FAILED=1
  fi
done

if [ $NBF_FAILED -eq 1 ] || [ $RES_FAILED -eq 1 ]; then
  echo "TEST FAILED"
  exit 1
fi

echo "Test passed"
