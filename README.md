<h1 align="center">ANALIZADOR DE TRIANGULOS</h1>
<p align="center">Análisis geométrico de malla triangular en C</p>

## Tech Stack

<p align="center">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" width="60" />
</p>

<p align="center">
  <b>Lenguaje:</b> C<br>
  <b>Conceptos:</b> Estructuras, punteros, memoria dinámica<br>
  <b>Librerías:</b> mimalloc, mirealloc, mifopen
</p>

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

```text
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
```

## Flujo del programa

1. Se leen los puntos desde fichero y se almacenan en memoria dinámica  
2. Se leen los triángulos y se enlazan con los puntos mediante punteros  
3. Se calculan propiedades geométricas de cada triángulo  
4. Se muestra la información en consola en formato estructurado  

---
