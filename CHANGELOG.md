# Changelog

## [v0.2](https://github.com/BC46/MultiIntro-Updated/releases/tag/v0.2)

### Features
- Added a config file
- Added an option to set a custom intro amount
- Added an option to only choose a random intro when launching the game (just like in vanilla Freelancer)

### Code-related changes
- Added a VC6 makefile
- Improved the project's folder structure
- Made `hModFL` a global constant since it's a fixed address that's used multiple times
- Moved `Main.cpp` forward function declarations to the header file
- Removed `srand` since it gets already called by Freelancer
- Add WIN32_LEAN_AND_MEAN definitions to reduce compile times
- Re-ordered includes in `Main.h`
- Build `Common.lib` using export definitions
- Added Freelancer's `INI_Reader` class definition
- Renamed the `WritePreHooks` function to `Setup`
- Replaced the custom `uint` typedef with `UINT` from `windows.h`
- Created a config reader class
- Removed `using namespace std`
- Converted tabs to spaces in the code files
- Extracted `dwOld`


## [v0.1](https://forge.the-starport.net/projects/multiintro/files)

### Purpose: To allow more than three intro screens.
