# GDSL - Generic Data Structure Library

GDSL is a header-only C++ data structure library (before C API version), designed for direct use in MinGW/GCC projects.

------------------------------------------------------------

# INSTALLATION (LOCAL - MINGW)

Place the folder inside:

MinGW/include/GDSL/

------------------------------------------------------------

# PROJECT STRUCTURE

GDSL/
│
├── include/
│   ├── Linear/
│   │   ├── List/
│   │   │   └── SinglyList.hpp
│   │   │
│   │   ├── Stack.hpp
│   │   │
│   │   └── Queue/
│   │       └── SimpleQueue.hpp
│   │
│   └── NonLinear/
│       └── Tree/
│           ├── BalancedTree.hpp
│           ├── BinarySearchTree.hpp
│           ├── AdelsonVelskyLandisTree.hpp
│           └── Mode.hpp
│
├── src/
│   ├── Linear/
│   │   ├── List/
│   │   │   └── SinglyList.tpp
│   │   │
│   │   ├── Stack.tpp
│   │   │
│   │   └── Queue/
│   │       └── SimpleQueue.tpp
│   │
│   └── NonLinear/
│       └── Tree/
│           ├── BalancedTree.tpp
│           ├── BinarySearchTree.tpp
│           └── AdelsonVelskyLandisTree.tpp

------------------------------------------------------------

# HOW IT WORKS

Each `.hpp` file includes its implementation `.tpp` file directly.

Example:

```cpp
#include "src/Linear/List/SinglyList.tpp"