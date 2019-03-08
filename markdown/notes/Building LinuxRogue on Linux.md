---
title: Building LinuxRogue on Linux
created: '2019-03-08T04:17:11.276Z'
modified: '2019-03-08T04:20:53.061Z'
---

# Building LinuxRogue on Linux

- Get the source for LinuxRogue v0.3.7 from [coredumpcentral](http://www.coredumpcentral.org/download.html)
- Unzip, untar it.
- Install the ncurses source: `sudo apt-get install libncurses-dev`
- Go to the directory with the actual .c files in it: `linuxrogue-0.3.7-roguecentral/linuxrogue-0.3.7`
- `make rogue54`

Then, you'll get a `rogue54` executable.
