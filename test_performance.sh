#!/bin/bash

EXEC="./test2"    # Nombre del binario
OUTPUT="exits/stress_performance_results.txt"

echo "Stress Performance Tests" > $OUTPUT
echo "=========================" >> $OUTPUT

# Función para realizar pruebas de estrés
function stress_test() {
    local input="$1"
    echo "[Running stress test with input size: $2]" >> $OUTPUT
    { time $EXEC "$input"; } 2>> $OUTPUT
    echo "----------------------------------" >> $OUTPUT
}

# Pruebas de estrés con entradas masivas
STRESS_STRING=$(python3 -c 'print("A" * 1000000)')
stress_test "$STRESS_STRING" "1000000 characters"

STRESS_STRING=$(python3 -c 'print("A" * 10000000)')
stress_test "$STRESS_STRING" "10000000 characters"

echo "[Stress Performance Tests Completed]" >> $OUTPUT
