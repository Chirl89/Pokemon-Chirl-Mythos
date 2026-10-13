import glob
import os
import re

def audit_files():
    hns_files = glob.glob('data/maps/*_hns/scripts.inc')
    text_files = glob.glob('data/text/*.inc')
    
    total_hns_strings = 0
    hns_files_with_strings = 0
    for f in hns_files:
        with open(f, 'r', encoding='latin1') as fp:
            content = fp.read()
        lines = [line.strip() for line in content.splitlines() if line.strip().startswith('.string ')]
        if lines:
            hns_files_with_strings += 1
            total_hns_strings += len(lines)
            
    total_text_strings = 0
    text_files_with_strings = 0
    for f in text_files:
        with open(f, 'r', encoding='latin1') as fp:
            content = fp.read()
        lines = [line.strip() for line in content.splitlines() if line.strip().startswith('.string ')]
        if lines:
            text_files_with_strings += 1
            total_text_strings += len(lines)

    print(f"HNS map files with text: {hns_files_with_strings} / {len(hns_files)}")
    print(f"Total .string entries in HNS maps: {total_hns_strings}")
    print(f"data/text files with text: {text_files_with_strings} / {len(text_files)}")
    print(f"Total .string entries in data/text: {total_text_strings}")

if __name__ == '__main__':
    audit_files()
