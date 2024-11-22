#!/bin/bash

EXEC="./test2"
OUTPUT="exits/dos_security_tests.txt"

echo "Denial of Service (DoS) Tests" > $OUTPUT
echo "===============================" >> $OUTPUT

function dos_test() {
    local input="$1"
    local count="$2"
    echo "[Running DoS test with $count requests]" >> $OUTPUT
    for i in $(seq 1 $count); do
        { time $EXEC "$input"; } 2>> $OUTPUT
    done
    echo "---------------------------------" >> $OUTPUT
}

dos_test "Test DoS" 100
dos_test "$(python3 -c 'print("A" * 1000)')" 500
dos_test "$(python3 -c 'print("A" * 10000)')" 200

echo "[DoS Security Tests Completed]" >> $OUTPUT
