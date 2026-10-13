import glob
import re
import json

files = glob.glob('data/maps/*_hns/scripts.inc')
res = {}

for f in files:
    with open(f, 'r', encoding='latin1') as fp:
        txt = fp.read()
    strs = re.findall(r'(\w+)::\s*\n\s*\.string\s*"([^"]+)"', txt)
    if strs:
        res[f] = {lbl: s for lbl, s in strs}

with open('dev_scripts/map_hns_strings.json', 'w', encoding='utf-8') as f:
    json.dump(res, f, indent=2, ensure_ascii=False)

print(f"Dumped map strings for {len(res)} files to dev_scripts/map_hns_strings.json")
