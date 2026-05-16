import ctypes
from ctypes import *

# load dll
gdsl = ctypes.CDLL("./bin/gdsl.dll")

# function declarations
gdsl.gdsl_btree_create.argtypes = [c_ushort]
gdsl.gdsl_btree_create.restype = c_void_p

gdsl.gdsl_btree_insert.argtypes = [c_void_p, c_int]
gdsl.gdsl_btree_insert.restype = c_int

gdsl.gdsl_btree_search.argtypes = [c_void_p, c_int]
gdsl.gdsl_btree_search.restype = c_int

gdsl.gdsl_btree_size.argtypes = [c_void_p]
gdsl.gdsl_btree_size.restype = c_long

gdsl.gdsl_btree_view_bfs.argtypes = [c_void_p, c_int]

gdsl.gdsl_btree_destroy.argtypes = [c_void_p]

# create tree
tree = gdsl.gdsl_btree_create(3)

# insert values
gdsl.gdsl_btree_insert(tree, 50)
gdsl.gdsl_btree_insert(tree, 30)
gdsl.gdsl_btree_insert(tree, 70)
gdsl.gdsl_btree_insert(tree, 10)
gdsl.gdsl_btree_insert(tree, 40)

# search
print("Search 40 =", gdsl.gdsl_btree_search(tree, 40))
print("Search 99 =", gdsl.gdsl_btree_search(tree, 99))

# size
print("Size =", gdsl.gdsl_btree_size(tree))

# view
print("\nBFS Traversal:")
gdsl.gdsl_btree_view_bfs(tree, 0)

# destroy
gdsl.gdsl_btree_destroy(tree)