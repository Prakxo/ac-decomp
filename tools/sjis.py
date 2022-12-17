from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument("input")
parser.add_argument("output")
args = parser.parse_args()

with open(args.input, encoding="utf-8") as f:
    txt = f.read()

with open(args.output, 'w', encoding="shift-jis") as f:
    f.write(txt)
