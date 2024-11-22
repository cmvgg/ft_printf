#!/bin/bash

EXEC="./test2"
OUTPUT="exits/performance_stress_tests.txt"
LARGE_STRING=$(head -c 100000 /dev/urandom | tr -dc 'a-zA-Z0-9')

echo "Performance Stress Tests" > $OUTPUT
echo "=========================" >> $OUTPUT

PASS_COUNT=0
FAIL_COUNT=0

function stress_test() {
    local description="$1"
    local iterations="$2"
    echo "[Stress Test: $description with $iterations iterations]" >> $OUTPUT
    for ((i = 1; i <= iterations; i++)); do
        $EXEC "$LARGE_STRING" >> exits/stress_test.txt
        if [[ $? -ne 0 ]]; then
            echo "[FAIL] $description - Failed at iteration $i"
            echo "Test failed at iteration $i" >> $OUTPUT
            FAIL_COUNT=$((FAIL_COUNT + 1))
            return
        fi
    done
    echo "[PASS] $description - Passed $iterations iterations"
    PASS_COUNT=$((PASS_COUNT + 1))
    echo "[Test completed]" >> $OUTPUT
    echo "---------------------------------" >> $OUTPUT
}

stress_test "Small string" 1000
stress_test "Large string" 500
stress_test "Mix of formats" 300

echo
echo "Summary:"
echo "========="
echo "Total Passed: $PASS_COUNT"
echo "Total Failed: $FAIL_COUNT"
echo

echo "[Performance Stress Tests Completed]" >> $OUTPUT
