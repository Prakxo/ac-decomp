"""
Creates the expected folder for diff.py
"""

from shutil import copytree, rmtree

import common as c

# Remove it if already existing
try:
    rmtree(c.EXPECTED)
except FileNotFoundError:
    pass

# Copy in builddir and outdir
copytree(c.BUILDDIR, f"{c.EXPECTED}/build")
copytree(c.OUTDIR, f"{c.EXPECTED}/out")