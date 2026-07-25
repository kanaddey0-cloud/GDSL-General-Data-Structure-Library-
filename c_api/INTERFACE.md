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
│
├── bin/
│   └── gdsl.dll
│
├── lib/
│   └── libgdsl.a
│
└── c_api/
    │
    ├── include/
    │   ├── gdsl_config.h
    │   ├── gdsl_mode.h
    │   ├── gdsl_list.h
    │   ├── gdsl_stack.h
    │   ├── gdsl_queue.h
    │   ├── gdsl_btree.h
    │   ├── gdsl_bst.h
    │   └── gdsl_avl.h
    │
    └── src/
        ├── gdsl_list.cpp
        ├── gdsl_stack.cpp
        ├── gdsl_queue.cpp
        ├── gdsl_btree.cpp
        ├── gdsl_bst.cpp
        └── gdsl_avl.cpp

__________________________________________________________

g++ -DGDSL_BUILD_DLL -shared \
c_api/src/*.cpp \
-o gdsl.dll \
-I . \
-I c_api/include \
-I include

➡️ Compiles all C API source files and creates the DLL (gdsl.dll) for dynamic linking.
➡️ Contains the actual executable code that runs at runtime.

GDSL
└── bin/
        └── gdsl.dll
__________________________________________________________

g++ -shared -o gdsl.dll c_api/src/*.cpp \
-Wl,--out-implib,libgdsl.a \
-I . \
-I c_api/include \
-I include

➡️ Creates both the DLL (gdsl.dll) and an import library (libgdsl.a) so users can link with -lgdsl at compile time.
➡️ Contains import information (stubs/symbols) used by the linker during compilation.
➡️ libgdsl.a is needed so C/C++ programs can link to gdsl.dll at compile time using  [ g++ app.cpp -lgdsl ]  without manually using LoadLibrary() and GetProcAddress().

GDSL
└── lib/
        └── libgdsl.a
__________________________________________________________

include/
└── Linear/
    └── List/
        └── SinglyList.hpp

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>
#include <stdexcept>

// Code

#include "src/Linear/List/SinglyList.tpp"

#endif
---------------------------------

c_api/include/
└── gdsl_list.h

#ifndef GDSL_LIST_H
#define GDSL_LIST_H

#include "gdsl_config.h"

#ifdef __cplusplus
extern "C" {
#endif

// Code

#ifdef __cplusplus
}
#endif

#endif
---------------------------------

c_api/src/
└── gdsl_list.cpp
#include "gdsl_list.h"
#include "Linear/List/SinglyList.hpp"

#include <new>

// Code
__________________________________________________________

include/
└── Linear/
    └── Stack.hpp

#ifndef STACK_LIFO
#define STACK_LIFO

#include <iostream>
#include "Linear/List/SinglyList.hpp"

// Code

#include "src/Linear/Stack.tpp"

#endif
---------------------------------

c_api/include/
└── gdsl_stack.h

#ifndef GDSL_STACK_H
#define GDSL_STACK_H

#include "gdsl_config.h"

#ifdef __cplusplus
extern "C" {
#endif

// Code

#ifdef __cplusplus
}
#endif

#endif
---------------------------------

c_api/src/
└── gdsl_stack.cpp

#include "gdsl_stack.h"
#include "Linear/Stack.hpp"

// Code
__________________________________________________________

include/
└── Linear/
    └── Queue/
        └── SimpleQueue.hpp

#ifndef SIMPLE_QUEUE_FIFO
#define SIMPLE_QUEUE_FIFO

#include <iostream>
#include "Linear/List/SinglyList.hpp"

// Code

#include "src/Linear/Queue/SimpleQueue.tpp"

#endif
---------------------------------

c_api/include/
└── gdsl_queue.h

#ifndef GDSL_QUEUE_H
#define GDSL_QUEUE_H

#include "gdsl_config.h"

#ifdef __cplusplus
extern "C" {
#endif

// Code

#ifdef __cplusplus
}
#endif

#endif
---------------------------------

c_api/src/
└── gdsl_queue.cpp

#include "gdsl_queue.h"
#include "Linear/Queue/SimpleQueue.hpp"

// Code
__________________________________________________________

include/
└── NonLinear/
    └── Tree/
        └── BalancedTree.hpp

#ifndef BALANCED_TREE
#define BALANCED_TREE

#include <iostream>

#include "Linear/Stack.hpp"
#include "Linear/Queue/SimpleQueue.hpp"

// Code

#include "src/NonLinear/Tree/BalancedTree.tpp"

#endif
---------------------------------

c_api/include/
└── gdsl_btree.h

#ifndef GDSL_BTREE_H
#define GDSL_BTREE_H

#include "gdsl_config.h"

#ifdef __cplusplus
extern "C" {
#endif

// Code

#ifdef __cplusplus
}
#endif

#endif
---------------------------------

c_api/src/
└── gdsl_btree.cpp

#include "gdsl_btree.h"
#include "NonLinear/Tree/BalancedTree.hpp"

// Code
__________________________________________________________

include/
└── NonLinear/
    └── Tree/
        └── BinarySearchTree.hpp

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>

#include "Linear/Stack.hpp"
#include "Linear/Queue/SimpleQueue.hpp"
#include "NonLinear/Tree/Mode.hpp"

// Code

#include "src/NonLinear/Tree/BinarySearchTree.tpp"

#endif
---------------------------------

c_api/include/
└── gdsl_bst.h

#ifndef GDSL_BST_H
#define GDSL_BST_H

#include "gdsl_config.h"
#include "gdsl_mode.h"

#ifdef __cplusplus
extern "C" {
#endif

// Code

#ifdef __cplusplus
}
#endif

#endif
---------------------------------

c_api/src/
└── gdsl_bst.cpp

#include "gdsl_bst.h"
#include "NonLinear/Tree/BinarySearchTree.hpp"

// Code
__________________________________________________________

include/
└── NonLinear/
    └── Tree/
        └── AdelsonVelskyLandisTree.hpp

#ifndef ADELSON_VELSKY_LANDIS_TREE
#define ADELSON_VELSKY_LANDIS_TREE

#include <iostream>

#include "Linear/Stack.hpp"
#include "Linear/Queue/SimpleQueue.hpp"
#include "NonLinear/Tree/Mode.hpp"

// Code

#include "src/NonLinear/Tree/AdelsonVelskyLandisTree.tpp"

#endif
---------------------------------

c_api/include/
└── gdsl_avl.h

#ifndef GDSL_AVL_H
#define GDSL_AVL_H

#include "gdsl_config.h"
#include "gdsl_mode.h"

#ifdef __cplusplus
extern "C" {
#endif

// Code

#ifdef __cplusplus
}
#endif

#endif
---------------------------------

c_api/src/
└── gdsl_avl.cpp

#include "gdsl_avl.h"
#include "NonLinear/Tree/AdelsonVelskyLandisTree.hpp"

// Code

