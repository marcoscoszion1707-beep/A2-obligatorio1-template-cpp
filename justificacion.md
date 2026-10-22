# Justificación de órdenes — Obligatorio 1

## Ejercicio 1

Exigencia: un solo TAD AVL parametrizado por tipo; ALTA y BUSCAR en O(log K) peor caso; RANGO en O(log K + R) peor caso, donde K es la cantidad de piezas y R la cantidad de resultados.

Se instancia AVL<long long> para monedas y AVL<string> para pinturas, reutilizando el mismo TAD. El AVL conserva altura O(log K) mediante rotaciones, por lo que la búsqueda y la inserción recorren como máximo una cantidad logarítmica de nodos y cuestan O(log K) en el peor caso. La inserción de repetidos debe no agregar nuevos nodos.

Para RANGO, debe hacerse un recorrido in-order podado: solo se visita el subárbol izquierdo si la clave del nodo supera desde, y solo el derecho si la clave es menor que hasta; se imprimen las claves en el intervalo cerrado. Con esta implementación el costo es O(log K + R) y el orden de salida es creciente. Comprobado en AVLimp.cpp: rangoRec poda el subárbol izquierdo cuando la clave es menor que el extremo inferior y el derecho cuando supera el extremo superior. La inserción ignora repetidos y balancear efectúa las rotaciones necesarias.

El espacio para K elementos es O(K); la pila recursiva, si se utiliza, necesita O(log K). Los títulos tienen longitud acotada por 20 caracteres, por lo que su comparación puede tratarse como costo constante bajo las cotas de la letra.

## Ejercicio 2

Exigencia: tabla hash abierta con encadenamiento, inserción y consulta en O(L) promedio incluyendo clave, hash y comparaciones; última línea en O(1) peor caso.

claveDelCajon cuenta las apariciones de las 26 letras y construye una representación canónica en orden alfabético. Su costo es O(L + 26) = O(L) por palabra, puesto que 26 es constante. La clave preserva multiplicidades, así que dos palabras usan el mismo cajón exactamente cuando tienen la misma clave. Se almacena una sola entrada de hash por cajón, con un contador de palabras registradas: esto permite que el número de palabras dentro del cajón no afecte el costo de consultar o insertar.

La implementación original de HashCajonesImp utiliza un arreglo de punteros a listas enlazadas. Cada nodo contiene la clave del cajón y un contador palabras. Al insertar una clave existente se incrementa el contador, sin agregar nodos. buscarNodo calcula el hash y recorre únicamente los nodos del bucket correspondiente, comparando las claves completas. La función hash polinómica acumula hash = (hash * 31 + clave[i]) % tamanio y cuesta O(L).

El constructor elige tamanio = primoMayorOIgual(N). Como hay a lo sumo N claves distintas, el factor de carga es a lo sumo 1 y no se hace rehash. Se conserva este dimensionamiento original, con búsqueda del siguiente primo. Para obtener O(L) promedio por inserción/consulta se presupone dispersión suficientemente uniforme: el recorrido esperado de un bucket tiene longitud constante y cada comparación de claves cuesta O(L). Tener factor de carga acotado no garantiza esa distribución para cualquier entrada.

Las variables cajones y mayor se actualizan durante insertar, con O(1), y permiten imprimir la última línea en O(1) en el peor caso mediante cantidadCajones() y mayorCajon(). La tabla y sus nodos ocupan O(N) espacio, puesto que el largo de las claves está acotado por 20.

Precisión sobre el orden global: la inicialización del arreglo cuesta O(tamanio); sin embargo, el cálculo de primoMayorOIgual(N) recorre candidatos y esPrimo los prueba por divisiones hasta la raíz cuadrada. Con el código disponible, el costo de esa búsqueda no está justificado como O(N) en todos los casos. Por tanto, el procesamiento de las N inserciones y Q consultas sí tiene orden esperado lineal en la entrada bajo el supuesto de dispersión, pero no se puede afirmar sin una demostración adicional que toda la ejecución, incluido el cálculo inicial del primo, cumple estrictamente el orden lineal promedio de la letra.

