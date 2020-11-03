![CMake](https://github.com/ricky85ps/kmbd/workflows/CMake/badge.svg)

# kEmbedded library (kmbd)
This library shall support functionality specialized to embedded systems. Test cases are also checked in.
If you want to run these, you can build it using make and run `kmbd/Debug/kEmbeddedLib`.

The library is tested using [Catch v2.1.1](https://github.com/catchorg/Catch2 "Go to Catch2 github repository") testing library, which is only a single headerfile named `catch.hpp`
## Running the test cases
This is done with the usual CMake steps:
```bash
mkdir myBuildFolder
cd myBuildFolder
cmake ..
cmake --build .
ctest
```
