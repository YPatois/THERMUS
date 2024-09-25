# THERMUS
A Thermal Model Package for ROOT

Contacts
========

Thermus.Project@cern.ch
Thermus.Support@cern.ch

Contents
========

Directory THERMUS/ :

README      - file containing important information
LICENSE     - usage terms and conditions
functions   - functions needed for numerical calculations
include     - prototypes for constrains and models
main        - models and main classes
particles   - list of particles and decay properties
test        - exemples and basic tests

Environment variables
=====================

The environment variables ROOTSYS and THERMUS should be set and exported
respectively with the proper <pathnames> (checked by cmakethermus.sh):
    $ROOTSYS should point to the directory of the root installation
    $THERMUS should point to the directory containing the THERMUS code

Compiling THERMUS and running test programs
===========================================

Configuration and compilation should be done using CMake: source cmakethermus.sh
(Please note that the provided makefiles are not recommended).
For using THERMUS, a ROOT version >= 6 compiled from source is necessary:
you can obtain the source via: git clone http://root.cern.ch/git/root.git root
please look at cmakeroot.sh as an example for properly building and installing root
Note that a rootlogon.C loading THERMUS Shared Object (.so) libraries is also provided.