## Ejercicio 3

Exigencia: heap binario, tiempo O(N log N) peor caso y espacio O(N).

El código utiliza un MinHeap<long long> para mantener disponibles los tamaños de los archivos. Inserta N valores, cada uno en O(log N) mediante flotar. Mientras quede más de uno extrae los dos mínimos y reinserta su suma; cada extracción/inserción vale O(log N) mediante operaciones del heap. Hay exactamente N-1 consolidaciones, por lo que el costo total es O(N log N) peor caso. El heap guarda como máximo N tamaños, de modo que el espacio es O(N). Para N=1 el ciclo no se ejecuta y se imprime cero. Se usa long long para evitar desbordamientos de 32 bits.

Comprobado en MinHeapImp.cpp: el heap se implementa con un arreglo indexado desde 1 y las operaciones flotar y hundir recorren como máximo la altura del árbol binario, O(log N).

## Ejercicio 4

Exigencia: heap binario para seleccionar módulos, tiempo O((V+A) log V) peor caso y espacio O(V+A).

Se utiliza el algoritmo de ordenamiento topológico de Kahn. Un grafo dirigido almacena las dependencias; gradoEntrada cuenta cuántos requisitos quedan pendientes por módulo. Se insertan en un min-heap solo los módulos de grado de entrada cero. La clave prioridad[i] * (V+1) + i, guardada en long long, ordena primero por prioridad y luego por número, sin comparador adicional.

Inicializar arreglos cuesta O(V); crear y registrar las A aristas cuesta O(A) si cada agregarArista es O(1). Cada módulo entra y sale del heap una sola vez: O(V log V). Cada arista se recorre una sola vez al reducir grados: O(A). Total O(V+A+V log V), contenido en O((V+A) log V) para V>=2 (para V=1 el costo es constante). El grafo, heap y arreglos ocupan O(V+A). Si se procesan menos de V módulos se imprime únicamente imposible; por eso se guarda el orden hasta confirmar que no haya ciclos.

Comprobado en GrafoImp.cpp: se emplea un arreglo de listas de adyacencia; agregar una arista dirigida es O(1) y recorrer todas las listas durante Kahn suma O(V+A). También se comprobó el heap binario.

## Ejercicio 5

Exigencia: Kruskal con conjuntos disjuntos, compresión de caminos y unión por altura, tiempo O(E log E) peor caso y espacio O(V+E).

Se implementa Kruskal: cada sendero se carga en un min-heap con clave costo * (E+1) + índice (tipo long long) para extraerlo en orden de costo ascendente, recuperando sus extremos desde los arreglos. Para cada sendero se consultan sus representantes en MFSet; solo se acepta si pertenecen a componentes distintas. Se detiene al escoger V-1 senderos. Si esto no es posible se imprime imposible; con V=1 se imprime cero.

Insertar E senderos en el heap y extraer a lo sumo E cuesta O(E log E) para E>=2. Los arreglos de extremos y el heap ocupan O(E); la estructura de conjuntos disjuntos, O(V). Se revisó MFSetImp: buscar realiza compresión de caminos (padre[elem] = buscar(padre[elem])) y unir compara las alturas de representantes y solo incrementa la altura si empatan. Ambas optimizaciones ofrecen tiempo amortizado casi constante (O(α(V))) por operación, no O(1) en el peor caso individual. Su costo total usual es O(E α(V)) más la inicialización O(V); combinado con el heap es O(E log E + E α(V) + V). La letra solicita O(E log E) en el peor caso. La implementación presenta el costo explícito O(V + E log E + E α(V)) considerando la inicialización, y la cota habitual amortizada para el MFSet; no se debe ocultar el término O(V) si hay refugios aislados y pocas aristas. Para E = 0, el algoritmo igualmente inicializa el MFSet en O(V).

Verificado en el TAD compartido: se implementan tanto compresión de caminos como unión por altura. También se verificó MinHeapImp, cuya extracción e inserción son O(log E) en el peor caso.