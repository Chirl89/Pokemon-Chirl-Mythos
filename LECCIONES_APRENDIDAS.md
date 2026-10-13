# Base de Conocimiento y Lecciones Aprendidas: Pokémon Chirl Mythos

Este documento registra los hallazgos técnicos, arquitecturas validadas, parches comprobados y soluciones definitivas para el desarrollo del juego en GBA Decomp.

> **Principio de Aprendizaje Continuo:**
> Si para una tarea se intentan múltiples soluciones, la que demuestre funcionar se registra aquí como referencia definitiva. Ante cualquier tarea posterior similar, se consulta este registro y se acude directamente a la solución probada sin repetir caminos fallidos.

---

## 1. Entorno de Compilación y Toolchain GBA
* **Compilador nativo en Ubuntu (WSL):**
  - No es necesario `devkitPro pacman` externo (que sufre bloqueos 403 por Cloudflare).
  - Los paquetes nativos de Ubuntu resuelven la compilación al 100%:
    ```bash
    sudo apt install -y gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi git
    ```
* **Configuración del Makefile para Johto/Kanto (HNS):**
  - Por defecto el repositorio base compila para `EMERALD`. Para fijar permanentemente la base HNS y firmar la ROM, se configuran las primeras líneas de `Makefile`:
    ```makefile
    GAME_VERSION ?= POKEMON_HNS
    TITLE        ?= POKEMON CHIRL
    GAME_CODE    ?= BPEE
    BUILD_NAME   ?= hns
    MAP_VERSION  ?= hns
    ```
  - Esto define `POKEMON_HNS` en la compilación y activa `IS_HNS = 1` en todo el código C.

---

## 2. Parches de Cabeceras HNS Resueltos
* **Error `FLAG_RECEIVED_TOGEPI_EGG` en `src/braille_puzzles.c`:**
  - *Problema:* El archivo usa la bandera del huevo de Togepi de Elm, definida exclusivamente en `constants/flags_hns.h`.
  - *Solución Definitiva:* Añadir `#include "constants/flags_hns.h"` en las cabeceras de `src/braille_puzzles.c`.
* **Error `momSavings` y `FLAG_MOM_HAS_GIFT` en `src/mom_savings.c`:**
  - *Problema:* `struct MomSavingsData momSavings;` dentro de `SaveBlock1` requiere `IS_HNS=1`, y la bandera `FLAG_MOM_HAS_GIFT` está en `flags_hns.h`.
  - *Solución Definitiva:* Configurar `Makefile` con `GAME_VERSION ?= POKEMON_HNS` e incluir `#include "constants/flags_hns.h"` en `src/mom_savings.c`.

---

## 3. Arquitectura del Espacio de Trabajo (Juego + Guía Web)
* **Unión de Directorios (Junction) en Windows:**
  - Para avanzar en paralelo con el juego y la guía web manteniendo repositorios Git independientes:
    ```cmd
    mklink /J C:\...\Pokemon-Chirl-Mythos\guia_web C:\...\Pokemon-Chirl-Mythos-Guia
    ```
  - En `.gitignore` de `Pokemon-Chirl-Mythos` se añade `guia_web/` para que el repositorio del juego no interfiera con el historial del repositorio de la guía.
