#ifndef GDSL_MODE_H
#define GDSL_MODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    GDSL_DFS='w',
    GDSL_BFS='x',
    GDSL_DFS_LR='y',
    GDSL_BFS_RL='z',
    GDSL_IN='a',
    GDSL_PRE='b',
    GDSL_POST='c',
    GDSL_DEF='d'
} GDSL_MODE;


typedef enum {
    GDSL_LEFT,
    GDSL_RIGHT,
    GDSL_PARENT
} GDSL_LINK;


#ifdef __cplusplus
}
#endif

#endif