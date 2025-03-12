This is a dummy project, an empty skeleton to start from when making something for the Badger2040 by Pimoroni

The badge:
[https://shop.pimoroni.com/products/badger-2040]

The code I based this on:
[https://github.com/pimoroni/pimoroni-pico/tree/main/examples/badger2040]

Looking through the code, I needed to cobble together 4 different parts of the Pimoroni repo:
1. drivers/uc8151_legacy
2. libraries/bitmap_fonts
3. libraries/hershey_fonts
4. common

After some fooling around with a CMakeList.txt, I got everything to compile under VSCode as a pico-sdk based project.
