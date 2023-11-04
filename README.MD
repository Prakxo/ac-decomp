# Animal Crossing Decompilation [![Discord Channel][discord-badge]][discord]
[discord]: https://discord.gg/hKx3FJJgrV
[discord-badge]: https://img.shields.io/discord/727908905392275526?color=%237289DA&logo=discord&logoColor=%23FFFFFF

Decompilation in progress of Animal Crossing (GAFE01)

A decompilation of the original N64 version of the game is being worked on [here](https://github.com/zeldaret/af).
## Cloning

Use `--recursive` when cloning to have ppcdis in the repository. 

## Build

**It's preferable to use [wibo](https://github.com/decompals/wibo), a lightweight
Wine replacement that's made to work with the compilers, but Wine is still usable.**

### Building (Docker)
1. Dump a copy of the game and extract **main.dol** and **foresta.rel.szs**.
2. Decompress **foresta.rel.szs** with yaz0 found in *tools/*.
3. Place **main.dol** and **foresta.rel** in *dump/*.
4. Place CodeWarrior 1.3.2 in *tools/1.3.2/* and 1.2.5n in *tools/1.2.5n/*.
5. Download [CodeWarrior 1.3.2r](https://mega.nz/file/WuBFTCLT#TmB5R4-1mEFkk4G1Vjn9_cHXRD9wOIH9CtOLaVSWEas) and extract it to *tools/1.3.2r/*.
6. Install Docker.
7. Run `docker build -t ac-decomp .` to build the Docker image.
8. Run `docker run -it --rm --name ac-decomp --mount type=bind,source="$(pwd)",destination=/ac-decomp ac-decomp python3 configure.py` to run configure.py.
9. Run `docker run -it --rm --name ac-decomp --mount type=bind,source="$(pwd)",destination=/ac-decomp ac-decomp ninja` to run Ninja.

### Building (manual)

1. Dump a copy of the game and extract **main.dol** and **foresta.rel.szs**.
2. Decompress **foresta.rel.szs** with yaz0 found in *tools/*.
3. Place **main.dol** and **foresta.rel** in *dump/*.
4. Place CodeWarrior 1.3.2 in *tools/1.3.2/* and 1.2.5n in *tools/1.2.5n/*.
5. Download [CodeWarrior 1.3.2r](https://mega.nz/file/WuBFTCLT#TmB5R4-1mEFkk4G1Vjn9_cHXRD9wOIH9CtOLaVSWEas) and extract it to *tools/1.3.2r/*.
6. Set the `N64_SDK` environment variables with the path of your libultra or equivalent headers.
	- Headers should be at `$N64_SDK/ultra/usr/include`.
    - You may need to modify `Gpopmtx`'s `param` member to be `unsigned int`.
7. Install DevkitPPC, Ninja and Python 3.
	- Set the environment variable DEVKITPPC to `/opt/devkitpro/devkitPPC`.
8. Install Python modules from requirements.txt (`pip install -r requirements.txt`).
9. Run `python3 configure.py`.
10. Run `ninja`.

## Credits

- jamchamb, Cuyler36, NWPlayer123 and fraser125 for past documentation of Animal Crossing.
- SeekyCt for [ppcdis](https://github.com/SeekyCt/ppcdis/) and helping setting up the project.
- msg for helping with *tools/map.py*.
