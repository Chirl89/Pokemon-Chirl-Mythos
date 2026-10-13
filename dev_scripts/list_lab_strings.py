import re

with open('data/maps/NewBarkTown_Lab_hns/scripts.inc', 'r', encoding='latin1') as f:
    content = f.read()

matches = re.findall(r'(\w+):\s*\n((?:\s*\.string\s*"[^"]*"\s*\n)+)', content)
print(f"Total text labels in Elm Lab: {len(matches)}")
for lbl, text in matches:
    cleaned = ''.join(re.findall(r'\.string\s*"([^"]*)"', text)).replace('\n', ' ').replace('\p', ' ').replace('\l', ' ')
    print(f"{lbl}: {cleaned[:80]}...")
