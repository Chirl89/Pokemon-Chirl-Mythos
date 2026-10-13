import glob
import re

files = glob.glob('data/maps/*_hns/scripts.inc')
print(f"Total *_hns map script files: {len(files)}")

total_strings = 0
examples = []
for f in files:
    with open(f, 'r', encoding='latin1') as fp:
        txt = fp.read()
    strs = re.findall(r'(\w+)::\s*\n\s*\.string\s*"([^"]+)"', txt)
    total_strings += len(strs)
    if strs and len(examples) < 15:
        examples.append((f, strs[0]))

print(f"Total .string entries across all hns maps: {total_strings}")
for fn, (lbl, st) in examples:
    print(f"  [{fn}] {lbl}: {st[:40]}...")
