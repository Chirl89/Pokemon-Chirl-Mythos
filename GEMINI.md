# Instrucciones del Agente - Desarrollo del Juego

Documento de directrices y órdenes perpetuas para la asistencia en el desarrollo del nuevo juego.

---

## 1. Saludo Obligatorio
* **SIEMPRE**, sin ninguna excepción, toda respuesta del agente debe comenzar con `"Carlos, "` (ejemplo: `Carlos, he actualizado...` o `Carlos, a continuación te muestro...`).

---

## 2. Protocolo de Flujo de Trabajo y Comandos

### A. Comando "siguiente paso"
Cuando Carlos escriba `"siguiente paso"`:
1. **NO ejecutar ninguna acción de código ni modificar archivos.**
2. Mostrar la tabla completa y actualizada del `PLAN_DE_ACCION.md`.
3. Indicar el cambio de versión de paso (ejemplo: transición de versión `0.9` a `0.10`).
4. Describir detalladamente justo debajo de la tabla el paso exacto que se va a realizar (objetivo, componentes/arquitectura involucrada y resultado esperado).
5. Preguntar explícitamente a Carlos si desea proceder.
6. Detener la ejecución a la espera de la confirmación expresa de Carlos.

### B. Comando "paso finalizado"
Cuando Carlos escriba `"paso finalizado"`:
1. Dar por terminado el punto actual, cambiando su estado a `implementado` en `PLAN_DE_ACCION.md`.
2. Registrar cualquier solución técnica comprobada o decisión de diseño en `LECCIONES_APRENDIDAS.md`.
3. Mostrar a Carlos la tabla del plan de acción actualizada con el nuevo estado y la versión consolidada.

---

## 3. Sistema de Control de Versiones e Iteraciones
* **Versión de Paso (Hitos / Tareas del Plan):**
  - Cada vez que se inicie un nuevo paso del plan de acción, la versión principal de desarrollo avanzará en su segundo nivel (por ejemplo, de `0.9` a `0.10`, o de `0.10` a `0.11`).
* **Versión de Iteración (Modificaciones dentro del Paso):**
  - Cada ajuste, ciclo de prueba, corrección de bugs o iteración interna dentro del paso activo incrementará el tercer nivel de versión (por ejemplo, de `0.3.29` a `0.3.30`).
* **Visibilidad:** El número de versión e iteración actual debe reflejarse en los reportes de estado y en la documentación del plan.

---

## 4. Construcción y Estructura del Plan (`PLAN_DE_ACCION.md`)
* La tabla debe mantener estrictamente el siguiente esquema de 4 columnas:
  `| número de punto | punto | breve descripción | estado (implementado, en curso, pendiente) |`
* Los únicos estados válidos son: `implementado`, `en curso`, `pendiente`.
* Las transiciones de estado ocurren únicamente bajo los comandos `"siguiente paso"` (`en curso`) y `"paso finalizado"` (`implementado`).

---

## 5. Construcción y Registro de Lecciones Aprendidas (`LECCIONES_APRENDIDAS.md`)
* **Principio de aprendizaje continuo:** Si durante el desarrollo de una mecánica, renderizado, lógica o arquitectura del juego se descartan opciones o se prueban varias alternativas (por ejemplo, 4 fallan y la 5ª funciona), se debe documentar inmediatamente en `LECCIONES_APRENDIDAS.md`.
* **Consulta obligatoria:** Ante cualquier tarea o problema técnico posterior similar, el agente debe consultar primero este archivo para aplicar directamente la solución validada, sin repetir errores ni vías descartadas.

---

## 6. Instrucciones de Verificación, Pruebas y Creación de la Guía
* **Creación Obligatoria de la Guía de Pruebas:**
  - En cada funcionalidad, mecánica o avance entregado, el agente debe **crear y redactar una guía de pruebas paso a paso**.
  - La guía debe incluir: requisitos previos, comandos exactos de arranque/compilación, controles a probar y resultado visual/funcional esperado.
* **Visualización en Vivo:**
  - Lanzar y mostrar el juego en ejecución en pantalla en tiempo real para que Carlos pueda probarlo e inspeccionar los cambios directamente.

---

## 7. Gestión Automática de Git y Push
* **Responsabilidad Directa del Agente:** El agente es el responsable de gestionar el control de versiones con Git de manera proactiva.
* **Push Automático Obligatorio:** Siempre que se completen cambios, se generen commits o se finalicen tareas (tanto en el repositorio del juego `Pokemon-Chirl-Mythos` como en el de la guía web `Pokemon-Chirl-Mythos-Guia`), el agente debe ejecutar automáticamente `git push` a los repositorios remotos sin delegar esta tarea a Carlos.

---

## 8. Prohibición Absoluta de Compilación por el Agente
* **JAMÁS compilar:** El agente tiene terminantemente prohibido ejecutar comandos de compilación (`make`, scripts de build de la ROM, etc.).
* **Compilación exclusiva de Carlos:** La compilación del juego la realiza única y exclusivamente Carlos en su propio entorno.
* **Flujo tras la compilación:** El agente aplicará los cambios de código y esperará a que Carlos pruebe y compile. Cuando Carlos dé el aviso, el agente procederá a realizar el commit y `git push`.


