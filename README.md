# MultiIntro Updated
This project builds on the [MultiIntro plugin for Freelancer (2003) by M0tah](https://forge.the-starport.net/projects/multiintro) to provide several new features and fixes.
The [changelog](https://github.com/BC46/MultiIntro-Updated/blob/main/CHANGELOG.md) lists all the changes that have been made on top of the original plugin.

## Description
Allows more than three intro screens to be displayed. It will also pick one at random when returning to the intro screen instead of sticking to the one chosen at startup.

## Installation instructions
Download the latest `MultiIntro.zip` from [Releases](https://github.com/BC46/MultiIntro-Updated/releases). Extract both the `dll` and `ini` file and move them to the `EXE` folder of your Freelancer installation.
Next, open the `dacom.ini` file and append `MultiIntro.dll` to the `[Libraries]` section.

## Build instructions
Build the project using the `NMAKE` tool from Microsoft Visual C++ 6.0 (VC6 or Visual Studio 98) with the included makefile.
This will output the `thruster_toggle.dll` file in the `bin` folder.
Building the project using other compilers may require the code to be modified.

## Credits
- [BC46](https://github.com/BC46)
  - Additional features and fixes
- M0tah
  - [Original MultiIntro plugin](https://forge.the-starport.net/projects/multiintro)
