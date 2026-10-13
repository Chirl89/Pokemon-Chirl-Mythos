import re

with open('src/battle_message.c', 'r', encoding='latin1') as f:
    text = f.read()

static_strings = re.findall(r'(?:static\s+const\s+u8|const\s+u8)\s+([A-Za-z0-9_]+)\[\]\s*=\s*_\("([^"]+)"\);', text)
table_strings = re.findall(r'\[(STRINGID_[A-Za-z0-9_]+)\]\s*=\s*COMPOUND_STRING\("([^"]+)"\)', text)

print(f'battle_message static strings: {len(static_strings)}')
print(f'battle_message table strings: {len(table_strings)}')

for k, v in static_strings[:15]:
    print(f"STATIC {k}: {v}")

for k, v in table_strings[:15]:
    print(f"TABLE {k}: {v}")
