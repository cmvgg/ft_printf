#!/bin/bash

EXEC="./test2"
OUTPUT="exits/security_logs.txt"

echo "Security Logs" > $OUTPUT
echo "====================" >> $OUTPUT

function log_activity() {
    local input="$1"
    echo "[Running security test with input: $input]" >> $OUTPUT
    $EXEC "$input" >> $OUTPUT 2>&1
    echo "---------------------------------" >> $OUTPUT
}

log_activity "'; ls -la"
log_activity "'; rm -rf /"
log_activity "'; echo 'Injection test passed'"

echo "[Security Logs Collection Completed]" >> $OUTPUT
