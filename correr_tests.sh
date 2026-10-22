#!/usr/bin/env bash
# Compila ejercicioN.cpp y lo corre contra tests/ejercicioN/*.in.txt,
# comparando con el .out.txt correspondiente.
#
# Uso:   ./correr_tests.sh N [filtro]
# Ej:    ./correr_tests.sh 2            (todos los tests del ejercicio 2)
#        ./correr_tests.sh 2 ejemplo    (solo los que tienen "ejemplo" en el nombre)
#
# Este script es solo para uso local: NO va en el zip de entrega.

n="${1:?Uso: ./correr_tests.sh N [filtro]}"
filtro="${2:-}"
limite=10 # segundos por test

cd "$(dirname "$0")" || exit 1
dir="tests/ejercicio$n"
bin="./ejercicio$n"

[ -f "ejercicio$n.cpp" ] || { echo "No existe ejercicio$n.cpp"; exit 1; }
[ -d "$dir" ] || { echo "No existe $dir"; exit 1; }

echo "Compilando ejercicio$n.cpp ..."
g++ -std=c++11 -O2 -Wall -o "$bin" "ejercicio$n.cpp" || { echo "ERROR DE COMPILACION"; exit 1; }

ok=0
fallan=()
for entrada in "$dir"/*"$filtro"*.in.txt; do
    [ -f "$entrada" ] || continue
    nombre="$(basename "$entrada" .in.txt)"
    esperado="$dir/$nombre.out.txt"
    obtenido="$dir/$nombre.myout.txt"

    inicio=$(date +%s%N)
    timeout "$limite" "$bin" < "$entrada" > "$obtenido"
    codigo=$?
    ms=$(( ($(date +%s%N) - inicio) / 1000000 ))

    if [ $codigo -eq 124 ]; then
        estado="TIMEOUT (> ${limite}s)"
    elif [ $codigo -ne 0 ]; then
        estado="CRASH (codigo $codigo)"
    elif diff -q -Z --strip-trailing-cr "$obtenido" "$esperado" > /dev/null; then
        estado="OK"
    else
        estado="DISTINTO"
    fi

    if [ "$estado" = "OK" ]; then
        ok=$((ok + 1))
        rm -f "$obtenido"
        printf "  OK        %-32s %6d ms\n" "$nombre" "$ms"
    else
        fallan+=("$nombre")
        printf "  FALLA     %-32s %6d ms  %s\n" "$nombre" "$ms" "$estado"
    fi
done

total=$((ok + ${#fallan[@]}))
echo
echo "Resultado: $ok/$total OK"
if [ ${#fallan[@]} -gt 0 ]; then
    echo "Fallan: ${fallan[*]}"
    echo "Salida propia en $dir/<nombre>.myout.txt (ignorada por git). Comparar con:"
    echo "  diff $dir/<nombre>.myout.txt $dir/<nombre>.out.txt | head"
    exit 1
fi