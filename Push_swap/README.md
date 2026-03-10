*Este proyecto ha sido creado como parte del currículo de 42 por jezambra y damagda*



# Push_swap

## Descripción

Push_swap es un proyecto de ordenación algorítmica. El objetivo es ordenar una lista de números enteros usando únicamente dos stacks (a y b) y un conjunto limitado de operaciones, minimizando el número de movimientos realizados.

El programa recibe los números como argumentos, calcula la secuencia óptima de operaciones y la imprime por stdout. Cada operación va separada por un salto de línea.

### Operaciones disponibles

| Operación | Descripción |
|-----------|-------------|
| `sa` | Intercambia los dos primeros elementos de A |
| `sb` | Intercambia los dos primeros elementos de B |
| `ss` | sa y sb a la vez |
| `pa` | Mueve el primero de B al principio de A |
| `pb` | Mueve el primero de A al principio de B |
| `ra` | Rota A: el primero pasa al final |
| `rb` | Rota B: el primero pasa al final |
| `rr` | ra y rb a la vez |
| `rra` | Rota A al revés: el último pasa al principio |
| `rrb` | Rota B al revés: el último pasa al principio |
| `rrr` | rra y rrb a la vez |

---

## Instrucciones

### Compilación

```bash
make
```

### Uso básico

```bash
./push_swap 5 4 3 2 1
```

### Selección de algoritmo

```bash
./push_swap --simple 5 4 3 2 1      # Fuerza O(n²)
./push_swap --medium 5 4 3 2 1      # Fuerza O(n√n)
./push_swap --complex 5 4 3 2 1     # Fuerza O(n log n)
./push_swap --adaptive 5 4 3 2 1    # Adaptativo según desorden (por defecto)
```

### Modo benchmark

```bash
./push_swap --bench 5 4 3 2 1
./push_swap --bench --complex 5 4 3 2 1
```

El modo `--bench` imprime por stderr el índice de desorden, la estrategia usada, el total de operaciones y el desglose por tipo.

### Verificación con checker

```bash
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
```

### Prueba de rendimiento

```bash
# 100 números
shuf -i 0-99 -n 100 > args.txt
./push_swap $(cat args.txt) | wc -l
./push_swap $(cat args.txt) | ./checker_linux $(cat args.txt)

# 500 números
shuf -i 0-499 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
./push_swap $(cat args.txt) | ./checker_linux $(cat args.txt)
```

## Algoritmos implementados

### Índice de desorden

Antes de ordenar, el programa calcula un índice de desorden entre 0 y 1. Se comparan todos los pares posibles de números: si un número mayor aparece antes que uno menor, se cuenta como error. El índice es el cociente entre errores y total de pares.

- **0.0** → lista completamente ordenada
- **1.0** → lista completamente desordenada

### 1. Algoritmo simple — O(n²) — `--simple`

**Técnica:** Insertion sort adaptado a push_swap.

En cada pasada se localiza el mínimo del stack A. Si está en la mitad superior se usa `ra` para subirlo al tope; si está en la mitad inferior se usa `rra` (más eficiente). Una vez arriba se manda a B con `pb`. Al vaciar A se devuelve todo a A con `pa`, quedando ordenado.

**Justificación:** Por cada uno de los n elementos se realizan hasta n rotaciones, lo que da O(n²) operaciones en el peor caso.

**Rendimiento medido:** ~580 ops para 100 números (excelente, < 700).

### 2. Algoritmo intermedio — O(n√n) — `--medium`

**Técnica:** k-sort (ordenación por rangos).

Se divide el rango de índices en grupos de tamaño `range` (15 para ≤100 elementos, 35 para ≤500). En cada pasada se van mandando a B los elementos cuyos índices caen dentro del grupo actual, rotando A cuando el tope no encaja. Los elementos que van al fondo de su grupo se mandan al fondo de B con `rb`. Al vaciar A se reconstruye desde B devolviendo siempre el máximo actual a A con `pa`.

