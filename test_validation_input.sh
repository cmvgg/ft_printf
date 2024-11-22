#!/bin/bash

EXEC="./test2"
OUTPUT="exits/input_validation_security_tests.txt"

echo "Input Validation Security Tests" > $OUTPUT
echo "=================================" >> $OUTPUT

function input_validation_test() {
    local input="$1"
    echo "[Running input validation test with input: $input]" >> $OUTPUT
    { time $EXEC "$input"; } 2>> $OUTPUT
    echo "---------------------------------" >> $OUTPUT
}

input_validation_test "' OR 1=1 --"
input_validation_test "' UNION SELECT * FROM users --"
input_validation_test "$(python3 -c 'print("DROP TABLE users")')"
input_validation_test "$(python3 -c 'print("<script>alert(1)</script>")')"

echo "[Input Validation Security Tests Completed]" >> $OUTPUT
