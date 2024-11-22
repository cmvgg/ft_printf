#!/bin/bash

EXEC="./test2"
OUTPUT="exits/regression_tests.txt"

echo "Regression Tests" > $OUTPUT
echo "================" >> $OUTPUT

PASS_COUNT=0
FAIL_COUNT=0

function regression_test() {
    local description="$1"
    local expected_output="$2"
    local command="$3"
    local test_output

    echo "[Regression Test: $description]" >> $OUTPUT
    test_output=$(eval "$command")
    if [[ "$test_output" == "$expected_output" ]]; then
        echo "[PASS] $description"
        echo "PASS: $description" >> $OUTPUT
        PASS_COUNT=$((PASS_COUNT + 1))
    else
        echo "[FAIL] $description"
        echo "Expected: $expected_output, Got: $test_output"
        echo "FAIL: $description - Expected: $expected_output, Got: $test_output" >> $OUTPUT
        FAIL_COUNT=$((FAIL_COUNT + 1))
    fi
}

regression_test "Basic string output" "Hello, world!" "$EXEC 'Hello, world!'"
regression_test "Integer output" "42" "$EXEC '%d' 42"
regression_test "Hexadecimal output" "2a" "$EXEC '%x' 42"
regression_test "Pointer output" "0x7ffeea3b4b40" "$EXEC '%p' 0x7ffeea3b4b40"

echo
echo "Summary:"
echo "========="
echo "Total Passed: $PASS_COUNT"
echo "Total Failed: $FAIL_COUNT"
echo

echo "[Regression Tests Completed]" >> $OUTPUT
