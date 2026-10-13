with open('data/maps/NewBarkTown_Lab_hns/scripts.inc', 'rb') as f:
    raw = f.read()

try:
    s_utf8 = raw.decode('utf-8')
    print("Valid UTF-8: YES")
except Exception as e:
    print("Valid UTF-8: NO", e)

try:
    s_latin = raw.decode('latin1')
    print("Valid Latin1: YES")
except Exception as e:
    print("Valid Latin1: NO", e)
