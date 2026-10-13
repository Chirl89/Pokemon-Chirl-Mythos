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

---

## 4. Gestión Eficiente de Compilaciones y Tokens
* **Delegación de compilación pesada en WSL:**
  - El escaneo de dependencias de `make` sobre el sistema de archivos montado `/mnt/c/` puede tomar minutos.
  - Para no malgastar tokens en temporizadores y comprobaciones reiteradas de estado, el agente no debe dejar tareas de compilación en espera cíclica.
  - Se prepara el código, se proporciona a Carlos el comando exacto para que lo ejecute en su terminal de Ubuntu/WSL, y Carlos avisa cuando el proceso concluye.

---

## 5. Localización de Tipos Elementales y Buffer `TYPE_NAME_LENGTH`
* **Error de longitud en `ELÉCTRICO` y `SINIESTRO`:**
  - *Problema:* En la base original en inglés, `TYPE_NAME_LENGTH` está fijado en 8 (para `ELECTRIC` y `FIGHTING`). Al traducir al español, `ELÉCTRICO` y `SINIESTRO` tienen 9 caracteres (+ terminador `EOS` = 10 bytes), lo que provocaba `error: excess elements in array initializer [-Werror]`.
  - *Solución Definitiva:* Modificar `#define TYPE_NAME_LENGTH 10` en `include/constants/global.h`. Es un array estático en ROM dentro de `struct TypeInfo`, no afecta al SaveBlock y permite nombres oficiales completos sin truncar ni abreviar.

---

## 6. Localización Masiva Oficial (WikiDex / Nintendo España)
* **Ampliación de buffers de texto:**
  - `MOVE_NAME_LENGTH` se amplió a 24 e `ITEM_NAME_LENGTH` a 24 en `include/constants/global.h` para albergar con total seguridad movimientos largos oficiales (ej. movimientos Z como *Aplastamiento Gigalítico*) y objetos compuestos en castellano.
* **Consistencia terminológica:**
  - Se utilizan exclusivamente los nombres canónicos de WikiDex / Nintendo España (ej. *Placaje*, *Lanzallamas*, *Poción*, *Mochila*, *Caja del PC*, *Guardar*, *Estilo de Combate Cambio/Fijo*), eliminando cualquier traducción literal o anglicismo.
* **Archivos maestros traducidos:**
  - `src/data/abilities.h`: 265 habilidades oficiales con descripciones en castellano.
  - `src/data/moves_info.h`: 788 nombres de movimientos oficiales WikiDex.
  - `src/data/items.h`: 620 nombres de objetos oficiales WikiDex.
  - `src/data/types_info.h`: 18 tipos elementales canónicos.
  - `src/pokemon.c`: 25 naturalezas canónicas.
  - `src/option_menu.c`: Opciones completas (menú, sonido, combate, acompañantes, marcos).
  - `src/pokemon_storage_system.c`: Sistema de almacenamiento y cajas del PC.
  - `src/battle_message.c`: Mensajes de combate y estados alterados.
  - `src/strings.c`: Bolsillos de mochila, menús de interfaz, guardado, tienda y datos.
  - `data/text/*.inc`: Discurso de apertura de Oak (`oak_speech_hns.inc`), enfermera Joy (`pkmn_center_nurse.inc`), empleados de tienda (`mart_clerk.inc`), obtención de objetos (`obtain_item.inc`), guardado (`save.inc`), surf (`surf.inc`), PC y transferencias (`pc.inc`, `pc_transfer.inc`) y tutor de movimientos (`move_relearner.inc`).
  - `data/event_scripts.s`: Arranque de PC doméstico, desmayo del jugador, curas domiciliarias y registro de llamadas del PokéGear.
  - `data/maps/*_hns/scripts.inc`: Mapas de inicio de Johto traducidos íntegramente (Casa del Protagonista 1F y 2F, Pueblo Primavera exterior, Laboratorio de Elm con elección de iniciales y cinemática del robo, Ruta 29 con tutorial de captura, Ciudad Cerezo con visita guiada y primer combate contra Silver, Ruta 30 con entrega del Huevo y Pokédex de Oak, y Ruta 31 hasta la entrada a Ciudad Malvalona).
* **Cadenas del motor C en intro e interfaz:**
  - El diálogo de Oak al mostrar a Wooper (*"Esto es lo que llamamos un “POKéMON”."*) no está en los scripts `.inc`, sino en la constante global `gText_ThisIsAPokemon` de `src/strings.c` (línea 47). Toda cadena mostrada por tareas del motor C debe localizarse en `src/strings.c` y `src/oak_speech_hns.c`.



