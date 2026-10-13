import re
import json

with open('src/battle_message.c', 'r', encoding='latin1') as f:
    text = f.read()

table_strings = re.findall(r'\[(STRINGID_[A-Za-z0-9_]+)\]\s*=\s*COMPOUND_STRING\("([^"]+)"\)', text)
res = {}
for k, v in table_strings:
    res[k] = v

with open('dev_scripts/battle_strings.json', 'w', encoding='utf-8') as f:
    json.dump(res, f, indent=2, ensure_ascii=False)

print(f"Dumped {len(res)} battle strings to dev_scripts/battle_strings.json")
