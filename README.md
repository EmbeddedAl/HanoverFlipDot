# HanoverFlipDot
Platform independent C software to access different Hanover flip dot display types

## Demo-Video
Check the code in action on YouTube:

[![Hanover Display Flip Dot Demo Video](https://img.youtube.com/vi/L9QkUoiti7c/0.jpg)](https://www.youtube.com/watch?v=L9QkUoiti7c "Hanover Display Flip Dot Demo Video")


## Compile examples
###### Natively compiling the code on Windows operating systems (x86/x64)
Install gcc on Windows using 'mingw' or 'cygwin'. 

Compiling should work out of the box. 

Use an USB/RS485 dongle to attach your system to the display.


###### Cross-Compiling the code for Raspberry Pi Zero or Raspberry Pi 1 (using a Linux Host system)
A typical case is cross compiling the sources to run on a Raspberry Pi systems.

To cross compile the Linaro toolchain can be used. 

It is available on GitHub: https://github.com/raspberrypi/tools


**Step:** On Linux (e.g. Ubuntu) clone the toolchain’s repository from https://github.com/raspberrypi/tools

**Note:** Within the repository, the toolchains binary files are located at 'arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin'

**Step:** Add the toolchain to your path by e.g. editing your ~/.profile and add: 
      ```
      # add the Raspberry Pi Linaro toolchain path 
      PATH="$HOME/git/RaspberryPiTools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin:$PATH"
      ```
      
**Note:** Don't forget to log off and log on again...


## Tested Hardware

Various Hanover display types
