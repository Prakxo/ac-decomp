import re
from argparse import ArgumentParser

parser = ArgumentParser(description="Fetch symbols from map file")
parser.add_argument('mapf', type=str, help="Map file path")
parser.add_argument('relf', type=str, help="Rel file path")
parser.add_argument('yml_p', type=str, help="YML output path")
args = parser.parse_args()

class entry:
    def __init__(self, address, size, virt, num, symbol, file, source):
        self.address = address
        self.size = size
        self.virt = virt
        self.num = num
        self.symbol = symbol
        self.file = file
        self.source = source
    def yaml(self):
        return f"0x{self.virt}: {self.symbol}"
    def shiftvirt(self, shift):
        cast = int(self.virt, base=16)
        self.virt = hex(cast+shift)[2:].upper()
    def sourcefile(self):
        if self.source != None:
            return self.source
        else:
            if self.file.endswith(".o"):
                return self.file.replace(".o", ".c")
            else:
                return self.file
allentries = []
for isrel, filename in enumerate((args.mapf, args.relf)):
    with open(filename, 'r') as f:
        data = f.readlines()
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
                source = d[5] if len(d) > 5 else None
                entries.append(entry(d[0], d[1], d[2], None, d[3], d[4], source))
            else:
                source = d[6] if len(d) > 6 else None
                entries.append(entry(d[0], d[1], d[2], d[3], d[4], d[5], source))
            if isrel:
                relshifts = {".bss": 0x8125A7C0, ".text": 0x803702A9, ".rodata": 0x80641260, ".data": 0x8064D500}
                entries[-1].file = "rel/" + entries[-1].file
                if entries[-1].source is not None:
                    entries[-1].source = "rel/" + entries[-1].source
                if sect in relshifts:
                    entries[-1].shiftvirt(relshifts[sect])
            else:
                entries[-1].file = "src/" + entries[-1].file
                if entries[-1].source is not None:
                    entries[-1].source = "src/" + entries[-1].source
		
            line += 1

        allentries.append(entries)
        #print(sect, len(entries))
        #if sect == "extab":
        #    for i in entries:
        #        print(i.yaml())
        #        print(i.address, i.size, i.virt, i.num, i.symbol, i.file)
        line += 1

filereg = {"global": {}, }
duplicates = []

for sect in allentries:
    if len(sect) == 0: continue
    for e in sect:
        if (e.num != "1" 
                and e.num is not None 
                and "$" not in e.symbol 
                and "@" not in e.symbol 
                and "..." not in e.symbol):
            newfile = e.sourcefile()
            if e.symbol not in filereg["global"] and e.symbol not in duplicates:
                filereg["global"][e.symbol] = [e]
            elif e.symbol in duplicates: # previously removed from global
                if newfile not in filereg:
                    filereg[newfile] = {}
                if e.symbol in filereg[newfile]:
                    print("same file collision:", newfile, e.symbol)
                    filereg[newfile][e.symbol].append(e)
                else:
                    filereg[newfile][e.symbol] = [e]
            else: # encountered a wild duplicate in global
                duplicates.append(e.symbol)
                oldfile = filereg["global"][e.symbol][0].sourcefile()
                if oldfile not in filereg:
                    filereg[oldfile] = {}
                if newfile not in filereg:
                    filereg[newfile] = {}
                filereg[oldfile][e.symbol] = filereg["global"][e.symbol]
                if oldfile == newfile:
                    print("same file collision:", newfile, e.symbol)
                    filereg[newfile][e.symbol].append(e)
                else:
                    filereg[newfile][e.symbol] = [e]
                filereg["global"].pop(e.symbol)


with open(args.yml_p, 'w') as d:
    for file, entries in filereg.items():
        print(f"{file}:", file=d)
        flat_list = [item for sublist in entries.values() for item in sublist]
        for e in sorted(flat_list, key=lambda x: x.virt):
            print("    " + e.yaml(), file=d)
