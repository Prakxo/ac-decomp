# Animal Crossing Decompilation [![Discord Channel][discord-badge]][discord]
[discord]: https://discord.gg/hKx3FJJgrV
[discord-badge]: https://img.shields.io/discord/727908905392275526?color=%237289DA&logo=discord&logoColor=%23FFFFFF

Decompilation in progress of Animal Crossing (GAFE01)

A decompilation of the original N64 version of the game is being worked on [here](https://github.com/zeldaret/af).
## Cloning

Use `--recursive` when cloning to have ppcdis in the repository. 

## Build

### Building with Docker (recommended)

> ℹ️ When using Windows, we recommend using a shell such as MSYS2, Bash, or PowerShell instead of the Command Prompt.

1. Dump a copy of the game and extract **main.dol** and **foresta.rel.szs**.
2. Decompress **foresta.rel.szs** with yaz0 found in *tools/*: `yaz0 -d foresta.rel.szs foresta.rel`.
3. Place **main.dol** and **foresta.rel** in *dump/*.
4. Download the [CodeWarrior 1.3.2 and 1.2.5n compilers](https://files.decomp.dev/compilers_20230715.zip) and extract them to *tools/1.3.2/* and *tools/1.2.5n/*, respectively.
5. Download the [CodeWarrior 1.3.2r compiler](https://mega.nz/file/WuBFTCLT#TmB5R4-1mEFkk4G1Vjn9_cHXRD9wOIH9CtOLaVSWEas) and extract it to *tools/1.3.2r/*.
6. Install Docker.
7. Build the Docker image (`docker build -t ac-decomp .`).
8. Run configure.py (`docker run -it --rm -v ${PWD}:/ac-decomp ac-decomp python3 configure.py`).
9. Run ninja (`docker run -it --rm -v ${PWD}:/ac-decomp ac-decomp ninja`).

### Building manually (not recommended)

> ℹ️ If you're using Windows, please use Docker, or if you prefer to build manually, use Windows Subsystem for Linux.

1. Dump a copy of the game and extract **main.dol** and **foresta.rel.szs**.
2. Decompress **foresta.rel.szs** with yaz0 found in *tools/*: `yaz0 -d foresta.rel.szs foresta.rel`.
3. Place **main.dol** and **foresta.rel** in *dump/*.
4. Download the [CodeWarrior 1.3.2 and 1.2.5n compilers](https://files.decomp.dev/compilers_20230715.zip) and extract them to *tools/1.3.2/* and *tools/1.2.5n/*, respectively.
5. Download the [CodeWarrior 1.3.2r compiler](https://mega.nz/file/WuBFTCLT#TmB5R4-1mEFkk4G1Vjn9_cHXRD9wOIH9CtOLaVSWEas) and extract it to *tools/1.3.2r/*.
6. Set the `N64_SDK` environment variable with the path of your libultra or equivalent headers. If you need headers, you can use the ones from [ultralib](https://github.com/decompals/ultralib).
    - Headers should be located at `$N64_SDK/ultra/usr/include`.
    - You may need to modify `Gpopmtx`'s `param` member to be `unsigned int` in **gbi.h**.
7. Install devkitPPC.
    - To get devkitPPC, you'll need [devkitPro Pacman](https://devkitpro.org/wiki/devkitPro_pacman#Installing_devkitPro_Pacman).
        - Run `dkp-pacman -S devkitPPC` once dkp-pacman is installed to install devkitPPC.
        - Set the environment variable `DEVKITPPC` to */opt/devkitpro/devkitPPC*.
8. Install [wibo](https://github.com/decompals/wibo)
    - Wibo is a lightweight Wine replacement that's tailor-made for use with decomp projects. You can use regular Wine if you wish, but for the purposes of this guide, we'll be using wibo.
    - Download [the latest GitHub release](https://github.com/decompals/wibo/releases/latest) and run `install ./wibo /usr/bin` to install it to your system.
8. Install Python and pip.
9. Install ninja (`pip install ninja`).
10. Install Python modules from requirements.txt (`pip install -r requirements.txt`).
11. Run `python3 configure.py`.
12. Run `ninja`.

## Credits

- jamchamb, Cuyler36, NWPlayer123 and fraser125 for past documentation of Animal Crossing.
- SeekyCt for [ppcdis](https://github.com/SeekyCt/ppcdis/) and helping setting up the project.
- msg for helping with *tools/map.py*.
