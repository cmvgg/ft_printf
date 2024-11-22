#!/bin/bash

EXEC="./test2"    # Nombre del binario
OUTPUT="exits/duration_performance_results.txt"

echo "Duration Performance Tests" > $OUTPUT
echo "==========================" >> $OUTPUT

# Función para realizar pruebas de duración
function duration_test() {
    local input="$1"
    local duration="$2"
    echo "[Running duration test for $duration seconds]" >> $OUTPUT
    { time (for i in $(seq 1 $duration); do $EXEC "$input"; done); } 2>> $OUTPUT
    echo "---------------------------------" >> $OUTPUT
}

# Pruebas de duración con entradas simples
duration_test "Hello, world!" 60     # 1 minuto
duration_test "Long test string" 600 # 10 minutos
duration_test "Max stress test string" 3600 # 1 hora

echo "[Duration Performance Tests Completed]" >> $OUTPUT