**Justificación:** Con √n k-sorts, cada k-sort requiere O(n) rotaciones para procesarse, dando O(n·√n) operaciones totales.

**Rendimiento medido:** ~5196 ops para 500 números (bueno, < 5500).

### 3. Algoritmo complejo — O(n log n) — `--complex`

**Técnica:** Radix sort LSD (Least Significant Digit) sobre índices en binario.

Se trabaja sobre los índices asignados (0 al n-1) en lugar de los valores. Por cada bit, de menor a mayor significativo, se recorre A completo: si el bit es 0 el elemento va a B con `pb`, si es 1 se rota con `ra`. Al terminar cada pasada se devuelve todo B a A con `pa`. Tras log₂(n) pasadas A queda ordenado.

**Justificación:** Se realizan log₂(n) pasadas, cada una toca los n elementos, dando O(n log n) operaciones.

**Rendimiento medido:** ~6784 ops para 500 números.

### 4. Algoritmo adaptativo — `--adaptive` (por defecto)

**Técnica:** Selección dinámica según el índice de desorden calculado antes de ordenar.

| Desorden | Umbral | Algoritmo usado | Complejidad |
|----------|--------|-----------------|-------------|
| Bajo | < 0.2 | Insertion sort | O(n) en la práctica |
| Medio | 0.2 – 0.5 | k-sort sort | O(n√n) |
| Alto | ≥ 0.5 | Radix sort | O(n log n) |

**Justificación de los umbrales:**
- Por debajo de 0.2 el stack está casi ordenado: insertion sort requiere muy pocas rotaciones porque el mínimo suele estar cerca del tope, comportándose de forma lineal en la práctica.
- Entre 0.2 y 0.5 el desorden es moderado: k-sort sort aprovecha la estructura parcial para reducir el número de rotaciones respecto a radix.
- Por encima de 0.5 el desorden es alto y no hay estructura aprovechable: radix sort garantiza O(n log n) independientemente del orden inicial.

**Casos pequeños:** Para 1-2 elementos se aplica directamente `sa` si hace falta. Para 3 elementos se usa `tiny_sort` (6 casos hardcodeados, mínimo de operaciones). Para 4-5 elementos se usa `sort_five` (manda los 2 menores a B, ordena los 3 restantes con `tiny_sort` y devuelve).

---

## Rendimiento

| Entrada | Mínimo | Bueno | Excelente |
|---------|--------|-------|-----------|
| 100 nums | < 2000 | < 1500 | < 700 |
| 500 nums | < 12000 | < 8000 | < 5500 |

Nuestros resultados con el modo adaptativo:
- 100 números: ~580 operaciones ✅ (excelente)
- 500 números: ~5196 operaciones ✅ (excelente)

---

## Contribuciones

| Login | Contribución |
|-------|-------------|
| jezambra | Estructura de datos (lista doblemente enlazada), movimientos básicos y rotativos, algoritmo insertion sort, algoritmo k-sort sort. |
| damagda | [ Sistema de flags, modo benchmark, main, gestión de argumentos y algoritmo radix.] |

---

## Recursos

### Referencias

- Knuth, D. E. — *The Art of Computer Programming, Vol. 3: Sorting and Searching* — referencia clásica sobre algoritmos de ordenación y análisis de complejidad.
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Insertion Sort — Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
- Peer-to-Peer en 42Madrid.
- Colaboracion de amigos ya que no hemos podido ir al campus muy amenudo.


### Uso de IA

Durante el desarrollo se utilizó IA para las siguientes tareas:

- **Depuración:** Identificación de errores y pruebas para la compilacion con diferentes casos.
- **Documentación:** Generación de estructura del README.
- **Explicación de conceptos:** Aclaración del funcionamiento de algoritmos como radix sort LSD y k-sort sort.

Todo el uso de la IA fue revisado, comprendido y validado por ambos integrantes del grupo antes de su integración en el proyecto.