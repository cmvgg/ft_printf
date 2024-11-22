#!/bin/bash

SOURCE="ft_printf.c ft_printf_utils.c main.c"
OUTPUT="exits/compiler_compatibility_tests.txt"

echo "Compiler Compatibility Tests" > $OUTPUT
echo "=============================" >> $OUTPUT

# Función para compilar y ejecutar con un compilador específico
function compile_and_test() {
    local compiler="$1"
    local version="$2"
    echo "[Testing with $compiler version $version]" >> $OUTPUT
    $compiler --version >> $OUTPUT 2>&1
    $compiler -o ft_printf_$version $SOURCE >> $OUTPUT 2>&1
    if [[ $? -eq 0 ]]; then
        ./ft_printf_$version "Testing compatibility with $compiler $version" >> $OUTPUT 2>&1
        echo "[Test passed]" >> $OUTPUT
    else
        echo "[Compilation failed]" >> $OUTPUT
    fi
    echo "---------------------------------" >> $OUTPUT
}

# Pruebas con GCC
compile_and_test "gcc" "9"
compile_and_test "gcc" "10"
compile_and_test "gcc" "11"

# Pruebas con Clang
compile_and_test "clang" "10"
compile_and_test "clang" "11"
compile_and_test "clang" "12"

echo "[Compiler Compatibility Tests Completed]" >> $OUTPUT
