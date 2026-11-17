# GDSL – Generic Data Structure Library

GDSL (Generic Data Structure Library) is a C++ data structure library designed to provide reusable, generic implementations of common linear and non-linear data structures.

The library is organized into modular components, separating public header files (`.hpp`) from implementation files (`.tpp`).

It also includes a compiled static library, a planned C API interface, and language-specific bindings for Dart, Java, and Python.

---

# INSTALLATION (MSYS2 – UCRT64)

Place the `GDSL` folder inside:

```text
C:\msys64\ucrt64\include\GDSL\
```

The compiled static library is located at:

```text
C:\msys64\ucrt64\include\GDSL\lib\libgdsl.a
```

---

# PROJECT STRUCTURE

```text
GDSL/
│
│── bin/
│
│── bindings/
│   │── dart/
│   │   └── README.md
│   │
│   │── java/
│   │   └── README.md
│   │
│   └── python/
│       │── pyproject.toml
│       └── README.md
│
│── c_api/
│   │── INTERFACE.md
│   │
│   │── include/
│   └── src/
│
│── include/
│   │
│   │── Linear/
│   │   │── Array.hpp
│   │   │── Stack.hpp
│   │   │
│   │   │── List/
│   │   │   └── SinglyList.hpp
│   │   │
│   │   └── Queue/
│   │       └── SimpleQueue.hpp
│   │
│   └── NonLinear/
│       └── Tree/
│           │── AdelsonVelskyLandisTree.hpp
│           │── BalancedTree.hpp
│           │── BinarySearchTree.hpp
│           └── Types.hpp
│
│── lib/
│   └── libgdsl.a
│
│── src/
│   │── instantiations.cpp
│   │
│   │── Linear/
│   │   │── Array.tpp
│   │   │── Stack.tpp
│   │   │
│   │   │── List/
│   │   │   └── SinglyList.tpp
│   │   │
│   │   └── Queue/
│   │       └── SimpleQueue.tpp
│   │
│   └── NonLinear/
│       └── Tree/
│           │── AdelsonVelskyLandisTree.tpp
│           │── BalancedTree.tpp
│           └── BinarySearchTree.tpp
│
│── g++
│── LIBRARY.md
│── test.c
│── test.exe
└── test.py
```

---

# DATA STRUCTURES

## 1. Linear Data Structures

Linear data structures organize elements sequentially.

| Data Structure | Header File | Implementation File |
|---|---|---|
| Array | `Array.hpp` | `Array.tpp` |
| Stack | `Stack.hpp` | `Stack.tpp` |
| Singly Linked List | `SinglyList.hpp` | `SinglyList.tpp` |
| Simple Queue | `SimpleQueue.hpp` | `SimpleQueue.tpp` |

## 2. Non-Linear Data Structures

Non-linear data structures organize elements hierarchically or through interconnected nodes.

| Data Structure | Header File | Implementation File |
|---|---|---|
| Binary Search Tree | `BinarySearchTree.hpp` | `BinarySearchTree.tpp` |
| Balanced Tree | `BalancedTree.hpp` | `BalancedTree.tpp` |
| AVL Tree | `AdelsonVelskyLandisTree.hpp` | `AdelsonVelskyLandisTree.tpp` |

`Types.hpp` contains shared tree-related type definitions.

---

# PROJECT ARCHITECTURE

GDSL separates its public interfaces and implementations.

### 1. include/

Contains public C++ header files (`.hpp`).

These files provide the declarations and interfaces required to use the library.

### 2. src/

Contains implementation files (`.tpp`) corresponding to the public headers.

It also contains:

- `instantiations.cpp` – Translation unit for template instantiations.

### 3. lib/

Contains the compiled static library.

```text
lib/
└── libgdsl.a
```

The static library can be linked into C++ applications using GCC/G++.

### 4. c_api/

Reserved for the C interface of GDSL.

```text
c_api/
│── INTERFACE.md
│
│── include/
└── src/
```

`INTERFACE.md` documents the intended C API interface.

### 5. bindings/

Reserved for future language-specific bindings and integrations.

| Language | Directory |
|---|---|
| Dart | `bindings/dart/` |
| Java | `bindings/java/` |
| Python | `bindings/python/` |

These directories are currently placeholders for future development.
---

# HOW IT WORKS

GDSL uses separate header (`.hpp`) and implementation (`.tpp`) files.

The `.hpp` files provide the public interface, while the `.tpp` files contain the corresponding template implementations.

For example:

```text
include/Linear/List/SinglyList.hpp
                |
                | Public Interface
                |
                ▼
src/Linear/List/SinglyList.tpp
                |
                | Implementation
                |
                ▼
          C++ Compilation
                |
                ▼
           libgdsl.a
```

The `instantiations.cpp` file serves as the translation unit for template instantiations.

---

# USING GDSL IN A C++ PROJECT

### Example: Including a Data Structure

```cpp
#include <GDSL/Linear/Stack.hpp>

int main()
{
    // Create and use GDSL data structures.
    return 0;
}
```

### Compilation (G++ – UCRT64)

Example command:

```bash
g++ main.cpp -o main.exe -I"C:/msys64/ucrt64/include" -L"C:/msys64/ucrt64/include/GDSL/lib" -lgdsl
```

Explanation:

| Argument | Purpose |
|---|---|
| `-I` | Specifies the directory containing GDSL headers. |
| `-L` | Specifies the directory containing the static library. |
| `-lgdsl` | Links against `libgdsl.a`. |

**Note:** Template types must have corresponding available definitions and instantiations. The exact supported types depend on the library's implementation and `instantiations.cpp`.

---

# REQUIREMENTS

- Windows
- MSYS2 UCRT64
- GCC / G++
- C++ compiler supporting the language features used by the library

---

# ADDITIONAL DOCUMENTATION

| File | Description |
|---|---|
| `LIBRARY.md` | Main library documentation |
| `c_api/INTERFACE.md` | C API interface documentation |

---

# LICENSE

Specify the applicable license here.

---

**GDSL – Generic Data Structure Library**

A modular, reusable, and extensible data structure library.
