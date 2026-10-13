import re

def inspect(path):
    with open(path, 'r', encoding='latin1') as f:
        text = f.read()
    matches = re.findall(r'(?:_|COMPOUND_STRING)\("([^"]+)"\)', text)
    print(f"=== {path} (total: {len(matches)}) ===")
    for m in matches[:25]:
        print(f"  {m}")

if __name__ == '__main__':
    inspect('src/pokemon_storage_system.c')
    inspect('src/start_menu.c')
    inspect('src/item_menu.c')
