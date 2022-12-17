import re

from argparse import ArgumentParser

parser = ArgumentParser(description="Fetch symbols from map file")
parser.add_argument('mapf', type=str, help="Map file path")
parser.add_argument('yml_p', type=str, help="YML output path")
args = parser.parse_args()

with open(args.mapf, 'r') as f:
    data = f.readlines()
class entry:
    def __init__(self, address, size, virt, num, symbol, file):
        self.address = address
        self.size = size
        self.virt = virt
        self.num = num
        self.symbol = symbol
        self.file = file
    def yaml(self):
        return f"0x{self.virt}: ENTRY"

allentries = []

line = 0
while True:
    while line < len(data) and not data[line].endswith("section layout\n"):
        line += 1
    if line >= len(data): break #end when the sections are exhausted

    sect = data[line].replace(" section layout\n", '')
    line += 4 #skip section header

    entries = []
    while data[line] != "\n":
        entryof = data[line].find("(entry of") != -1
        if entryof:
            d = re.sub(r"\(entry of .*?\)", "", data[line])
        else:
            d = data[line]
        d = d.strip().replace("\t", "").split(" ")
        d = [x for x in d if x != ""]
        #if sect == "extab":
        #    print(data[line])
        #    print(d)
        if entryof:
            entries.append(entry(d[0], d[1], d[2], None, d[3], d[4]))
        else:
            entries.append(entry(d[0], d[1], d[2], d[3], d[4], d[5]))
        line += 1

    allentries.append(entries)
    #print(sect, len(entries))
    #if sect == "extab":
    #    for i in entries:
    #        print(i.yaml())
    #        print(i.address, i.size, i.virt, i.num, i.symbol, i.file)
    line += 1
with open(args.yml_p, 'w') as d:
    print("global:", file=d)
    for sect in allentries:
        if len(sect) == 0: continue
        # print("    #" + sect[0].yaml())
        for e in sect:
            if e.num is None and "..." not in e.symbol:
                print("    " + e.yaml(), file=d)
