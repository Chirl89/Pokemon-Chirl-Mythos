import sys
import re

files = [
    "src/data/abilities.h",
    "src/data/moves_info.h",
    "src/data/items.h",
    "src/data/types_info.h",
    "src/pokemon.c",
    "src/main_menu.c",
    "src/strings.c",
    "src/option_menu.c",
    "src/pokemon_storage_system.c",
    "src/battle_message.c",
    "include/constants/global.h"
]

all_ok = True
for f in files:
    try:
        with open(f, "r", encoding="utf-8") as fp:
            txt = fp.read()
        bad_compound = re.findall(r'COMPOUND_STRING\("([^"]*\n[^"]*)"\)', txt)
        if bad_compound:
            print(f"[ERROR] {f} has unescaped newline in COMPOUND_STRING: {bad_compound[0][:50]}")
            all_ok = False
        else:
            print(f"[OK] {f} ({len(txt)} chars)")
    except Exception as e:
        print(f"[FAIL] {f}: {e}")
        all_ok = False

if all_ok:
    print("\nAll files verified perfectly!")
else:
    sys.exit(1)
