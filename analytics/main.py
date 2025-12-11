import os
import json

files = []

for fileName in os.listdir("output"):
    path = "output/" + fileName
    with open(path) as f:
        d = json.load(f)
        files.append(d)

print(files)