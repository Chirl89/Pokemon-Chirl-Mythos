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

def load_items_dict():
    items = {
        "ITEM_FIRE_STONE": "Piedra Fuego",
        "ITEM_WATER_STONE": "Piedra Agua",
        "ITEM_THUNDER_STONE": "Piedra Trueno",
        "ITEM_LEAF_STONE": "Piedra Hoja",
        "ITEM_MOON_STONE": "Piedra Lunar",
        "ITEM_SUN_STONE": "Piedra Solar",
        "ITEM_SHINY_STONE": "Piedra Día",
        "ITEM_DUSK_STONE": "Piedra Noche",
        "ITEM_DAWN_STONE": "Piedra Alba",
        "ITEM_ICE_STONE": "Piedra Hielo",
        "ITEM_LINKING_CORD": "Cordón Unión",
        "ITEM_KINGS_ROCK": "Roca del Rey",
        "ITEM_METAL_COAT": "Revestimiento Metálico",
        "ITEM_DRAGON_SCALE": "Escama Dragón",
        "ITEM_UP_GRADE": "Mejora",
        "ITEM_DUBIOUS_DISC": "Disco Extraño",
        "ITEM_PROTECTOR": "Protector",
        "ITEM_ELECTIRIZER": "Electrizador",
        "ITEM_MAGMARIZER": "Magmatizador",
        "ITEM_REAPER_CLOTH": "Tela Terrible",
        "ITEM_PRISM_SCALE": "Escama Bella",
        "ITEM_OVAL_STONE": "Piedra Oval",
        "ITEM_RAZOR_CLAW": "Garra Afilada",
        "ITEM_RAZOR_FANG": "Colmillo Afilado",
        "ITEM_DEEP_SEA_TOOTH": "Diente Marino",
        "ITEM_DEEP_SEA_SCALE": "Escama Marina",
        "ITEM_SWEET_APPLE": "Manzana Dulce",
        "ITEM_TART_APPLE": "Manzana Ácida",
        "ITEM_CRACKED_POT": "Tetera Rota",
        "ITEM_CHIPPED_POT": "Tetera Agrietada",
        "ITEM_GALARICA_CUFF": "Brazal Galanuez",
        "ITEM_GALARICA_WREATH": "Corona Galanuez",
        "ITEM_BLACK_AUGURITE": "Mineral Negro",
        "ITEM_PEAT_BLOCK": "Bloque Turba",
    }
    try:
        with open('src/data/items.h', 'r', encoding='utf-8', errors='ignore') as f:
            text = f.read()
        blocks = text.split('\n    [ITEM_')
        for b in blocks[1:]:
            item_const = 'ITEM_' + b.split(']')[0].strip()
            if item_const not in items:
                m = re.search(r'\.name\s*=\s*(?:ITEM_NAME|COMPOUND_STRING|_\()\s*\(\"([^\"]+)\"\)', b)
                if not m:
                    m = re.search(r'\.name\s*=\s*[A-Z_]*\(\"([^\"]+)\"\)', b)
                if m:
                    items[item_const] = m.group(1).title()
    except Exception as e:
        print("Warning loading items.h:", e)
    return items

