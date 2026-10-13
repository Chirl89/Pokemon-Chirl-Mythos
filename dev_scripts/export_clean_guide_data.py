import json
import re
import glob
import os

def load_types_map():
    return {
        "TYPE_NORMAL": "Normal",
        "TYPE_FIGHTING": "Lucha",
        "TYPE_FLYING": "Volador",
        "TYPE_POISON": "Veneno",
        "TYPE_GROUND": "Tierra",
        "TYPE_ROCK": "Roca",
        "TYPE_BUG": "Bicho",
        "TYPE_GHOST": "Fantasma",
        "TYPE_STEEL": "Acero",
        "TYPE_MYSTERY": "Desconocido",
        "TYPE_FIRE": "Fuego",
        "TYPE_WATER": "Agua",
        "TYPE_GRASS": "Planta",
        "TYPE_ELECTRIC": "Eléctrico",
        "TYPE_PSYCHIC": "Psíquico",
        "TYPE_ICE": "Hielo",
        "TYPE_DRAGON": "Dragón",
        "TYPE_DARK": "Siniestro",
        "TYPE_FAIRY": "Hada",
        "TYPE_STELLAR": "Terapápago"
    }

def load_abilities():
    abilities = {}
    with open('src/data/abilities.h', 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # [ABILITY_XYZ] = { .name = _("NAME"), .description = ... }
    blocks = content.split('\n    [ABILITY_')
    for b in blocks[1:]:
        const_name = 'ABILITY_' + b.split(']')[0].strip()
        name_m = re.search(r'\.name\s*=\s*_\(\"([^\"]+)\"\)', b)
        desc_m = re.search(r'\.description\s*=\s*(?:COMPOUND_STRING\(_?\"([^\"]+)\"\)|_\(\"([^\"]+)\"\)|s([A-Za-z0-9_]+)Description)', b)
        
        name = name_m.group(1).title() if name_m else const_name.replace('ABILITY_', '').replace('_', ' ').title()
        desc = "Habilidad de combate."
        if desc_m:
            if desc_m.group(1):
                desc = desc_m.group(1).replace('\n', ' ')
            elif desc_m.group(2):
                desc = desc_m.group(2).replace('\n', ' ')
        abilities[const_name] = {
            "name": name,
            "desc": desc
        }
    print(f"Loaded {len(abilities)} abilities from abilities.h")
    return abilities

def load_moves(types_map):
    moves = {}
    with open('src/data/moves_info.h', 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    blocks = content.split('\n    [MOVE_')
    for b in blocks[1:]:
        const_name = 'MOVE_' + b.split(']')[0].strip()
        name_m = re.search(r'\.name\s*=\s*(?:COMPOUND_STRING\(_?\"([^\"]+)\"\)|_\(\"([^\"]+)\"\))', b)
        power_m = re.search(r'\.power\s*=\s*([0-9]+)', b)
        acc_m = re.search(r'\.accuracy\s*=\s*([0-9]+)', b)
        pp_m = re.search(r'\.pp\s*=\s*([0-9]+)', b)
        type_m = re.search(r'\.type\s*=\s*(TYPE_[A-Z0-9_]+)', b)
        cat_m = re.search(r'\.category\s*=\s*(DAMAGE_CATEGORY_[A-Z0-9_]+)', b)
        
        name = name_m.group(1).title() if name_m else const_name.replace('MOVE_', '').replace('_', ' ').title()
        power = int(power_m.group(1)) if power_m else 0
        acc = int(acc_m.group(1)) if acc_m else 0
        pp = int(pp_m.group(1)) if pp_m else 0
        t_raw = type_m.group(1) if type_m else "TYPE_NORMAL"
        t_es = types_map.get(t_raw, "Normal")
        
        cat_raw = cat_m.group(1) if cat_m else "DAMAGE_CATEGORY_PHYSICAL"
        cat_es = "Físico"
        if "SPECIAL" in cat_raw:
            cat_es = "Especial"
        elif "STATUS" in cat_raw:
            cat_es = "Estado"

        moves[const_name] = {
            "name": name,
            "type": t_es,
            "category": cat_es,
            "power": power,
            "accuracy": acc,
            "pp": pp,
            "desc": f"Movimiento de tipo {t_es} ({cat_es}). Potencia: {power if power > 0 else '-'}, Precisión: {acc if acc > 0 else '-'}%, PP: {pp}."
        }
    print(f"Loaded {len(moves)} moves from moves_info.h")
    return moves

def load_learnsets(moves_dict):
    learnsets = {}
    for fpath in glob.glob('src/data/pokemon/level_up_learnsets/gen_*.h'):
        with open(fpath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # static const struct LevelUpMove sBulbasaurLevelUpLearnset[] = { ... };
        matches = re.finditer(r'static const struct LevelUpMove\s+(s[A-Za-z0-9_]+LevelUpLearnset)\[\]\s*=\s*\{([^;]+)\};', content)
        for m in matches:
            set_name = m.group(1)
            body = m.group(2)
            move_entries = []
            move_matches = re.finditer(r'LEVEL_UP_MOVE\(\s*([0-9]+)\s*,\s*(MOVE_[A-Z0-9_]+)\)', body)
            for mm in move_matches:
                lvl = int(mm.group(1))
                mv_const = mm.group(2)
                mv_info = moves_dict.get(mv_const, {"name": mv_const.replace('MOVE_', '').replace('_', ' ').title(), "type": "Normal", "category": "Físico", "power": 0, "pp": 0})
                move_entries.append({
                    "level": lvl,
                    "move": mv_info["name"],
                    "type": mv_info.get("type", "Normal"),
                    "category": mv_info.get("category", "Físico"),
                    "power": mv_info.get("power", 0),
                    "pp": mv_info.get("pp", 0)
                })
            learnsets[set_name] = move_entries
    print(f"Loaded {len(learnsets)} learnsets")
    return learnsets

def load_species_info(types_map, abilities_dict):
    species = {}
    for fpath in glob.glob('src/data/pokemon/species_info/gen_*_families.h'):
        with open(fpath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()

        chunks = content.split('\n    [SPECIES_')
        for c in chunks[1:]:
            sp_const = 'SPECIES_' + c.split(']')[0].strip()
            
            # Name
            name_m = re.search(r'\.speciesName\s*=\s*_\(\"([^\"]+)\"\)', c)
            name = name_m.group(1).title() if name_m else sp_const.replace('SPECIES_', '').replace('_', ' ').title()
            
            # NatDex
            dex_m = re.search(r'\.natDexNum\s*=\s*NATIONAL_DEX_([A-Z0-9_]+)', c)
            # Stats
            hp = int(re.search(r'\.baseHP\s*=\s*([0-9]+)', c).group(1)) if re.search(r'\.baseHP\s*=\s*([0-9]+)', c) else 50
            atk = int(re.search(r'\.baseAttack\s*=\s*([0-9]+)', c).group(1)) if re.search(r'\.baseAttack\s*=\s*([0-9]+)', c) else 50
            defe = int(re.search(r'\.baseDefense\s*=\s*([0-9]+)', c).group(1)) if re.search(r'\.baseDefense\s*=\s*([0-9]+)', c) else 50
            spe = int(re.search(r'\.baseSpeed\s*=\s*([0-9]+)', c).group(1)) if re.search(r'\.baseSpeed\s*=\s*([0-9]+)', c) else 50
            spa = int(re.search(r'\.baseSpAttack\s*=\s*([0-9]+)', c).group(1)) if re.search(r'\.baseSpAttack\s*=\s*([0-9]+)', c) else 50
            spd = int(re.search(r'\.baseSpDefense\s*=\s*([0-9]+)', c).group(1)) if re.search(r'\.baseSpDefense\s*=\s*([0-9]+)', c) else 50
            total = hp + atk + defe + spe + spa + spd
            
            # Types
            types = []
            types_m = re.search(r'\.types\s*=\s*MON_TYPES\((.*?)\)', c)
            if types_m:
                for t_raw in re.findall(r'TYPE_[A-Z0-9_]+', types_m.group(1)):
                    if t_raw in types_map and types_map[t_raw] not in types:
                        types.append(types_map[t_raw])
            if not types:
                types = ["Normal"]

            # Abilities
            abilities = []
            ab_m = re.search(r'\.abilities\s*=\s*\{([^}]+)\}', c)
            if ab_m:
                for ab_const in re.findall(r'ABILITY_[A-Z0-9_]+', ab_m.group(1)):
                    if ab_const != "ABILITY_NONE" and ab_const in abilities_dict:
                        ab_name = abilities_dict[ab_const]["name"]
                        if ab_name not in abilities:
                            abilities.append(ab_name)

            # Learnset pointer
            ls_m = re.search(r'\.levelUpLearnset\s*=\s*(s[A-Za-z0-9_]+LevelUpLearnset)', c)
            learnset_ptr = ls_m.group(1) if ls_m else None

            # Evolutions
            evo_targets = []
            evo_m = re.search(r'\.evolutions\s*=\s*EVOLUTION\((.*?)\)', c, re.DOTALL)
            evolutions_text = []
            if evo_m:
                evo_body = evo_m.group(1)
                # match each {EVO_TYPE, ARG, TARGET_SPECIES}
                single_evos = re.findall(r'\{([A-Z0-9_]+)\s*,\s*([^,]+)\s*,\s*(SPECIES_[A-Z0-9_]+)[^\}]*\}', evo_body)
                for etype, earg, etarget in single_evos:
                    evo_targets.append(etarget)
                    target_name = etarget.replace('SPECIES_', '').replace('_', ' ').title()
                    if etype == "EVO_LEVEL":
                        evolutions_text.append(f"Evoluciona a {target_name} (Nivel {earg.strip()})")
                    elif etype == "EVO_ITEM":
                        item_name = earg.replace('ITEM_', '').replace('_', ' ').title()
                        evolutions_text.append(f"Evoluciona a {target_name} ({item_name})")
                    elif etype == "EVO_FRIENDSHIP":
                        evolutions_text.append(f"Evoluciona a {target_name} (Amistad alta)")
                    elif etype == "EVO_TRADE":
                        evolutions_text.append(f"Evoluciona a {target_name} (Intercambio / Cordón Unión)")
                    elif etype == "EVO_MOVE":
                        move_name = earg.replace('MOVE_', '').replace('_', ' ').title()
                        evolutions_text.append(f"Evoluciona a {target_name} (Conocer {move_name})")
                    else:
                        evolutions_text.append(f"Evoluciona a {target_name}")

            species[sp_const] = {
                "const": sp_const,
                "name": name,
                "types": types,
                "stats": {
                    "hp": hp,
                    "atk": atk,
                    "def": defe,
                    "spe": spe,
                    "spa": spa,
                    "spd": spd,
                    "total": total
                },
                "abilities": abilities,
                "learnset_ptr": learnset_ptr,
                "evo_targets": evo_targets,
                "evolutions_text": evolutions_text
            }
    print(f"Loaded {len(species)} species definitions from species_info")
    return species

def main():
    types_map = load_types_map()
    abilities_dict = load_abilities()
    moves_dict = load_moves(types_map)
    learnsets_dict = load_learnsets(moves_dict)
    species_dict = load_species_info(types_map, abilities_dict)

    # 1. Parse wild encounters and map each pokemon to routes
    with open('src/data/wild_encounters.json', 'r', encoding='utf-8') as f:
        enc_raw = json.load(f)

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

    land_rates = [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1]
    water_rates = [60, 30, 5, 4, 1]

    pokemon_encounters = {} # SPECIES_CONST -> [ { route, method, rate, levels } ]
    wild_species_set = set()

    headers = enc_raw['wild_encounter_groups'][0]['encounters']
    for enc in headers:
        m = enc.get('map', '')
        if m in map_names:
            route_name = map_names[m]
            base_label = enc.get('base_label', '')
            tod = 'Día' if 'Day' in base_label else ('Noche' if 'Night' in base_label else 'Cualquiera')
            
            # Land
            if 'land_mons' in enc and 'mons' in enc['land_mons']:
                for idx, mon in enumerate(enc['land_mons']['mons']):
                    sp = mon['species']
                    wild_species_set.add(sp)
                    rate = land_rates[idx] if idx < len(land_rates) else 5
                    min_l = mon.get('min_level', 1)
                    max_l = mon.get('max_level', 1)
                    lvl_str = f"Nv. {min_l}-{max_l}" if min_l != max_l else f"Nv. {min_l}"
                    if sp not in pokemon_encounters:
                        pokemon_encounters[sp] = []
                    pokemon_encounters[sp].append({
                        "route": route_name,
                        "method": f"Hierba alta ({tod})",
                        "rate": f"{rate}%",
                        "levels": lvl_str,
                        "time": lvl_str
                    })
            
            # Water
            if 'water_mons' in enc and 'mons' in enc['water_mons']:
                for idx, mon in enumerate(enc['water_mons']['mons']):
                    sp = mon['species']
                    wild_species_set.add(sp)
                    rate = water_rates[idx] if idx < len(water_rates) else 10
                    min_l = mon.get('min_level', 1)
                    max_l = mon.get('max_level', 1)
                    lvl_str = f"Nv. {min_l}-{max_l}" if min_l != max_l else f"Nv. {min_l}"
                    if sp not in pokemon_encounters:
                        pokemon_encounters[sp] = []
                    pokemon_encounters[sp].append({
                        "route": route_name,
                        "method": "Surf",
                        "rate": f"{rate}%",
                        "levels": lvl_str,
                        "time": lvl_str
                    })

            # Fishing
            if 'fishing_mons' in enc and 'mons' in enc['fishing_mons']:
                for idx, mon in enumerate(enc['fishing_mons']['mons']):
                    sp = mon['species']
                    wild_species_set.add(sp)
                    min_l = mon.get('min_level', 1)
                    max_l = mon.get('max_level', 1)
                    lvl_str = f"Nv. {min_l}-{max_l}" if min_l != max_l else f"Nv. {min_l}"
                    method = "Caña Vieja" if idx < 2 else ("Caña Buena" if idx < 5 else "Supercaña")
                    if sp not in pokemon_encounters:
                        pokemon_encounters[sp] = []
                    pokemon_encounters[sp].append({
                        "route": route_name,
                        "method": f"Pesca ({method})",
                        "rate": "Variable",
                        "levels": lvl_str,
                        "time": lvl_str
                    })

    # Also check other non-HNS maps in headers for wild species (like caves, towers, safari, etc.)
    for enc in headers:
        m = enc.get('map', '')
        for field in ['land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons']:
            if field in enc and 'mons' in enc[field]:
                for mon in enc[field]['mons']:
                    sp = mon['species']
                    wild_species_set.add(sp)

    print(f"Total wild species found across ROM: {len(wild_species_set)}")

    # 2. Add evolution families
    obtainable_set = set(wild_species_set)
    # Forward evolutions
    changed = True
    while changed:
        changed = False
        for sp in list(obtainable_set):
            if sp in species_dict:
                for tgt in species_dict[sp]["evo_targets"]:
                    if tgt not in obtainable_set and tgt in species_dict:
                        obtainable_set.add(tgt)
                        changed = True

    # Pre-evolutions
    child_to_parent = {}
    for parent, sdata in species_dict.items():
        for ch in sdata["evo_targets"]:
            child_to_parent[ch] = parent

    for sp in list(obtainable_set):
        curr = sp
        while curr in child_to_parent:
            par = child_to_parent[curr]
            obtainable_set.add(par)
            curr = par

    print(f"Total obtainable species to display in Pokédex: {len(obtainable_set)}")

    # 3. Build pokemon list
    dex_num = 1
    final_pokemon = []
    
    # Sort obtainable by NatDex or name
    # Let's order by species_dict order
    ordered_species = [sp for sp in species_dict.keys() if sp in obtainable_set]

    for sp_const in ordered_species:
        sdata = species_dict[sp_const]
        
        # Deduplicate encounters
        encs = pokemon_encounters.get(sp_const, [])
        dedup_encs = []
        seen_enc = set()
        for e in encs:
            k = (e["route"], e["method"], e["levels"])
            if k not in seen_enc:
                seen_enc.add(k)
                dedup_encs.append(e)

        # Learnset
        ls_ptr = sdata["learnset_ptr"]
        learnset = learnsets_dict.get(ls_ptr, [])

        final_pokemon.append({
            "id": dex_num,
            "const": sp_const,
            "name": sdata["name"],
            "types": sdata["types"],
            "stats": sdata["stats"],
            "abilities": sdata["abilities"],
            "learnset": learnset,
            "encounters": dedup_encs,
            "evolutions_text": sdata["evolutions_text"],
            "slug": sdata["name"].lower().replace(' ', '-').replace('.', '')
        })
        dex_num += 1

    print(f"Generated {len(final_pokemon)} accurate Pokémon for Guide Pokédex!")

    # 4. Load existing data.js and replace pokemon and metadata
    guide_path = '../Pokemon-Chirl-Mythos-Guia/js/data.js'
    with open(guide_path, 'r', encoding='utf-8') as f:
        text = f.read()

    prefix = "window.CHIRLMYTHOS_DATA = window.CHIRLGOLD_DATA = "
    start = text.find(prefix)
    header_comment = text[:start]
    data = json.loads(text[start + len(prefix):].rstrip().rstrip(';'))

    data['pokemon'] = final_pokemon

    # Write back
    new_json = json.dumps(data, ensure_ascii=False, indent=2)
    output_content = f"{header_comment}{prefix}{new_json};\n"
    with open(guide_path, 'w', encoding='utf-8') as f:
        f.write(output_content)

    print("Successfully wrote 100% authentic, filtered Pokémon to guide data.js!")

if __name__ == '__main__':
    main()
