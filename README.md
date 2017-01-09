# MinorKMint (Jorg de Bont / Thomas van Lingen)
## Compiling
In order to compile our program, the following packages are needed:
  * build-essential
  * libsdl2-dev
  * libsdl2-ttf-dev
  * libsdl2-gfx-dev
  * libsdl2-image-dev
  
These can be installed using `apt`. It's recommended to do a full update beforhand.
To update your system and install all needed dependencies, run the following:
```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install build-essential libsdl2-dev libsdl2-ttf-dev libsdl2-gfx-dev libsdl2-image-dev
```

A `Makefile` is included with the program for easy compilation. To compile the program,
simply run `make` in the project directory.

The compiled binary is then stored in `build/KMint`. It can then be easily run by
typing `make run` in the project root.

