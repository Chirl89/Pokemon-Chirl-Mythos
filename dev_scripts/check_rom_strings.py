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
        else:
            print(f"Char not found: {c}")
            return None
    return bytes(res)

with open('pokehns.gba', 'rb') as f:
    rom = f.read()

partida = encode("PARTIDA NUEVA")
newgame = encode("NEW GAME")

print(f"Encoded 'PARTIDA NUEVA': {partida.hex() if partida else 'None'}")
print(f"Encoded 'NEW GAME': {newgame.hex() if newgame else 'None'}")

if partida and partida in rom:
    print("Found 'PARTIDA NUEVA' in pokehns.gba!")
else:
    print("NOT found 'PARTIDA NUEVA' in pokehns.gba")

if newgame and newgame in rom:
    print("Found 'NEW GAME' in pokehns.gba!")
else:
    print("NOT found 'NEW GAME' in pokehns.gba")
