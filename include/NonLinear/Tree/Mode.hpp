#ifndef MODE_HPP
#define MODE_HPP

enum class MODE : char {
    DFS='w', BFS='x', DFS_LR='y', BFS_RL='z',
    IN='a', PRE='b', POST='c',
    DEF='d'
};

enum { L, R, P };

#endif