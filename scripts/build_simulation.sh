#!/bin/bash

execDir=$(dirname $0)
cd $execDir

Target=simulation
build_mode="Debug"
clean_build="false"

###########################################################################
# Test if we have the correct getopt
###########################################################################
getopt --test > /dev/null
if [[ $? -ne 4 ]]; then
        echo "The version of getopt in use is wrong, the installer needs to be updated"
fi

###########################################################################
# Parse the options
###########################################################################

SHORT=h,d,r,f,t:,
LONG=help,debug,release,force,target:

PARSED=`getopt --options $SHORT --longoptions $LONG --name "$0" -- "$@"`
if [[ $? -ne 0 ]]; then
    echo "Parsing otions failed Err no. 1"
    exit 1
fi

eval set -- "$PARSED"

while true; do
    case "$1" in
        -h|--help) print_help shift exit ;;
        -d|--debug) build_mode="Debug" shift exit ;;
        -r|--release) build_mode="Release" shift exit ;;
        -f|--force) cleab_build="true" shift exit ;;
        -t|--target) Target="$2" shift 2 exit ;;
        --) 
         shift 
         break 
         ;; #Running without options
        *) echo "Parsing option failed Err no. 2" && exit 1 ;;
    esac
done

if [[ $# -ne 0 ]]; then
   echo "Too many arguments provided"
   print_help
   exit 1
fi


build_dir="$PWD/../../simulation_build_$build_mode"
install_dir="$PWD/../../simulation_install_$build_mode"
src_dir="$PWD/../."
generator="Unix Makefiles"


if [ "$clean_build" == "true" ]; then
    echo "Cleaning the build directory"
    if [ -d "$build_dir" ]; then
        rm -rf $build_dir
    fi
    if [ -d "$install_dir" ]; then
        rm -rf $install_dir
    fi
fi

if [ ! -d "$build_dir" ]; then
    mkdir -p $build_dir
fi
if [ ! -d "$install_dir" ]; then
    mkdir -p $install_dir
fi

cmake_log="$PWD/../../cmake_${build_mode}.log"
make_log="$PWD/../../make_${build_mode}.log"
make_install_log="$PWD/../../make_install_${build_mode}.log"

rm -rf $cmake_log $make_log $make_install_log

echo  "------------------------------------------------------"
echo  "Starting the build of $Target in $build_mode with params:"
echo  "Source dir: $src_dir"
echo  "Build dir: $build_dir"
echo  "Install dir: $install_dir"
echo  "Build mode: $build_mode"
echo  "Clean build: $clean_build"
echo  "------------------------------------------------------"
echo  "Cmake log: $cmake_log"
echo  "Make log: $make_log"
echo  "Make install log: $make_install_log"

cd $build_dir

time_start=$(date +"%N")
cmake \
        -DCMAKE_BUILD_TYPE=${build_mode} \
        -G"$generator" \
        ${src_dir} &> $cmake_log

if [ $? -ne 0 ]; then
    echo "Cmake error: see $cmake_log for more info"
    exit 1
fi

time_cmake_stop=$(date +"%N")
time_cmake=$(((time_cmake_stop-time_start)/1000000))

echo "Cmake complete in $time_cmake mseconds, starting make"

make -j 3 &> $make_log

if [ $? -ne 0 ]; then
    echo "Make error: see $make_log for more info"
fi

time_make_stop=$(date +"%N")
time_make=$(((time_make_stop-time_cmake_stop)/1000000))

echo "Make is complete in $time_make mseconds"

#make install &> $make_install_log

#if [ $? -ne 0 ]; then
 #   echo "Make error: see $make_install_log for more info"
#fi

time_stop=$(date +"%N")
time_done=$(((time_stop-time_start)/1000000))

echo "Building is done in ${time_done} msecond"


