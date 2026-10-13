import glob
import re

def inspect_data_text():
    text_files = glob.glob('data/text/*.inc')
    res = {}
    for f in text_files:
        with open(f, 'r', encoding='latin1') as fp:
            content = fp.read()
        matches = re.findall(r'([A-Za-z0-9_]+)::\s*(?:\s*@.*?\n)?((?:\s*\.string\s*"[^"]*"\s*\n)+)', content)
        if matches:
            res[f] = len(matches)
    for f, count in sorted(res.items(), key=lambda x: x[1], reverse=True):
        print(f"{f}: {count} blocks")

if __name__ == '__main__':
    inspect_data_text()
