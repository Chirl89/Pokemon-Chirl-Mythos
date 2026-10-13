import re

with open('data/maps/NewBarkTown_Lab_hns/scripts.inc', 'r', encoding='utf-8') as f:
    content = f.read()

label = 'NewBarkTown_Lab_Text_ShouldntTouch'
pattern = re.compile(rf'({label}:(?::)?\s*\n)((?:\s*\.string\s*"[^"]*"\s*\n)+)')
m = pattern.search(content)
print("Match found:", bool(m))
if m:
    print("Full match:\n", repr(m.group(0)))
