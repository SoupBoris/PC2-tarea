# Tarea #7: Estructura de datos fundamentales - Arboles y Grafos

Problemas del curso de Programación Orientada a Objetos 2 - CS1103

## Problema #1 - Obtener mediana

Diseñar y desarrollar el template de clase **median** que permita la busqueda en tiempo constante del valor de la mediana de una colección de valores numéricos y que permita insertar en tiempo logarítmico y borrar en tiempo logarítmico los valores.

**Casos de uso**  
```cpp
    // Caso de uso #1
    median<int> m1 = {1, 2, 3, 4, 5, 6};
    cout << "mediana = " << m1();
    // Caso de uso #2
    int n = 100;
    median<int> m2;
    for (int i = 0; i < n; ++i)
        m2.push_back(random<int>(1, 100)); 
    cout << "mediana = " << m2();
    // Caso de uso #3
    n = 50;
    for (int i = 0; i < n; ++i)
        m2.pop_back(); 
    cout << "mediana = " << m2();
```
## Problema #2 - Distancia al origen

Diseñar y desarrollar el template de clase **distance** que por medio de un heap de puntos 𝑷(𝑿,𝒀) devuelva los n primeros valores cuya distancia euclidiana al punto 𝑷(𝟎,𝟎) sea la más corta. 

**Casos de uso**  
```cpp
    // Caso de uso #1
    distance<int> d1(0, 0);
    d1 = {{1,1}, {10, 20}, {30, 30}, {4, 5}, {11, 22}};
    for (auto p: d1(2))
        cout << "punto = " << p.first << ", " << p.second << endl;
    // Caso de uso #2
    int n = 100;
    distance<int> d2(10, 10);
    for (int i = 0; i < n; ++i)
        d2.push_back({random<int>(1, 100), random<int>(1, 100)}); 
    for (auto p: d2(10))
        cout << "punto = " << p.first << ", " << p.second << endl;
    // Caso de uso #3
    n = 50;
    for (int i = 0; i < n; ++i)
        d2.pop_back(); 
    for (auto p: d2(10))
        cout << "punto = " << p.first << ", " << p.second << endl;
```
## Problema #3 - Remover duplicados

Diseñar y desarrollar el template de función `remove_duplicates` que en un tiempo lineal O(n) permita remover los valores duplicados de un contenedor. 

```cpp
template <typename Container>
void remove_duplicates(Container& cnt);
```

**Casos de uso**  

## Problema #4 - Par Equivalente
Diseñar y desarrollar el template de función `get_equivalent_pair` que al recibir 2 collecciones de valores numéricas y un número k, retorne un par ordenado cuya suma sea igual al valor k. 

```cpp
template <typename T, template <typename> class U>
pair<T, T> get_equivalent_pair(U<T>& cnt);
```

**Casos de uso**  

## Problema #5 - Diametro de un Grafo
Utilizando el arbol binario (**`binary_tree`**) desarrollado en clase, desarrollar el método `diameter` que permita calcular el diámetro de un árbol (es la distancia mas larga entre 2 hojas).

**Casos de uso**  
```cpp
    // Caso de uso #1
    binary_tree_t a(10);
    auto node = a.add_left(a.root(), 10);
    a.add_rigth(node, 20);
    a.add_left(node, 30);
    node = a.add_right(a.root(), 40);
    a.add_rigth(node, 50);
    a.add_left(node, 60);
    // Calcular Diametro 
    cout << a.diametro() << endl;
    // Caso de uso #2
    binary_tree_t a2(1);
    // Izquierda
    auto left_branch = a2.add_left(a2.root(), 2);
    left_branch = a2.add_left(left_branch, 3);
    left_branch = a2.add_left(left_branch, 4);
    left_branch = a2.add_left(left_branch, 5);
    left_branch = a2.add_left(left_branch, 6);
    // Derecha
    auto right_branch = a2.add_right(a2.root(), 7);
    right_branch = a2.add_right(right_branch, 8);
    right_branch = a2.add_right(right_branch, 9);
    right_branch = a2.add_right(right_branch, 10);
    right_branch = a2.add_right(right_branch, 11);
    // Calcular Diametro 
    cout << a2.diametro() << endl;
```

## Problema #6 - Hermanos
Utilizando el arbol binario (**`binary_tree`**) desarrollado en clase, desarrollar el método `are_sibling(node a, node b)` que confirme si 2 nodos son hermanos (se encuentran en un mismo nivel).

**Casos de uso**  
```cpp
    // Caso de uso #1
    binary_tree_t a(1);
    // Izquierda
    auto left_branch = a.add_left(a.root(), 2);
    left_branch = a.add_left(left_branch, 3);
    left_branch = a.add_left(left_branch, 4);
    left_branch = a.add_left(left_branch, 5);
    left_branch = a.add_left(left_branch, 6);
    // Derecha
    auto right_branch = a.add_right(a.root(), 7);
    right_branch = a.add_right(right_branch, 8);
    right_branch = a.add_right(right_branch, 9);
    right_branch = a.add_right(right_branch, 10);
    right_branch = a.add_right(right_branch, 11);
    // Calcular Diametro 
    cout << a.are_sibling(left_branch, right_branch) << endl;

```
## Problema #7 - Conectado
Utilizando el grafo no dirigido  (**`grafo_t`**) desarrollado en clase, desarrollar el método `is_connected` que determine si el grafo es conectado.

**Casos de uso**  
```cpp
    // Caso de uso #1
    graph_t g;
    // Vertices
    g.add_vertex("A");
    g.add_vertex("B");
    g.add_vertex("C");
    g.add_vertex("D");
    g.add_vertex("E");
    // Edges
    g.add_edge("A", "B", 10);
    g.add_edge("B", "E", 4);
    g.add_edge("B", "C", 7);
    g.add_edge("E", "C", 5);
    g.add_edge("E", "D", 8);
    // Verificar si esta conectado
    cout << g.is_connected() << endl;
    // Caso de uso #2
    graph_t g2;
    // Vertices
    g2.add_vertex("A");
    g2.add_vertex("B");
    g2.add_vertex("C");
    // Edges
    g2.add_edge("A", "B", 10);
    // Verificar si esta conectado
    cout << g2.is_connected() << endl;
```

## Problema #8 - Árbol Expandido Máximo
Utilizando el grafo no dirigido  (**`grafo_t`**) desarrollado en clase, crear los métodos Kruskal y Prim en reversa (`kruskal_max`, `prim_max`) de modo que permitan ubicar el Árbol Expandido Máximo.

**Casos de uso**  
```cpp
    // Caso de uso #1
    graph_t g;
    // Vertices
    g.add_vertex("A");
    g.add_vertex("B");
    g.add_vertex("C");
    g.add_vertex("D");
    g.add_vertex("E");
    // Edges
    g.add_edge("A", "B", 10);
    g.add_edge("B", "E", 4);
    g.add_edge("B", "C", 7);
    g.add_edge("E", "C", 5);
    g.add_edge("E", "D", 8);
    // Arbol Expandido Maximo
    for (auto& [a, b, w] : g.kruskal_max())
        cout << a << " " << b << " " << w << endl; 
    cout << endl << endl;
    for (auto& [a, b, w] : g.prim_max())
        cout << a << " " << b << " " << w << endl; 
```