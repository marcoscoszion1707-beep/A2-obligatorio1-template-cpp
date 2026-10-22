# Bitácora — Obligatorio 1

**Integrantes:** Marcos Coszion (332945), Luca Bruni (346902)

## 2026-10-15 — En conjunto — Ejercicio 1

- Analizamos las operaciones de alta, búsqueda y rango del catálogo de monedas y pinturas.
- Decidimos utilizar el mismo TAD AVL parametrizado por tipo, instanciándolo con long long para monedas por tema de overflow y string para pinturas.
- Adaptamos el material de AVL de Aulas a AVL.h y AVLImp.cpp, incorporando inserción sin duplicados, búsqueda, actualización de alturas y rotaciones.
- Para las consultas de rango implementamos un recorrido in-order con poda de subárboles, respetando ambos extremos del intervalo.
- Fuente: presentación de AVL de Aulas. 
- IA durante el desarrollo: no utilizada.
- Desarrollo de un script para no correr las pruebas manualmente.
- Problema con el compilador de C++, no se detectaba instalado en el dispositivo del integrante Marcos Coszion, solución mediante foros de internet.
- Salida de pruebas de ejercicio 1 Ok.

## 2026-10-17 — En conjunto — Ejercicio 2

- Analizamos cómo identificar palabras con las mismas letras y multiplicidades, independientemente de su orden.
- Elegimos una tabla hash abierta con encadenamiento mediante listas, almacenando un nodo y un contador por cada cajón distinto. 
- Implementamos claveDelCajon, que cuenta las 26 letras y construye una clave canónica ordenada.
- Incorporamos los contadores cajones y mayor para responder la última línea en tiempo constante.
- Dimensionamos la tabla utilizando el primer primo mayor o igual que N, sin realizar rehash.
- Consultamos material de Aulas y conversamos con un compañero de otro grupo al encontrar dificultades.
- IA: revisión de código. Se evaluó modificar el dimensionamiento del hash, pero se decidió conservar el original. Quedó identificada una observación sobre la justificación del costo de buscar el primo.
- Ocurrencia de un warning por comparacion de diferentes tipos, no afecta el funcionamineto, pruebas ejercicio 2 dan ok.

## 2026-10-18 — En conjunto — Ejercicio 3

- Identificamos que en cada paso correspondía consolidar los dos archivos más pequeños disponibles.
- Elegimos un min-heap binario para extraer mínimos y volver a insertar el tamaño del archivo consolidado.
- Adaptamos las implementaciones y la presentación de Heap de Aulas, además de ejemplos vistos en clase.
- Acumulamos el costo total utilizando long long y contemplamos el caso de un único archivo, cuyo costo es cero.
- Fuentes: presentación de Heap e implementaciones de clase. 
- IA durante el desarrollo: no utilizada.
- Salida de pruebas de ejercicio 3 Ok.

## 2026-10-20 — En conjunto — Ejercicio 4

- Analizamos el problema de las dependencias de módulos y la selección del siguiente módulo por prioridad e identificador.
- Implementamos ordenamiento topológico mediante Kahn, con grafo dirigido de listas de adyacencia y un arreglo de grados de entrada.
- Utilizamos un min-heap para elegir el siguiente módulo disponible. Codificamos la prioridad y el identificador.
- Guardamos el orden antes de imprimirlo para poder responder solamente imposible si existen ciclos.
- Fuentes: presentaciones de Grafos y Heap de Aulas e implementaciones vistas en clase.
- IA: ayuda para corregir errores específicos durante el desarrollo.
- Salida de pruebas de ejercicio 4 no todas Ok hasta revisión.

## 2026-10-21 — En conjunto — Ejercicio 5

- Identificamos que el objetivo era obtener el árbol de cubrimiento mínimo del grafo de refugios y senderos.
- Aplicamos Kruskal: extraer senderos de menor costo mediante un min-heap y aceptar solo los que conectan componentes distintas.
- Implementamos MFSetImp utilizando arreglos de padres y alturas, compresión de caminos y unión por altura.
- Incorporamos la detección del caso imposible y el caso de un único refugio.
- Fuentes: presentaciones de Grafos y Heap de Aulas e implementaciones de clase.
- IA: corrección de errores específicos durante el desarrollo.
- Salida de pruebas de ejercicio 5 no todas Ok hasta revisión.

## 2026-10-22 — En Conjunto — Revisión y pruebas finales

- Revisamos con IA las implementaciones de HashCajonesImp y MFSetImp, especialmente el encadenamiento y los contadores del hash, y la compresión de caminos y unión por altura del MFSet.
- Revisamos también los TAD AVL, grafo y min-heap y su relación con las restricciones de los cinco ejercicios.
- Tras considerar una alternativa al cálculo del siguiente primo del hash, decidimos mantener el código original.
- Ejecutaamos los tests de los cinco ejercicios y confirmé que todos los tests ejecutados pasaron correctamente.
- Consulta entre estudiantes: intercambio con un compañero de otro grupo para corroboración de implementaciones, satisfactorio.