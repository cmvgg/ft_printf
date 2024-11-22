#!/bin/bash

EXEC="./test2"
OUTPUT="exits/performance_time_tests.txt"
LARGE_STRING=$(head -c 100000 /dev/urandom | tr -dc 'a-zA-Z0-9')

echo "Performance Time Tests" > $OUTPUT
echo "=======================" >> $OUTPUT

PASS_COUNT=0
FAIL_COUNT=0

function time_test() {
    local description="$1"
    local command="$2"
    echo "[Test: $description]" >> $OUTPUT
    START=$(date +%s%N)
    eval "$command" > /dev/null
    EXIT_CODE=$?
    END=$(date +%s%N)
    DIFF=$(( (END - START) / 1000000 ))
    echo "Execution time: $DIFF ms" >> $OUTPUT
    echo "---------------------------------" >> $OUTPUT

    if [[ $EXIT_CODE -eq 0 ]]; then
        echo "[PASS] $description - Time: $DIFF ms"
        PASS_COUNT=$((PASS_COUNT + 1))
    else
        echo "[FAIL] $description - Error occurred!"
        FAIL_COUNT=$((FAIL_COUNT + 1))
    fi
}

time_test "Small string" "$EXEC 'Hello, world!'"
time_test "Large string" "$EXEC \"$LARGE_STRING\""
time_test "1000 integers" "$EXEC $(seq -s ' ' 1 1000)"
time_test "Pointer addresses" "$EXEC $(for i in {1..100}; do printf '0x%x ' $i; done) "

echo
echo "Summary:"
echo "========="
echo "Total Passed: $PASS_COUNT"
echo "Total Failed: $FAIL_COUNT"
echo

echo "[Performance Time Tests Completed]" >> $OUTPUT
