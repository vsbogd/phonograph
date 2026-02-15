## Overview

This repo contains various tools for working with toy educational phonograph:
- [disc generator page](https://vsbogd.github.io/toy-phonograph/disc.html) to
  generate and print the discs
- `smp2mp3.py` utility to decode/encode .smp files from the device in Python
- `smp2mp3.c` utility to decode/encode .smp files from the device in C

## Disc code

Code consists of 10 bits + 1 checksum bit. Checksum bit is set to 1 when number
of 1 in number is odd and 0 otherwise. The number of the set bits is always
even. The bits are printed counter-clockwise from the least significant one to
the last significant one. Each bit is represented by a sector which contains
both black and white parts. 0 is encoded by 6 degrees black sector which is
followed by 18 degrees white sector. 1 is encoded by 18 degrees black sector
which is followed by 6 degrees white sector. After the most significant bit
(counter-clockwise) there is a 24 degrees sector which is totally black. After
the black sector and before the least significant bit there is a big white
area.

## Available tracks

First Chinese track has code 1. Last official Chinese disc has code 97. The
total number of Chinese tracks is 288, thus there are 191 additional Chinese
track in the device.

First English track has code 587. Last English disc has code 682. There are
only 96 English tracks.

First DIY track has code 577. Despite there are only 8 DIY discs in a standard
box, there are 2 additional discs. The total number of DIY discs is 10.
