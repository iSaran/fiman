# FiMan

## About

FiMan is a financial manager written in C++, managing the inflows and outflows in a registered account.

FiMan is still under development and it is not recommended for use. When the first stable version is released, this README will be populated with more detailed instructions of use.

## Build

FiMan uses tools from the standard library of C++11 using `cmake` and tested under linux (Ubuntu 14.04). So, you will need the following dependencies in order to build the project:

  * Ubuntu 14.04
  * CMake

You can install CMake with:

```bash
sudo apt-get install cmake
```

In order to build the project clone it and create a build directory:

```bash
git clone https://github.com/isaran/fiman.git ~/fiman
cd ~/fiman
mkdir build
cd build
cmake ..
make
./fiman
```
