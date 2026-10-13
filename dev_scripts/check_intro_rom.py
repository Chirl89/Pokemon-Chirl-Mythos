import re

charmap = {}
with open('charmap.txt', 'r', encoding='latin1') as f:
    for line in f:
        line = line.strip()
        if not line or line.startswith('@'):
            continue
        m = re.match(r"^'([^']+)'\s*=\s*([0-9A-Fa-f]{2})", line)
        if m:
            charmap[m.group(1)] = int(m.group(2), 16)

def encode(s):
    res = bytearray()
    for c in s:
        if c in charmap:
            res.append(charmap[c])
        elif c == ' ':
            res.append(0x00)
    return bytes(res)

with open('pokehns.gba', 'rb') as f:
    rom = f.read()

# Let's check English Oak welcome vs Spanish Oak welcome
en_welcome = encode("Welcome to the world of POK")
es_welcome = encode("bienvenida al mundo")

print("English Oak welcome in ROM:", en_welcome in rom if en_welcome else False)
print("Spanish Oak welcome in ROM:", es_welcome in rom if es_welcome else False)

en_elm = encode("PROF.ELM'S LAB")
es_elm = encode("LABORATORIO")
print("English Elm Lab in ROM:", en_elm in rom if en_elm else False)

# Check naming screen strings
en_boy = encode("BOY")
es_chico = encode("CHICO")
print("English BOY in ROM:", en_boy in rom if en_boy else False)
print("Spanish CHICO in ROM:", es_chico in rom if es_chico else False)
