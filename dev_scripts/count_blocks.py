import glob
import re

def count_blocks():
    hns_files = glob.glob('data/maps/*_hns/scripts.inc')
    total_blocks = 0
    for f in hns_files:
        with open(f, 'r', encoding='latin1') as fp:
            content = fp.read()
        blocks = re.findall(r'(\w+)::\s*\n((?:\s*\.string\s*"[^"]*"\s*\n)+)', content)
        total_blocks += len(blocks)
    print(f"Total multi-line text blocks in HNS maps: {total_blocks}")

if __name__ == '__main__':
    count_blocks()
