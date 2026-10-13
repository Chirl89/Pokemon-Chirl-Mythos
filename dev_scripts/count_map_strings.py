import glob
import re

files = glob.glob('data/maps/*_hns/scripts.inc')
total_string_lines = 0
files_with_strings = 0

for f in files:
    with open(f, 'r', encoding='latin1') as fp:
        txt = fp.read()
    strs = re.findall(r'^\s*\.string\s+"([^"]*)"', txt, re.MULTILINE)
    if strs:
        files_with_strings += 1
        total_string_lines += len(strs)

print(f"Files with .string: {files_with_strings} / {len(files)}")
print(f"Total .string lines in *_hns: {total_string_lines}")
