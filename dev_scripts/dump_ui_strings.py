import re
import json

with open('src/strings.c', 'r', encoding='latin1') as f:
    text = f.read()

# Pattern for const u8 gText_XYZ[] = _("...");
gtext_matches = re.findall(r'const\s+u8\s+([A-Za-z0-9_]+)(?:\[[^\]]*\])?\s*=\s*_\("([^"]+)"\);', text)
res = {}
for k, v in gtext_matches:
    res[k] = v

with open('dev_scripts/ui_strings.json', 'w', encoding='utf-8') as f:
    json.dump(res, f, indent=2, ensure_ascii=False)

print(f"Dumped {len(res)} UI strings to dev_scripts/ui_strings.json")
