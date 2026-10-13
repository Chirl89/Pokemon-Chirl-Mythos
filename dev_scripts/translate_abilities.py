#!/usr/bin/env python3
import os
import re
import csv

def load_data():
    abilities_csv = "dev_scripts/data_cache/abilities.csv"
    names_csv = "dev_scripts/data_cache/ability_names.csv"
    flavor_csv = "dev_scripts/data_cache/ability_flavor_text.csv"
    
    id_to_ident = {}
    with open(abilities_csv, encoding='utf-8') as f:
        for r in csv.DictReader(f):
            c_name = "ABILITY_" + r['identifier'].upper().replace('-', '_')
            id_to_ident[r['id']] = c_name
            
    ident_to_name = {}
    with open(names_csv, encoding='utf-8') as f:
        for r in csv.DictReader(f):
            if r['local_language_id'] == '7':
                c_name = id_to_ident.get(r['ability_id'])
                if c_name:
                    ident_to_name[c_name] = r['name'].upper()
                    
    ident_to_desc = {}
    # Gen 4/5/6 version groups in Veekun: 15 (BW), 16 (B2W2), 17 (XY), 18 (ORAS)
    with open(flavor_csv, encoding='utf-8') as f:
        for r in csv.DictReader(f):
            if r['language_id'] == '7':
                c_name = id_to_ident.get(r['ability_id'])
                if c_name and (c_name not in ident_to_desc or int(r['version_group_id']) in [15, 16, 17, 18]):
                    text = r['flavor_text'].replace('\n', ' ')
                    ident_to_desc[c_name] = text
                    
    return ident_to_name, ident_to_desc

def wrap_text(text, max_len=30):
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
    return "\\n".join(lines)

def translate_abilities():
    ident_to_name, ident_to_desc = load_data()
    file_path = "src/data/abilities.h"
    with open(file_path, "r", encoding="utf-8") as f:
        content = f.read()
        
    def repl_block(m):
        ability_const = m.group(1)
        block = m.group(2)
        if ability_const in ident_to_name:
            es_name = ident_to_name[ability_const]
            # Replace .name = _("...")
            block = re.sub(r'(\.name\s*=\s*_\(")[^"]*("\))', rf'\g<1>{es_name}\g<2>', block)
            if ability_const in ident_to_desc:
                raw_desc = ident_to_desc[ability_const]
                wrapped = wrap_text(raw_desc, 32)
                block = re.sub(r'(\.description\s*=\s*COMPOUND_STRING\(")[^"]*("\))', rf'\g<1>{wrapped}\g<2>', block)
        return f"[{ability_const}] =\n    {{{block}}}"

    pattern = re.compile(r'\[(ABILITY_\w+)\]\s*=\s*\{([^}]+)\}', re.MULTILINE)
    new_content = pattern.sub(repl_block, content)
    
    with open(file_path, "w", encoding="utf-8") as f:
        f.write(new_content)
        
    print(f"Updated {file_path} successfully.")

if __name__ == "__main__":
    translate_abilities()
