import glob
import re

def inspect_all_strings():
    hns_files = glob.glob('data/maps/*_hns/scripts.inc')
    text_labels = 0
    all_text_blocks = []
    
    for f in hns_files:
        with open(f, 'r', encoding='latin1') as fp:
            content = fp.read()
        # Find any label ending with : or :: followed by .string
        matches = re.findall(r'([A-Za-z0-9_]+)::\s*(?:\s*@.*?\n)?((?:\s*\.string\s*"[^"]*"\s*\n)+)', content)
        for label, body in matches:
            text_labels += 1
            all_text_blocks.append((f, label, body))
            
    print(f"Total labeled text entries (with ::): {text_labels}")
    
    # Also find single colon labels
    matches_single = []
    for f in hns_files:
        with open(f, 'r', encoding='latin1') as fp:
            content = fp.read()
        matches = re.findall(r'(?<!:)([A-Za-z0-9_]+):\s*(?:\s*@.*?\n)?((?:\s*\.string\s*"[^"]*"\s*\n)+)', content)
        for label, body in matches:
            matches_single.append((f, label, body))
    print(f"Total labeled text entries (with :): {len(matches_single)}")

if __name__ == '__main__':
    inspect_all_strings()
