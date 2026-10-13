#!/usr/bin/env python3
import os
import re
import csv

CACHE_DIR = "dev_scripts/data_cache"

def load_abilities():
    id_to_ident = {}
    with open(f"{CACHE_DIR}/abilities.csv", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            c_name = "ABILITY_" + r["identifier"].upper().replace("-", "_")
            id_to_ident[r["id"]] = c_name

    names_es = {}
    with open(f"{CACHE_DIR}/ability_names.csv", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r["local_language_id"] == "7":
                c = id_to_ident.get(r["ability_id"])
                if c:
                    names_es[c] = r["name"].upper()

    desc_es = {}
    with open(f"{CACHE_DIR}/ability_flavor_text.csv", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r["language_id"] == "7":
                c = id_to_ident.get(r["ability_id"])
                if c and (c not in desc_es or int(r["version_group_id"]) in [15, 16, 17, 18]):
                    desc_es[c] = r["flavor_text"].replace("\n", " ").replace("\r", "").strip()

    return names_es, desc_es

def load_moves():
    id_to_ident = {}
    with open(f"{CACHE_DIR}/moves.csv", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            c_name = "MOVE_" + r["identifier"].upper().replace("-", "_")
            id_to_ident[r["id"]] = c_name

    names_es = {}
    with open(f"{CACHE_DIR}/move_names.csv", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r["local_language_id"] == "7":
                c = id_to_ident.get(r["move_id"])
                if c:
                    names_es[c] = r["name"].upper()

    desc_es = {}
    with open(f"{CACHE_DIR}/move_flavor_text.csv", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r["language_id"] == "7":
                c = id_to_ident.get(r["move_id"])
                if c and (c not in desc_es or int(r["version_group_id"]) in [10, 15, 16, 17]):
                    desc_es[c] = r["flavor_text"].replace("\n", " ").replace("\r", "").strip()

    return names_es, desc_es

def load_items():
    id_to_ident = {}
    with open(f"{CACHE_DIR}/items.csv", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            c_name = "ITEM_" + r["identifier"].upper().replace("-", "_")
            id_to_ident[r["id"]] = c_name

    names_es = {}
    with open(f"{CACHE_DIR}/item_names.csv", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r["local_language_id"] == "7":
                c = id_to_ident.get(r["item_id"])
                if c:
                    names_es[c] = r["name"].upper()

    desc_es = {}
    with open(f"{CACHE_DIR}/item_flavor_text.csv", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r["language_id"] == "7":
                c = id_to_ident.get(r["item_id"])
                if c and (c not in desc_es or int(r["version_group_id"]) in [10, 15, 16, 17]):
                    desc_es[c] = r["flavor_text"].replace("\n", " ").replace("\r", "").strip()

    return names_es, desc_es

def wrap_to_c_lines(text, max_len=26, max_lines=2):
    words = text.split()
    lines = []
    curr = []
    curr_len = 0
    for w in words:
        if curr_len + len(w) + (1 if curr else 0) <= max_len:
            curr.append(w)
            curr_len += len(w) + (1 if curr_len > 0 else 0)
        else:
            if curr:
                lines.append(" ".join(curr))
            curr = [w]
            curr_len = len(w)
    if curr:
        lines.append(" ".join(curr))
    
    if len(lines) > max_lines:
        lines = lines[:max_lines]
        # Append dot if needed
        if not lines[-1].endswith("."):
            lines[-1] = lines[-1].rstrip(",;") + "."

    if len(lines) == 1:
        return f'"{lines[0]}"'
    else:
        parts = [f'            "{l}\\n"' for l in lines[:-1]]
        parts.append(f'            "{lines[-1]}"')
        return "(\n" + "\n".join(parts) + ")"

def translate_abilities_file():
    names_es, desc_es = load_abilities()
    file_path = "src/data/abilities.h"
    with open(file_path, "r", encoding="utf-8") as f:
        content = f.read()

    count = 0
    def repl_block(m):
        nonlocal count
        ab_const = m.group(1)
        block = m.group(2)
        if ab_const in names_es:
            count += 1
            es_name = names_es[ab_const]
            block = re.sub(r'(\.name\s*=\s*_\(")[^"]*("\))', rf'\g<1>{es_name}\g<2>', block)
            if ab_const in desc_es:
                raw_desc = desc_es[ab_const]
                # Keep on single line without newlines to avoid formatting issues in summary box
                block = re.sub(r'(\.description\s*=\s*COMPOUND_STRING\(")[^"]*("\))', rf'\g<1>{raw_desc}\g<2>', block)
        return f"[{ab_const}] =\n    {{{block}}}"

    pattern = re.compile(r'\[(ABILITY_\w+)\]\s*=\s*\{([^}]+)\}', re.MULTILINE)
    new_content = pattern.sub(repl_block, content)
    with open(file_path, "w", encoding="utf-8") as f:
        f.write(new_content)
    print(f"[Abilities] Traducidas {count} habilidades en {file_path}")

def translate_moves_file():
    names_es, desc_es = load_moves()
    file_path = "src/data/moves_info.h"
    with open(file_path, "r", encoding="utf-8") as f:
        content = f.read()

    count = 0
    def repl_name(m):
        nonlocal count
        mv_const = m.group(1)
        if mv_const in names_es:
            count += 1
            es_name = names_es[mv_const]
            return f'[{mv_const}] =\n    {{\n        .name = COMPOUND_STRING("{es_name}"),'
        return m.group(0)

    pattern = re.compile(r'\[(MOVE_\w+)\]\s*=\s*\{\s*\.name\s*=\s*COMPOUND_STRING\("[^"]*"\),', re.MULTILINE)
    new_content = pattern.sub(repl_name, content)
    with open(file_path, "w", encoding="utf-8") as f:
        f.write(new_content)
    print(f"[Moves] Traducidos {count} nombres de movimientos en {file_path}")

def translate_items_file():
    names_es, desc_es = load_items()
    file_path = "src/data/items.h"
    with open(file_path, "r", encoding="utf-8") as f:
        content = f.read()

    count = 0
    def repl_name(m):
        nonlocal count
        it_const = m.group(1)
        if it_const in names_es:
            count += 1
            es_name = names_es[it_const]
            return f'[{it_const}] =\n    {{\n        .name = ITEM_NAME("{es_name}"),'
        return m.group(0)

    pattern = re.compile(r'\[(ITEM_\w+)\]\s*=\s*\{\s*\.name\s*=\s*ITEM_NAME\("[^"]*"\),', re.MULTILINE)
    new_content = pattern.sub(repl_name, content)
    with open(file_path, "w", encoding="utf-8") as f:
        f.write(new_content)
    print(f"[Items] Traducidos {count} nombres de objetos en {file_path}")

if __name__ == "__main__":
    translate_abilities_file()
    translate_moves_file()
    translate_items_file()
