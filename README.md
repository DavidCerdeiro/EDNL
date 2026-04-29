# 🌳 Librería de Estructuras de Datos No Lineales y Algoritmia Avanzada (C++)

## 📌 Descripción del Proyecto
Este repositorio contiene una colección de implementaciones desde cero de **estructuras de datos complejas (no lineales)** y algoritmos avanzados desarrollados en **C++**. 

El objetivo principal de esta librería es resolver problemas computacionales de alta complejidad, priorizando la eficiencia algorítmica (Notación Big O), el manejo riguroso de la memoria dinámica a bajo nivel y la optimización de tiempos de búsqueda y enrutamiento.

## 🚀 Estructuras y Algoritmos Implementados

El repositorio está dividido en tres grandes módulos lógicos de estructuras de datos, aplicables a diferentes escenarios de la ingeniería de software:

### 1. Árboles Binarios y de Búsqueda (BST)
Implementación orientada a la indexación rápida y búsqueda optimizada de información.
* Desarrollo de Árboles Binarios de Búsqueda (BST).
* Algoritmos de recorrido (Preorden, Inorden, Postorden, Niveles).
* Operaciones recursivas e iterativas para cálculo de profundidad, altura y balanceo de nodos.
* *Caso de uso:* Motores de búsqueda internos y bases de datos jerárquicas simples.

### 2. Árboles Generales (N-arios)
Estructuras diseñadas para representar relaciones jerárquicas asimétricas.
* Implementación de nodos con múltiples ramificaciones dinámicas.
* *Caso de uso:* Representación de sistemas de archivos (File Systems), parsers de lenguajes o estructuras organizativas complejas.

### 3. Teoría de Grafos y Enrutamiento
Modelado de redes y topologías complejas para la resolución de problemas de caminos y conectividad.
* Representación mediante Matrices de Adyacencia y Listas de Adyacencia.
* **Algoritmos de Búsqueda:** Búsqueda en Anchura (BFS) y Búsqueda en Profundidad (DFS).
* **Caminos Mínimos:** Implementación de algoritmos de optimización de rutas (ej. Dijkstra, Floyd-Warshall).
* **Árboles de Expansión Mínima (MST):** Conectividad óptima de redes (ej. Kruskal, Prim).
* *Caso de uso:* Sistemas de navegación, topologías de red y optimización de logística.

## 🛠️ Aspectos Técnicos y Buenas Prácticas (C++ Core)

* **Gestión Manual de Memoria:** Uso intensivo de punteros, referencias y control de fugas de memoria (*memory leaks*) en la creación y destrucción de grafos y árboles.
* **Recursividad vs Iteración:** Toma de decisiones arquitectónicas evaluando el coste de la pila de llamadas (*Call Stack*) frente a la complejidad espacial.
* **Programación Orientada a Objetos (OOP):** Encapsulación de la lógica de los nodos y las estructuras para garantizar un código limpio, modular y reutilizable.
