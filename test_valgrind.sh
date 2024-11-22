#!/bin/bash

EXEC="./test2"
OUTPUT="exits/valgrind_results.txt"

echo "Memory Analysis with Valgrind" > $OUTPUT
echo "=============================" >> $OUTPUT

function valgrind_result() {
    if grep -q "no leaks are possible" $1; then
        echo "$2: PASS" >> $OUTPUT
    else
        echo "$2: FAIL" >> $OUTPUT
    fi
}

echo "[1] Testing buffer overflow detection" | tee -a $OUTPUT
valgrind --leak-check=full --track-origins=yes $EXEC "$(python3 -c 'print("%d" * 1000)')" > valgrind_output.log 2>&1
valgrind_result "valgrind_output.log" "Testing buffer overflow detection"

echo "[2] Testing null pointer" | tee -a $OUTPUT
valgrind --leak-check=full --track-origins=yes $EXEC "%s" NULL > valgrind_output.log 2>&1
valgrind_result "valgrind_output.log" "Testing null pointer"

echo "[3] Testing for memory leaks" | tee -a $OUTPUT
valgrind --leak-check=full --track-origins=yes $EXEC "String: %s" "Test" > valgrind_output.log 2>&1
valgrind_result "valgrind_output.log" "Testing for memory leaks"

echo "[Valgrind Analysis Completed]" | tee -a $OUTPUT
