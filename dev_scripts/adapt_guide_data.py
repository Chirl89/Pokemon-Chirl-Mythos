import json
import re

def main():
    # 1. Load wild encounters
    with open('src/data/wild_encounters.json', 'r', encoding='utf-8') as f:
        enc_raw = json.load(f)

    headers = enc_raw['wild_encounter_groups'][0]['encounters']
    
    # Map from MAP_CONSTANT to friendly name and region
    map_names = {
        "MAP_ROUTE29_HNS": "Ruta 29",
        "MAP_ROUTE30_HNS": "Ruta 30",
        "MAP_ROUTE31_HNS": "Ruta 31",
        "MAP_ROUTE32_HNS": "Ruta 32",
        "MAP_ROUTE33_HNS": "Ruta 33",
        "MAP_ROUTE34_HNS": "Ruta 34",
        "MAP_ROUTE35_HNS": "Ruta 35",
        "MAP_ROUTE36_HNS": "Ruta 36",
        "MAP_ROUTE37_HNS": "Ruta 37",
        "MAP_ROUTE38_HNS": "Ruta 38",
        "MAP_ROUTE39_HNS": "Ruta 39",
        "MAP_ROUTE40_HNS": "Ruta 40",
        "MAP_ROUTE41_HNS": "Ruta 41",
        "MAP_ROUTE42_HNS": "Ruta 42",
        "MAP_ROUTE43_HNS": "Ruta 43",
        "MAP_ROUTE44_HNS": "Ruta 44",
        "MAP_ROUTE45_HNS": "Ruta 45",
        "MAP_ROUTE46_HNS": "Ruta 46",
        "MAP_ROUTE47_HNS": "Ruta 47",
        "MAP_ROUTE48_HNS": "Ruta 48",
        "MAP_CHERRYGROVE_CITY_HNS": "Ciudad Cerezo",
        "MAP_VIOLET_CITY_HNS": "Ciudad Malva",
        "MAP_AZALEA_TOWN_HNS": "Pueblo Azalea",
        "MAP_GOLDENROD_CITY_HNS": "Ciudad Trigal",
        "MAP_ECRUTEAK_CITY_HNS": "Ciudad Iris",
        "MAP_OLIVINE_CITY_HNS": "Ciudad Olivo",
        "MAP_CIANWOOD_CITY_HNS": "Ciudad Orquídea",
        "MAP_MAHOGANY_TOWN_HNS": "Pueblo Caoba",
        "MAP_BLACKTHORN_CITY_HNS": "Ciudad Endrino",
        "MAP_DARK_CAVE_SOUTH_SIDE_HNS": "Cueva Oscura (Sur)",
        "MAP_DARK_CAVE_NORTH_SIDE_HNS": "Cueva Oscura (Norte)",
        "MAP_UNION_CAVE_1F_HNS": "Cueva Unión (1F)",
        "MAP_UNION_CAVE_B1F_HNS": "Cueva Unión (B1F)",
        "MAP_UNION_CAVE_B2F_HNS": "Cueva Unión (B2F)",
        "MAP_SLOWPOKE_WELL_B1F_HNS": "Pozo Slowpoke (B1F)",
        "MAP_SLOWPOKE_WELL_B2F_HNS": "Pozo Slowpoke (B2F)",
        "MAP_ILEX_FOREST_HNS": "Encinar",
        "MAP_NATIONAL_PARK_HNS": "Parque Nacional",
        "MAP_BURNED_TOWER_1F_HNS": "Torre Quemada (1F)",
        "MAP_BURNED_TOWER_B1F_HNS": "Torre Quemada (Sótano)",
        "MAP_BELL_TOWER_1F_HNS": "Torre Campana",
        "MAP_WHIRL_ISLANDS_1F_HNS": "Islas Remolino",
        "MAP_MT_MORTAR_1F_OUTSIDE_HNS": "Monte Mortero",
        "MAP_ICE_PATH_1F_HNS": "Ruta Helada",
        "MAP_DRAGONS_DEN_CAVERN_HNS": "Guarida Dragón",
        "MAP_MT_SILVER_OUTSIDE_HNS": "Monte Plateado (Exterior)",
        "MAP_MT_SILVER_CAVE_ROOM1_HNS": "Monte Plateado (Interior)",
        "MAP_MT_SILVER_SUMMIT_HNS": "Monte Plateado (Cima)",
        "MAP_ROUTE26_HNS": "Ruta 26",
        "MAP_ROUTE27_HNS": "Ruta 27",
        "MAP_ROUTE28_HNS": "Ruta 28",
        "MAP_TOHJO_FALLS_HNS": "Cataratas Tohjo",
        "MAP_VICTORY_ROAD_1F_HNS": "Calle Victoria (1F)",
        "MAP_VICTORY_ROAD_2F_HNS": "Calle Victoria (2F)",
        "MAP_VICTORY_ROAD_3F_HNS": "Calle Victoria (3F)",
        "MAP_INDIGO_PLATEAU_HNS": "Meseta Añil",
    }

    # Extract encounter rates
    # Land slots in pokeemerald typically: [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1]
    land_rates = [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1]
    water_rates = [60, 30, 5, 4, 1]

    # Map encounters
    extracted_routes = {}

    for enc in headers:
        m = enc.get('map', '')
        if m in map_names:
            friendly = map_names[m]
            base_label = enc.get('base_label', '')
            tod = 'Día' if 'Day' in base_label else ('Noche' if 'Night' in base_label else 'Todo el día')
            
            if friendly not in extracted_routes:
                extracted_routes[friendly] = {
                    "name": friendly,
                    "region": "Kanto" if any(k in friendly for k in ["Ruta 26", "Ruta 27", "Ruta 28", "Calle Victoria", "Meseta Añil"]) else "Johto",
                    "encounters": []
                }
            
            # Land mons
            if 'land_mons' in enc and 'mons' in enc['land_mons']:
                mons = enc['land_mons']['mons']
                for idx, mon in enumerate(mons):
                    rate = land_rates[idx] if idx < len(land_rates) else 5
                    sp = mon['species'].replace('SPECIES_', '').replace('_', ' ').title()
                    min_l = mon.get('min_level', 1)
                    max_l = mon.get('max_level', 1)
                    extracted_routes[friendly]["encounters"].append({
                        "pokemon": sp,
                        "method": f"Hierba alta ({tod})",
                        "rate": f"{rate}%",
                        "levels": f"Nv. {min_l}-{max_l}" if min_l != max_l else f"Nv. {min_l}"
                    })

            # Water mons
            if 'water_mons' in enc and 'mons' in enc['water_mons']:
                mons = enc['water_mons']['mons']
                for idx, mon in enumerate(mons):
                    rate = water_rates[idx] if idx < len(water_rates) else 10
                    sp = mon['species'].replace('SPECIES_', '').replace('_', ' ').title()
                    min_l = mon.get('min_level', 1)
                    max_l = mon.get('max_level', 1)
                    extracted_routes[friendly]["encounters"].append({
                        "pokemon": sp,
                        "method": "Surf",
                        "rate": f"{rate}%",
                        "levels": f"Nv. {min_l}-{max_l}" if min_l != max_l else f"Nv. {min_l}"
                    })

            # Fishing mons
            if 'fishing_mons' in enc and 'mons' in enc['fishing_mons']:
                mons = enc['fishing_mons']['mons']
                for idx, mon in enumerate(mons):
                    sp = mon['species'].replace('SPECIES_', '').replace('_', ' ').title()
                    min_l = mon.get('min_level', 1)
                    max_l = mon.get('max_level', 1)
                    method = "Caña Vieja" if idx < 2 else ("Caña Buena" if idx < 5 else "Supercaña")
                    extracted_routes[friendly]["encounters"].append({
                        "pokemon": sp,
                        "method": f"Pesca ({method})",
                        "rate": "Variable",
                        "levels": f"Nv. {min_l}-{max_l}" if min_l != max_l else f"Nv. {min_l}"
                    })

    print(f"Extracted {len(extracted_routes)} routes with accurate encounters from GBA ROM!")
    
    # 2. Load existing guide data.js
    guide_data_path = '../Pokemon-Chirl-Mythos-Guia/js/data.js'
    with open(guide_data_path, 'r', encoding='utf-8') as f:
        guide_text = f.read()

    prefix = "window.CHIRLMYTHOS_DATA = window.CHIRLGOLD_DATA = "
    start_pos = guide_text.find(prefix)
    header_comment = guide_text[:start_pos]
    json_str = guide_text[start_pos + len(prefix):].rstrip().rstrip(';')

    data = json.loads(json_str)

    # 3. Update routes in data
    # Merge extracted encounters into data['routes']
    new_routes_list = []
    seen = set()

    # Keep existing route layout metadata (x, y, desc, connections) if present, but update encounters
    existing_by_name = {r['name']: r for r in data.get('routes', [])}

    for name, rdata in extracted_routes.items():
        seen.add(name)
        existing = existing_by_name.get(name, {})
        # deduplicate encounters
        dedup_enc = []
        enc_keys = set()
        for enc in rdata['encounters']:
            k = (enc['pokemon'], enc['method'], enc['levels'])
            if k not in enc_keys:
                enc_keys.add(k)
                dedup_enc.append(enc)
        
        new_routes_list.append({
            "name": name,
            "region": rdata["region"],
            "x": existing.get("x", 50),
            "y": existing.get("y", 50),
            "desc": existing.get("desc", f"Zona de la aventura en {rdata['region']}: {name}."),
            "connections": existing.get("connections", []),
            "encounters": dedup_enc
        })

    # Add any other routes from existing that were not HNS-specific
    for r in data.get('routes', []):
        if r['name'] not in seen:
            new_routes_list.append(r)

    data['routes'] = new_routes_list
    print(f"Total routes in updated data: {len(data['routes'])}")

    # 4. Update Features & QoL for Pokemon Chirl Mythos (GBA)
    data['features'] = {
        "qol": [
            "Motor Base GBA Descompilado (HD 2D): Desarrollado sobre la arquitectura de decompilación de Game Boy Advance con la región de Johto y Kanto recreada fielmente con gráficos nítidos y sin cuelgues.",
            "Motor de Combate Completo Gen 9 en GBA: División Físico/Especial por icono, tipo Hada introducido, movimientos y habilidades modernas actualizadas hasta la última generación.",
            "Velocidad de Diálogo Instantánea/Rápida: El texto fluye a máxima velocidad por defecto en todas las conversaciones y eventos.",
            "Animaciones de Combate Optimizadas: Entrada a batalla acelerada y transiciones ágiles para un combate dinámico.",
            "Omisión de Pausas de Texto: Eliminadas las demoras y pausas artificiales en diálogos de NPCs para una lectura fluida.",
            "Curación Exprés en Centros Pokémon: La Enfermera Joy atiende a tu equipo de forma directa y veloz, ahorrando tiempo en cada visita.",
            "Menús Limpios y Sin Distracciones: Supresión total de menús y opciones innecesarias de Nuzlocke y Randomizador; el juego está calibrado en su dificultad nativa.",
            "Sistema de Level Caps Estricto: Curva de dificultad equilibrada por cada medalla de gimnasio para garantizar combates estratégicos sin requerir grindeo excesivo.",
            "Progresión Limpia de EVs e IVs: Eliminadas las restricciones competitivas artificiales de EVs e IVs basadas en medallas, permitiendo un entrenamiento natural.",
            "Ciclo Día y Noche en Tiempo Real (RTC GBA): Encuentros salvajes diferenciados por franja horaria (mañana/día y noche) utilizando el reloj interno de GBA.",
            "Megaevoluciones en Combate GBA: Activa la transformación en combate pulsando START antes de seleccionar tu movimiento, tras equipar la correspondiente Megapiedra y portar el Mega-Aro.",
            "Controles Ergonómicos Nativos GBA: Soporte completo para mandos físicos (D-Pad, A, B, L, R, Start, Select) sin necesidad de emulación táctil ni doble pantalla.",
            "Traducción 100% en Castellano Oficial: Nombres de ataques, habilidades, objetos, lugares y diálogos adaptados a la localización oficial de Nintendo España y WikiDex."
        ],
        "bugs": [
            {
                "issue": "Emulador Recomendado para GBA",
                "fix": "Se recomienda encarecidamente utilizar mGBA (v0.10 o superior) en PC/Mac/Linux o RetroArch (mGBA core) para una emulación perfecta de sonido, vídeo y reloj en tiempo real."
            },
            {
                "issue": "Configuración del Reloj en Tiempo Real (RTC)",
                "fix": "Asegúrate de tener activada la opción 'Real Time Clock (RTC)' en tu emulador para que el ciclo de Día y Noche funcione de acuerdo con la hora local de tu equipo."
            },
            {
                "issue": "Tipo de Guardado GBA",
                "fix": "El tipo de guardado recomendado es Flash 128K o detección automática. Guarda la partida normalmente desde el menú START del juego."
            }
        ]
    }

    # 5. Update non_included
    data['non_included'] = [
        {
            "name": "Modos Nuzlocke y Randomizador en Menú",
            "reason": "Eliminados por diseño para preservar la experiencia de aventura pura y equilibrada."
        },
        {
            "name": "Restricciones Artificiales de EVs por Medalla",
            "reason": "Eliminadas para volver al sistema clásico y natural de entrenamiento."
        },
        {
            "name": "Pantalla Táctil y Funciones NDS",
            "reason": "No aplican: el juego está construido nativamente para Game Boy Advance (GBA)."
        }
    ]

    # 6. Save back to js/data.js
    new_json = json.dumps(data, ensure_ascii=False, indent=2)
    output_content = f"/* Pokémon Chirl Mythos v0.2.5 - Base de Datos Oficial */\nwindow.CHIRLMYTHOS_VERSION = \"v0.2.5\";\nwindow.CHIRLGOLD_VERSION = window.CHIRLMYTHOS_VERSION;\n{prefix}{new_json};\n"

    with open(guide_data_path, 'w', encoding='utf-8') as f:
        f.write(output_content)

    print("Successfully wrote updated, authentic GBA data to Pokemon-Chirl-Mythos-Guia/js/data.js!")

if __name__ == '__main__':
    main()
