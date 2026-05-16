#include <stdio.h>
#include "gdsl_btree.h"

int main() {
    // create B-tree (order = 3 for example)
    GDSL_BTREE* tree = gdsl_btree_create(3);

    if (!tree) {
        printf("Failed to create B-tree\n");
        return 1;
    }

    // insert values
    gdsl_btree_insert(tree, 50);
    gdsl_btree_insert(tree, 30);
    gdsl_btree_insert(tree, 70);
    gdsl_btree_insert(tree, 10);
    gdsl_btree_insert(tree, 40);
    gdsl_btree_insert(tree, 60);
    gdsl_btree_insert(tree, 80);

    // search test
    printf("Search 40: %d\n", gdsl_btree_search(tree, 40));
    printf("Search 99: %d\n", gdsl_btree_search(tree, 99));

    // size
    printf("Size: %ld\n", gdsl_btree_size(tree));

    // traversal
    printf("\nBFS view:\n");
    gdsl_btree_view_bfs(tree, 0);

    printf("\nDFS view:\n");
    gdsl_btree_view_dfs(tree, 0);

    // remove test
    gdsl_btree_remove(tree, 40);
    printf("\nAfter removing 40:\n");
    gdsl_btree_view_bfs(tree, 0);

    // destroy
    gdsl_btree_destroy(tree);

    return 0;
}