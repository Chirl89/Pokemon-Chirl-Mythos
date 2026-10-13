import re
import json

with open('data/maps/NewBarkTown_Lab_hns/scripts.inc', 'r', encoding='latin1') as f:
    content = f.read()

matches = re.findall(r'(\w+):\s*\n((?:\s*\.string\s*"[^"]*"\s*\n)+)', content)
result = {}
for lbl, text in matches:
    raw_lines = re.findall(r'\.string\s*"([^"]*)"', text)
    result[lbl] = raw_lines

with open('dev_scripts/elm_lab_strings.json', 'w', encoding='utf-8') as f:
    json.dump(result, f, indent=2, ensure_ascii=False)

print(f"Dumped {len(result)} labels to dev_scripts/elm_lab_strings.json")
