# PyPI is the official Python package registry where you publish your library so users can install it using pip install gdsl.

GDSL/
├── bin/
│   └── gdsl.dll
│
└── bindings/
    └── python/
        │
        ├── pyproject.toml
        ├── README.md
        │
        └── gdsl/
            ├── __init__.py
            │
            ├── list.py
            ├── stack.py
            ├── queue.py
            ├── bst.py
            ├── avl.py
            │
            └── _native/
                └── gdsl.dll

# bin/gdsl.dll → compiled native library (actual C/C++ code that runs at runtime)
# pyproject.toml → build configuration for pip (defines package name, version, build system)
# README.md → documentation for users (install guide, usage, examples)
# __init__.py → marks gdsl as a Python package and controls default imports
# list.py / stack.py / queue.py / bst.py / avl.py → Python wrapper modules that expose C/C++ DLL functions using ctypes or CFFI
# _native/gdsl.dll → private bundled DLL loaded internally by Python wrappers at runtime


# ________________________________________Step-by-step:

1. Build your package (run inside your project root)
👉 Go to folder where pyproject.toml is:
>> cd GDSL/bindings/python
Then run:
>> python -m build
This creates:
dist/
  gdsl-1.0.0-py3-none-any.whl

# -----------------------------------------------------
2. Upload to PyPI (THIS is the important step)
Install uploader:
>> pip install twine
Upload:
>> twine upload dist/*

# -----------------------------------------------------
3. After upload
Now users anywhere in the world can run:
pip install gdsl

# -----------------------------------------------------
Important explanation:
PyPI is NOT something you open or edit manually.
It is a server (like GitHub but for Python packages).

# -----------------------------------------------------
One-line summary:
You run build and upload commands in your terminal, and PyPI is the online server where your package gets published so pip can install it.


________________________________________________________________________________

# GDSL
Generic Data Structure Library (C++ backend with Python bindings)

## Installation
pip install gdsl

## Usage
import gdsl

stack = gdsl.Stack()
stack.push(10)

## Features
- Stack, Queue, BST, AVL
- High performance C++ core
- Python bindings using ctypes