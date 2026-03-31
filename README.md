# TriMesh Analyzer

Proyecto en C centrado en el uso de estructuras y memoria dinámica para representar puntos del plano y su triangulación.

El programa lee dos ficheros de entrada (`puntos.txt` y `triangulos.txt`), construye en memoria una malla triangular enlazando puntos mediante punteros y realiza un análisis geométrico sobre los triángulos.

---

## Funcionalidad

- Lectura de puntos 2D desde fichero
- Construcción de triángulos a partir de referencias a puntos
- Gestión de memoria dinámica con la librería proporcionada:
  - `mifopen`
  - `mimalloc`
  - `mirealloc`
- Cálculo de:
  - distancia entre puntos
  - perímetro de triángulos
  - área
  - baricentro
- Salida en consola estructurada como informe geométrico

---

## Estructura del proyecto

/proyecto
│
├── src/
│   ├── main.c
│   ├── leerPuntos.c
│   ├── imprimirPuntos.c
│   ├── leerTriangulos.c
│   ├── imprimirTriangulos.c
│   ├── geometria.c
│
├── include/
│   ├── estructuras.h
│   ├── memoria.h
│
├── lib/
│   ├── mifopen.c
│   ├── mimalloc.c
│   ├── mirealloc.c
│
├── data/
│   ├── puntos.txt
│   └── triangulos.txt

---

## Flujo del programa

1. Se leen los puntos desde fichero y se almacenan en memoria dinámica  
2. Se leen los triángulos y se enlazan con los puntos mediante punteros  
3. Se calculan propiedades geométricas de cada triángulo  
4. Se muestra la información en consola en formato estructurado  

---

## Compilación

Desde la raíz del proyecto:


gcc src/.c lib/.c -Iinclude -o triangulos -lm


---

## Ejecución


./triangulos


---

## Notas

- El proyecto sigue los requisitos de la asignatura:
  - uso de estructuras (`struct`)
  - uso de memoria dinámica
  - uso de la librería proporcionada en clase
- No se utilizan librerías externas ni funcionalidades fuera del temario
- La salida en consola se ha diseñado como un pequeño informe visual para facilitar la interpretación de los datos

---
