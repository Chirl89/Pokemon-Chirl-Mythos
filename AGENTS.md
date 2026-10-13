# Reglas y Órdenes Mandatarias del Agente: Pokémon Chirl Mythos

Estas directrices son obligatorias y perpetuas para toda interacción en este proyecto (Juego + Guía Web).

---

## 1. Saludo Obligatorio
* **SIEMPRE**, sin ninguna excepción, toda respuesta del agente debe comenzar con `Carlos, ` (ejemplo: `Carlos, he actualizado...` o `Carlos, a continuación te muestro...`).

---

## 2. Protocolo de Flujo de Trabajo y Comandos

### A. Comando "siguiente paso"
Cuando Carlos escriba `"siguiente paso"`:
1. **NO ejecutar ninguna acción de código ni modificar archivos.**
2. Mostrar la tabla completa y actualizada del `PLAN_DE_ACCION.md`.
3. Indicar el cambio de versión correspondiente según el protocolo.
4. Describir detalladamente justo debajo de la tabla el paso exacto que se va a realizar (objetivo, archivos/funciones en C/Poryscript involucrados, resultado esperado).
5. Preguntar explícitamente a Carlos si desea proceder.
6. Detener la ejecución a la espera de la confirmación expresa de Carlos.

### B. Comando "paso finalizado"
Cuando Carlos escriba `"paso finalizado"`:
1. Dar por terminado el punto actual, cambiando su estado a `implementado` en `PLAN_DE_ACCION.md`.
2. Registrar cualquier solución técnica comprobada o decisión de diseño en `LECCIONES_APRENDIDAS.md`.
3. Actualizar la versión en `version.json` y reflejar el cambio en la Guía Web (`guia_web/`).
4. Mostrar a Carlos la tabla del plan de acción actualizada con el nuevo estado.

---

## 3. Protocolo de Versionado Estricto y Sincronización Juego <-> Guía

1. **Fase de Desarrollo Siempre en `v0.x`**:
   - Mientras el juego esté en fase de desarrollo, la versión mantiene estrictamente el esquema `v0.X.Y`.
2. **Pasos Principales vs Iteraciones**:
   - **Nuevo Paso Principal del Plan**: Incrementa la versión menor (ejemplo: de `v0.1.0` a `v0.2.0`, o de `v0.9.0` a `v0.10.0`).
   - **Correcciones, parches y ajustes dentro de un paso**: Incrementa la subversión (ejemplo: de `v0.2.0` a `v0.2.1` -> `v0.2.2`).
3. **Alineación Obligatoria Juego <-> Guía Web**:
   - La versión registrada en `version.json`, la ROM compilada y la Guía Web (`guia_web/`) **DEBEN ser idénticas y coincidir en todo momento**.
   - Cualquier cambio funcional (habilidades, tiendas, evoluciones, legendarios) se documenta inmediatamente en la Guía Web en esa misma iteración.
4. **Sincronización Git**:
   - Cada paso consolidado se sincroniza con commits semánticos y push a los repositorios correspondientes (`Pokemon-Chirl-Mythos` y `Pokemon-Chirl-Mythos-Guia`).

---

## 4. Instrucciones de Verificación y Pruebas
* En cada funcionalidad comprobable, explicar detalladamente a Carlos qué se puede probar y cómo probarlo paso a paso en el emulador (RetroArch con core `mGBA`):
  - Comandos de compilación en Ubuntu/WSL: `make -j$(nproc)`.
  - Acción a realizar en el juego.
  - Resultado exacto observable.

---

## 5. Estructura de la Tabla del Plan (`PLAN_DE_ACCION.md`)
La tabla debe mantener estrictamente las 4 columnas:
`| número de punto | punto | breve descripción | estado (implementado, en curso, pendiente) |`
* Estados válidos: `implementado`, `en curso`, `pendiente`.

---

## 6. Registro Perpetuo de Lecciones Aprendidas (`LECCIONES_APRENDIDAS.md`)
* Si durante la implementación se prueban alternativas o se descartan vías erróneas, se documenta de inmediato en `LECCIONES_APRENDIDAS.md`.
* Ante cualquier tarea posterior similar, el agente debe consultar primero este archivo e iniciar directamente por la solución comprobada.
