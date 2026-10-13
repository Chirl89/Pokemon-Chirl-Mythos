#!/usr/bin/env python3
import os
import csv
import urllib.request

CACHE_DIR = "dev_scripts/data_cache"
os.makedirs(CACHE_DIR, exist_ok=True)

FILES = [
    "moves.csv",
    "move_names.csv",
    "move_flavor_text.csv",
    "abilities.csv",
    "ability_names.csv",
    "ability_flavor_text.csv",
    "items.csv",
    "item_names.csv",
    "item_flavor_text.csv",
]

BASE_URL = "https://raw.githubusercontent.com/veekun/pokedex/master/pokedex/data/csv/"

def download_cache():
    for f in FILES:
        target = os.path.join(CACHE_DIR, f)
        if not os.path.exists(target):
            url = BASE_URL + f
            print(f"Downloading {f}...")
            urllib.request.urlretrieve(url, target)
        else:
            print(f"Cached: {f}")

if __name__ == "__main__":
    download_cache()
    print("Done caching datasets.")