def load_abilities():
    abilities = {}
    with open('src/data/abilities.h', 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
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

def load_moves(types_map, existing_moves_list):
    moves = {}
    # Build lookup from existing guide moves
    moves_by_name = { m["name"].lower(): m for m in existing_moves_list }
    
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
        
        raw_name = name_m.group(1).title() if name_m else const_name.replace('MOVE_', '').replace('_', ' ').title()
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

        # Check existing guide moves for exact ID and name
        existing = moves_by_name.get(raw_name.lower())
        mv_id = existing["id"] if existing else 0
        final_name = existing["name"] if existing else raw_name

        moves[const_name] = {
            "id": mv_id,
            "name": final_name,
            "type": existing.get("type", t_es) if existing else t_es,
            "category": existing.get("category", cat_es) if existing else cat_es,
            "power": existing.get("power", power) if existing else power,
            "accuracy": existing.get("accuracy", acc) if existing else acc,
            "pp": existing.get("pp", pp) if existing else pp,
            "desc": existing.get("desc", f"Movimiento de tipo {t_es}.") if existing else f"Movimiento de tipo {t_es}."
        }
    print(f"Loaded {len(moves)} moves from moves_info.h")
    return moves

def load_learnsets(moves_dict):
    learnsets = {}
    for fpath in glob.glob('src/data/pokemon/level_up_learnsets/gen_*.h'):
        with open(fpath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        matches = re.finditer(r'static const struct LevelUpMove\s+(s[A-Za-z0-9_]+LevelUpLearnset)\[\]\s*=\s*\{([^;]+)\};', content)
        for m in matches:
            set_name = m.group(1)
            body = m.group(2)
            move_entries = []
            move_matches = re.finditer(r'LEVEL_UP_MOVE\(\s*([0-9]+)\s*,\s*(MOVE_[A-Z0-9_]+)\)', body)
            for mm in move_matches:
                lvl = int(mm.group(1))
                mv_const = mm.group(2)
                mv_info = moves_dict.get(mv_const, {
                    "id": 0,
                    "name": mv_const.replace('MOVE_', '').replace('_', ' ').title(),
                    "type": "Normal",
                    "category": "Físico",
                    "power": 0,
                    "accuracy": 0,
                    "pp": 0
                })
                move_entries.append({
                    "id": mv_info.get("id", 0),
                    "lvl": lvl,
                    "level": lvl,
                    "name": mv_info["name"],
                    "move": mv_info["name"],
                    "type": mv_info.get("type", "Normal"),
                    "cat": mv_info.get("category", "Físico"),
                    "category": mv_info.get("category", "Físico"),
                    "power": mv_info.get("power", 0),
                    "acc": mv_info.get("accuracy", 0),
                    "accuracy": mv_info.get("accuracy", 0),
                    "pp": mv_info.get("pp", 0)
                })
            learnsets[set_name] = move_entries
    print(f"Loaded {len(learnsets)} learnsets")
    return learnsets

def load_species_info(types_map, abilities_dict, items_dict, moves_dict):
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
            evolutions_list = []
            evolutions_text = []
            evo_m = re.search(r'\.evolutions\s*=\s*EVOLUTION\((.*?)\)', c, re.DOTALL)
            if evo_m:
                evo_body = evo_m.group(1)
                single_evos = re.findall(r'\{([A-Z0-9_]+)\s*,\s*([^,]+)\s*,\s*(SPECIES_[A-Z0-9_]+)[^\}]*\}', evo_body, re.DOTALL)
                for etype, earg, etarget in single_evos:
                    earg_clean = earg.strip()
                    evo_targets.append(etarget)
                    target_name = etarget.replace('SPECIES_', '').replace('_', ' ').title()

                    method_str = "Evolución"
                    method_type = "level"
                    item_str = None
                    move_str = None

                    if etype == "EVO_LEVEL":
                        method_str = f"Nivel {earg_clean}"
                        method_type = "level"
                        evolutions_text.append(f"Evoluciona a {target_name} (Nivel {earg_clean})")
                    elif etype == "EVO_LEVEL_DAY":
                        method_str = f"Nivel {earg_clean} (Día)"
                        method_type = "level"
                        evolutions_text.append(f"Evoluciona a {target_name} (Nivel {earg_clean}, Día)")
                    elif etype == "EVO_LEVEL_NIGHT":
                        method_str = f"Nivel {earg_clean} (Noche)"
                        method_type = "level"
                        evolutions_text.append(f"Evoluciona a {target_name} (Nivel {earg_clean}, Noche)")
                    elif etype == "EVO_LEVEL_FEMALE":
                        method_str = f"Nivel {earg_clean} (Hembra)"
                        method_type = "level"
                        evolutions_text.append(f"Evoluciona a {target_name} (Nivel {earg_clean}, Hembra)")
                    elif etype == "EVO_LEVEL_MALE":
                        method_str = f"Nivel {earg_clean} (Macho)"
                        method_type = "level"
                        evolutions_text.append(f"Evoluciona a {target_name} (Nivel {earg_clean}, Macho)")
                    elif etype == "EVO_ITEM":
                        item_str = items_dict.get(earg_clean, earg_clean.replace('ITEM_', '').replace('_', ' ').title())
                        method_str = item_str
                        method_type = "item"
                        evolutions_text.append(f"Evoluciona a {target_name} ({item_str})")
                    elif etype == "EVO_FRIENDSHIP":
                        method_str = "Amistad"
                        method_type = "friendship"
                        evolutions_text.append(f"Evoluciona a {target_name} (Amistad alta)")
                    elif etype == "EVO_FRIENDSHIP_DAY":
                        method_str = "Amistad (Día)"
                        method_type = "friendship"
                        evolutions_text.append(f"Evoluciona a {target_name} (Amistad alta, Día)")
                    elif etype == "EVO_FRIENDSHIP_NIGHT":
                        method_str = "Amistad (Noche)"
                        method_type = "friendship"
                        evolutions_text.append(f"Evoluciona a {target_name} (Amistad alta, Noche)")
                    elif etype == "EVO_TRADE":
                        method_str = "Cordón Unión"
                        method_type = "item"
                        item_str = "Cordón Unión"
                        evolutions_text.append(f"Evoluciona a {target_name} (Cordón Unión / Intercambio)")
                    elif etype == "EVO_TRADE_ITEM":
                        item_str = items_dict.get(earg_clean, earg_clean.replace('ITEM_', '').replace('_', ' ').title())
                        method_str = item_str
                        method_type = "item"
                        evolutions_text.append(f"Evoluciona a {target_name} (Intercambio con {item_str})")
                    elif etype == "EVO_MOVE":
                        mv_obj = moves_dict.get(earg_clean, {})
                        mv_name = mv_obj.get("name", earg_clean.replace('MOVE_', '').replace('_', ' ').title())
                        method_str = f"Conocer {mv_name}"
                        method_type = "move"
                        move_str = mv_name
                        evolutions_text.append(f"Evoluciona a {target_name} (Conocer {mv_name})")
                    else:
                        method_str = "Evolución especial"
                        method_type = "special"
                        evolutions_text.append(f"Evoluciona a {target_name}")

                    evo_entry = {
                        "target_const": etarget,
                        "method": method_str,
                        "method_type": method_type
                    }
                    if item_str:
                        evo_entry["item"] = item_str
                    if move_str:
                        evo_entry["move"] = move_str
                    evolutions_list.append(evo_entry)

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
                "evolutions_list": evolutions_list,
                "evolutions_text": evolutions_text,
                "slug": name.lower().replace(' ', '-').replace('.', '')
            }
    print(f"Loaded {len(species)} species definitions from species_info")
    return species

def main():
    guide_path = '../Pokemon-Chirl-Mythos-Guia/js/data.js'
    with open(guide_path, 'r', encoding='utf-8') as f:
        guide_raw = f.read()

    prefix = "window.CHIRLMYTHOS_DATA = window.CHIRLGOLD_DATA = "
    start = guide_raw.find(prefix)
    header_comment = guide_raw[:start]
    guide_data = json.loads(guide_raw[start + len(prefix):].rstrip().rstrip(';'))

    types_map = load_types_map()
    items_dict = load_items_dict()
    abilities_dict = load_abilities()
    moves_dict = load_moves(types_map, guide_data.get('moves', []))
    learnsets_dict = load_learnsets(moves_dict)
    species_dict = load_species_info(types_map, abilities_dict, items_dict, moves_dict)

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
        "MAP_ROUTE26_HNS": "Ruta 26",
        "MAP_ROUTE27_HNS": "Ruta 27",
        "MAP_ROUTE28_HNS": "Ruta 28",
        "MAP_NEW_BARK_TOWN_HNS": "Pueblo Primavera",
        "MAP_CHERRYGROVE_CITY_HNS": "Ciudad Cerezo",
        "MAP_VIOLET_CITY_HNS": "Ciudad Malva",
        "MAP_AZALEA_TOWN_HNS": "Pueblo Azalea",
        "MAP_GOLDENROD_CITY_HNS": "Ciudad Trigal",
        "MAP_ECRUTEAK_CITY_HNS": "Ciudad Iris",
        "MAP_OLIVINE_CITY_HNS": "Ciudad Olivo",
        "MAP_CIANWOOD_CITY_HNS": "Ciudad Orquídea",
        "MAP_MAHOGANY_TOWN_HNS": "Pueblo Caoba",
        "MAP_BLACKTHORN_CITY_HNS": "Ciudad Endrino",
        "MAP_DARK_CAVE_VIOLET_ENTRANCE_HNS": "Cueva Oscura",
        "MAP_DARK_CAVE_BLACKTHORN_ENTRANCE_HNS": "Cueva Oscura",
        "MAP_UNION_CAVE_1F_HNS": "Cueva Unión",
        "MAP_UNION_CAVE_B1F_HNS": "Cueva Unión B1F",
        "MAP_UNION_CAVE_B2F_HNS": "Cueva Unión B2F",
        "MAP_ILEX_FOREST_HNS": "Encinar",
        "MAP_SLOWPOKE_WELL_B1F_HNS": "Pozo Slowpoke",
        "MAP_SLOWPOKE_WELL_B2F_HNS": "Pozo Slowpoke B2F",
        "MAP_SPROUT_TOWER_1F_HNS": "Torre Bellsprout",
        "MAP_SPROUT_TOWER_2F_HNS": "Torre Bellsprout 2F",
        "MAP_SPROUT_TOWER_3F_HNS": "Torre Bellsprout 3F",
        "MAP_BURNED_TOWER_1F_HNS": "Torre Quemada",
        "MAP_BURNED_TOWER_B1F_HNS": "Torre Quemada B1F",
        "MAP_BELL_TOWER_1F_HNS": "Torre Hojalata",
        "MAP_NATIONAL_PARK_HNS": "Parque Nacional",
        "MAP_NATIONAL_PARK_BUG_CONTEST_HNS": "Concurso de Bichos",
        "MAP_RUINS_OF_ALPH_OUTSIDE_HNS": "Ruinas Alfa",
        "MAP_RUINS_OF_ALPH_INNER_CHAMBER_HNS": "Cámara Ruinas Alfa",
        "MAP_MT_MORTAR_1F_OUTSIDE_HNS": "Monte Mortero",
        "MAP_MT_MORTAR_1F_INSIDE_HNS": "Monte Mortero",
        "MAP_MT_MORTAR_2F_INSIDE_HNS": "Monte Mortero 2F",
        "MAP_MT_MORTAR_B1F_HNS": "Monte Mortero B1F",
        "MAP_LAKE_OF_RAGE_HNS": "Lago de la Furia",
        "MAP_ICE_PATH_1F_HNS": "Ruta Helada",
        "MAP_ICE_PATH_B1F_HNS": "Ruta Helada B1F",
        "MAP_ICE_PATH_B2F_MAHOGANY_SIDE_HNS": "Ruta Helada B2F",
        "MAP_ICE_PATH_B2F_BLACKTHORN_SIDE_HNS": "Ruta Helada B2F",
        "MAP_ICE_PATH_B3F_HNS": "Ruta Helada B3F",
        "MAP_WHIRL_ISLANDS_1F_HNS": "Islas Remolino",
        "MAP_WHIRL_ISLANDS_B1F_HNS": "Islas Remolino B1F",
        "MAP_WHIRL_ISLANDS_B2F_HNS": "Islas Remolino B2F",
        "MAP_DRAGONS_DEN_HNS": "Guarida Dragón",
        "MAP_MT_SILVER_OUTSIDE_HNS": "Monte Plateado (Exterior)",
        "MAP_MT_SILVER_1F_HNS": "Monte Plateado 1F",
        "MAP_MT_SILVER_2F_HNS": "Monte Plateado 2F",
        "MAP_MT_SILVER_ITEM_ROOMS_HNS": "Monte Plateado",
        "MAP_VICTORY_ROAD_1F_HNS": "Calle Victoria 1F",
        "MAP_VICTORY_ROAD_2F_HNS": "Calle Victoria 2F",
        "MAP_VICTORY_ROAD_3F_HNS": "Calle Victoria 3F",
        "MAP_TOHJO_FALLS_HNS": "Cataratas Tohjo"
    }

    land_rates = [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1]
    water_rates = [60, 30, 5, 4, 1]
    rock_rates = [60, 30, 5, 4, 1]

    pokemon_encounters = {}
    wild_species_set = set()

    headers = enc_raw.get('wild_encounter_groups', [{}])[0].get('encounters', [])
    for enc in headers:
        m = enc.get('map', '')
        route_name = map_names.get(m, m.replace('MAP_', '').replace('_HNS', '').replace('_', ' ').title())

        # Land
        if 'land_mons' in enc and 'mons' in enc['land_mons']:
            mons = enc['land_mons']['mons']
            for idx, mon in enumerate(mons):
                sp = mon['species']
                wild_species_set.add(sp)
                rate = land_rates[idx] if idx < len(land_rates) else 5
                min_l = mon.get('min_level', 1)
                max_l = mon.get('max_level', 1)
                lvl_str = f"Nv. {min_l}-{max_l}" if min_l != max_l else f"Nv. {min_l}"
                time_str = "Hierba alta (Día)" if idx % 2 == 0 else "Hierba alta (Noche)"
                if sp not in pokemon_encounters:
                    pokemon_encounters[sp] = []
                pokemon_encounters[sp].append({
                    "route": route_name,
                    "method": time_str,
                    "rate": f"{rate}%",
                    "levels": lvl_str,
                    "time": lvl_str
                })

        # Water
        if 'water_mons' in enc and 'mons' in enc['water_mons']:
            mons = enc['water_mons']['mons']
            for idx, mon in enumerate(mons):
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

        # Rock Smash
        if 'rock_smash_mons' in enc and 'mons' in enc['rock_smash_mons']:
            mons = enc['rock_smash_mons']['mons']
            for idx, mon in enumerate(mons):
                sp = mon['species']
                wild_species_set.add(sp)
                rate = rock_rates[idx] if idx < len(rock_rates) else 10
                min_l = mon.get('min_level', 1)
                max_l = mon.get('max_level', 1)
                lvl_str = f"Nv. {min_l}-{max_l}" if min_l != max_l else f"Nv. {min_l}"
                if sp not in pokemon_encounters:
                    pokemon_encounters[sp] = []
                pokemon_encounters[sp].append({
                    "route": route_name,
                    "method": "Golpe Roca",
                    "rate": f"{rate}%",
                    "levels": lvl_str,
                    "time": lvl_str
                })

        # Fishing
        if 'fishing_mons' in enc and 'mons' in enc['fishing_mons']:
            mons = enc['fishing_mons']['mons']
            for idx, mon in enumerate(mons):
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

    for enc in headers:
        for field in ['land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons']:
            if field in enc and 'mons' in enc[field]:
                for mon in enc[field]['mons']:
                    wild_species_set.add(mon['species'])

    print(f"Total wild species found: {len(wild_species_set)}")

    # 2. Add full evolution families (forward and backward)
    obtainable_set = set(wild_species_set)
    changed = True
    while changed:
        changed = False
        for sp in list(obtainable_set):
            if sp in species_dict:
                for tgt in species_dict[sp]["evo_targets"]:
                    if tgt not in obtainable_set and tgt in species_dict:
                        obtainable_set.add(tgt)
                        changed = True

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

    print(f"Total obtainable species: {len(obtainable_set)}")

    # Assign IDs in consistent order
    ordered_species = [sp for sp in species_dict.keys() if sp in obtainable_set]
    sp_to_dex_id = {}
    for idx, sp in enumerate(ordered_species, 1):
        sp_to_dex_id[sp] = idx

    # Build parent -> evolutions list among obtainable species
    obtainable_child_to_parent = {}
    for sp in ordered_species:
        for evo in species_dict[sp]["evolutions_list"]:
            tgt = evo["target_const"]
            if tgt in obtainable_set:
                obtainable_child_to_parent[tgt] = sp

    def get_family_root(sp):
        curr = sp
        while curr in obtainable_child_to_parent:
            curr = obtainable_child_to_parent[curr]
        return curr

    def build_tree_node(sp_const, evo_info=None):
        sdata = species_dict[sp_const]
        node = {
            "id": sp_to_dex_id[sp_const],
            "name": sdata["name"],
            "types": sdata["types"],
            "slug": sdata["slug"],
            "evolves_to": []
        }
        if evo_info:
            node["method"] = evo_info.get("method", "Evolución")
            node["method_type"] = evo_info.get("method_type", "level")
            if "item" in evo_info:
                node["item"] = evo_info["item"]
            if "move" in evo_info:
                node["move"] = evo_info["move"]

        for evo in sdata["evolutions_list"]:
            tgt = evo["target_const"]
            if tgt in obtainable_set and tgt in species_dict:
                child_node = build_tree_node(tgt, evo)
                node["evolves_to"].append(child_node)

        return node

    # Pre-cache root tree for each family
    family_trees = {}
    for sp in ordered_species:
        root = get_family_root(sp)
        if root not in family_trees:
            root_tree = build_tree_node(root)
            # Check if root has any evolutions
            if root_tree["evolves_to"] or sp in obtainable_child_to_parent:
                family_trees[root] = [root_tree]
            else:
                family_trees[root] = []

    # 3. Build pokemon list
    final_pokemon = []
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

        root = get_family_root(sp_const)
        tree = family_trees.get(root, [])

        final_pokemon.append({
            "id": sp_to_dex_id[sp_const],
            "const": sp_const,
            "name": sdata["name"],
            "types": sdata["types"],
            "stats": sdata["stats"],
            "abilities": sdata["abilities"],
            "learnset": learnset,
            "encounters": dedup_encs,
            "family_tree": tree,
            "evolutions_text": sdata["evolutions_text"],
            "slug": sdata["slug"]
        })

    print(f"Generated {len(final_pokemon)} authentic Pokémon with complete family_tree and learnset!")
    
    # 4. Save to guide data.js
    guide_data['pokemon'] = final_pokemon
    new_json = json.dumps(guide_data, ensure_ascii=False, indent=2)
    output_content = f"{header_comment}{prefix}{new_json};\n"
    with open(guide_path, 'w', encoding='utf-8') as f:
        f.write(output_content)

    print("SUCCESS: Wrote 100% updated data.js with family_tree and resilient learnsets!")

if __name__ == '__main__':
    main()
