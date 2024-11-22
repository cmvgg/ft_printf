#!/bin/bash

EXEC="./test2"    # Nombre del binario
OUTPUT="exits/buffer_overflow_security_tests.txt"

echo "Buffer Overflow Security Tests" > $OUTPUT
echo "===============================" >> $OUTPUT

# Función para probar desbordamientos de búfer
function buffer_overflow_test() {
    local input="$1"
    echo "[Running buffer overflow test with input: $input]" >> $OUTPUT
    { time $EXEC "$input"; } 2>> $OUTPUT
    echo "---------------------------------" >> $OUTPUT
}

# Intentos de desbordamiento de búfer con entradas muy largas
buffer_overflow_test "$(python3 -c 'print("A" * 10000)')"
buffer_overflow_test "$(python3 -c 'print("A" * 100000)')"
buffer_overflow_test "$(python3 -c 'print("A" * 1000000)')"

echo "[Buffer Overflow Security Tests Completed]" >> $OUTPUT
