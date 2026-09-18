#ifndef TYPES_HPP
#define TYPES_HPP


enum class MODE : char {
    DFS='a', BFS='b', DFS_RL='c', BFS_RL='d',
    IN='e', R_IN='f', PRE='g', POST='h',
    DEF='i'
};

enum { L, R, P };

enum class NTYPE : char {
    LF='j', RT='k', IM='n'
};

enum class PRINT : char {
    M_ADD='p', I_ADD='q', IN_V='r', R_IN_V='s'
};


#endif