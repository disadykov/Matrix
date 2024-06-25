#!/bin/bash

clear
echo "###################################################################"
echo "#           LAUNCH TESTS CASES FOR PROJECT S21_MATRIX             #"
echo "###################################################################"
echo
GCC=$1
FLAGS=$(echo $2)
TEST_LIB=$3
LIBS_OS_CHECK=$(echo $4)
FLAG_GCOV=$5
OSLINUX=$(echo $6)

cd test
find . -name "*.check" | while read FILE
do
    echo "--------------------------------------------"
    filename=$(basename "$FILE" \.check)
    checkmk $filename.check > test_$filename.c
    $GCC $FLAGS $FLAG_GCOV -c test_$filename.c
    $GCC $FLAGS -o test_$filename test_$filename.o ../$TEST_LIB.a $LIBS_OS_CHECK $FLAG_GCOV
    echo "TESTS CASES --> $filename:"
    ./test_$filename

    if [[ $OSLINUX -eq 1 ]]
        then
            ./linux_leak.sh "test_$filename"
        else
            ./mac_leak.sh "test_$filename"
    fi
    echo
    rm -f test_$filename
done
