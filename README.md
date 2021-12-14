# Color Out

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Building](#building)
- [Usage](#usage)
- [Development](#development)

## Introduction
Color Out is C++ library to colorize the standart output of your program. It
also provides feature to style the text, such as bold and underline.

## Features
![Result Preview](/assets/img/Screenshot_141221_135958_edited.png)
Color Out provides many foreground and background colors and the styles of the
text (bold, underline, etc.). You could see in the header file (`ColorOut.h`) at
the public method.

## Building
The library can be built using CMake version 3.22.1. Run the following commands
to build,
```
$ ./configure
$ ./makelib
```
The shared and static library should appear in the `lib/` directory.

## Usage
To use the library, you need to include the header file (`ColorOut.h`) and link
the library. Create an instance of the ColorOut class and use the methods to
apply style and color to your text.

In example you want to create blue text in a red background, you could write
this code,
```cpp
Zain::ColorOut clout;
clout.foreground().blue().background().red().print("This is a red text with red background.\n");
```

## Development
If you want to improve or make change to the library and test it, uncomment the
last row of `CMakeLists.txt` and test the library from `src/main.cpp` file. The
testing binary should appear as `testing/testing`.